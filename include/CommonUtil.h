/*********************************************************
 * Copyright (C) 2015 All rights reserved.
 * Author        : Ewen Dong
 * Email         : ewen.dong@cloudminds.com
 * Filename      : CommonUtil.h
 * Last modified : 2015-08-25
 * Description   : 
 *********************************************************/

#ifndef _COMMONUTIL_H_
#define _COMMONUTIL_H_

class CCommonUtil {
public:
    static long GetCurrentTime();
    static void SleepMs(int nSec, int nMS);
    static int  GetRandomNumber(int nMaxNumber);
};

#endif
