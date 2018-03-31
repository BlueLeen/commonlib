/*********************************************************
 * Copyright (C) 2015 All rights reserved.
 * Author        : Ewen Dong
 * Email         : ewen.dong@cloudminds.com
 * Filename      : CommonThread.h
 * Last modified : 2015-08-25
 * Description   :
 *********************************************************/

#ifndef _COMMONTHREAD_H_
#define _COMMONTHREAD_H_

#include <pthread.h>

class CCommonThread
{
public:
    CCommonThread();
    virtual ~CCommonThread();

    static void* ThreadRoutine(void* arg);
    virtual int StartThread(void);
    virtual void Run(void) = 0;

protected:
    pthread_t m_thread_id;
    bool      m_bRunning;
};

#endif
