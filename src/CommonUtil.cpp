/*********************************************************
 * Copyright (C) 2015 All rights reserved.
 * Author        : Ewen Dong
 * Email         : ewen.dong@cloudminds.com
 * Filename      : CommonUtil.cpp
 * Last modified : 2015-08-25
 * Description   : 
 *********************************************************/

#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include "CommonUtil.h"

void CCommonUtil::SleepMs(int nSec, int nMS) {
    struct timespec tsp;
    tsp.tv_sec = nSec;
    tsp.tv_nsec = nMS * 1000000;  //nMS ms
    nanosleep(&tsp, NULL);
}

long CCommonUtil::GetCurrentTime() {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

int CCommonUtil::GetRandomNumber(int nMaxNumber) {
    return rand() % nMaxNumber;
}
