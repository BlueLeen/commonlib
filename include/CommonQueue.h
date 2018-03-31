/*********************************************************
 * Copyright (C) 2015 All rights reserved.
 * Author        : Ewen Dong
 * Email         : ewen.dong@cloudminds.com
 * Filename      : CommonQueue.h
 * Last modified : 2015-08-25
 * Description   : 
 *********************************************************/

#ifndef _COMMONQUEUE_H_
#define _COMMONQUEUE_H_

#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>

template<typename T>
class CCommonQueue
{
public:
    CCommonQueue() {};
    //CCommonQueue(const CCommonQueue&);
    //CCommonQueue& operator=(const CCommonQueue&) = delete;//禁止赋值操作是为了简化 
    void Push(T new_value);
    bool TryPop(T& value);//尝试删除队首元素，若删除成功则通过value返回队首元素，并返回true;若队为空，则返回false 
    std::shared_ptr<T> TryPop();//若队非空shared_ptr返回并删除的队首元素;若队空，则返回的shared_ptr为NULL
    void WaitPop(T& value);//若队非空，通过value返回队首元素并删除，函数返回true;若队为空，则通过condition_variable等待有元素入队后再获取闭并删除队首元素
    std::shared_ptr<T> WaitPop();//和前面一样，只不过通过shared_ptr返回队首元素
    bool Empty() const;
    int Size() const;
private:
     mutable std::mutex m_Mutex; 
     std::queue<T> m_DataQueue;
     std::condition_variable m_DataCond;
};

template<typename T>
void CCommonQueue<T>::Push(T new_value) {
    std::lock_guard<std::mutex> lk(m_Mutex);
    m_DataQueue.push(new_value);
    m_DataCond.notify_one();
}

template<typename T>
void CCommonQueue<T>::WaitPop(T& value) {
    std::unique_lock<std::mutex> lk(m_Mutex);
    m_DataCond.wait(lk, [this]{return !m_DataQueue.empty();});
    value=m_DataQueue.front();
    m_DataQueue.pop();
}

template<typename T>
std::shared_ptr<T> CCommonQueue<T>::WaitPop() {
    std::unique_lock<std::mutex> lk(m_Mutex);
    m_DataCond.wait(lk,[this]{return !m_DataQueue.empty();});
    std::shared_ptr<T> res(std::make_shared<T>(m_DataQueue.front()));
    m_DataQueue.pop();
    return res;
}

template<typename T>
bool CCommonQueue<T>::TryPop(T& value) {
    std::lock_guard<std::mutex> lk(m_Mutex);
    if(m_DataQueue.empty())
        return false;
    value=m_DataQueue.front();
    m_DataQueue.pop();
    return true;
}

template<typename T>
std::shared_ptr<T> CCommonQueue<T>::TryPop() {
    std::lock_guard<std::mutex> lk(m_Mutex);
    if(m_DataQueue.empty())
        return std::shared_ptr<T>();
    std::shared_ptr<T> res(std::make_shared<T>(m_DataQueue.front()));
    m_DataQueue.pop();
    return res;
}

template<typename T>
bool CCommonQueue<T>::Empty() const {
    std::lock_guard<std::mutex> lk(m_Mutex);
    return m_DataQueue.empty();
}

template<typename T>
int CCommonQueue<T>::Size() const {
    return m_DataQueue.size();
}


#endif
