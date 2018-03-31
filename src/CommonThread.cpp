/*********************************************************
 * Copyright (C) 2015 All rights reserved.
 * Author        : Ewen Dong
 * Email         : ewen.dong@cloudminds.com
 * Filename      : CommonThread.cpp
 * Last modified : 2015-08-25
 * Description   :
 *********************************************************/
#include "CommonThread.h"

CCommonThread::CCommonThread() {
    m_thread_id = 0;
    m_bRunning = false;
}

CCommonThread::~CCommonThread() {
    while(m_bRunning)
        m_bRunning = false;
    pthread_join(m_thread_id, NULL);
}

void* CCommonThread::ThreadRoutine(void* arg) {
    CCommonThread* pThread = (CCommonThread*) arg;
    pThread->Run();
    return NULL;
}

int CCommonThread::StartThread() {
    if (m_bRunning) {
        return 0;
    }
    m_bRunning = true;
    return pthread_create(&m_thread_id, NULL, ThreadRoutine, this);
}
