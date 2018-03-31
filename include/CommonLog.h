/*********************************************************
 * Copyright (C) 2015 All rights reserved.
 * Author        : Ewen Dong
 * Email         : ewen.dong@cloudminds.com
 * Filename      : CommonLog.h
 * Last modified : 2015-08-25
 * Description   : 
 *********************************************************/

#ifndef _COMMONLOG_H_
#define _COMMONLOG_H_

#include <log4cplus/logger.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/layout.h>
#include <log4cplus/loggingmacros.h>

using namespace log4cplus;
using namespace log4cplus::helpers;

class CCommonLog {
public:
    bool OpenLogConfig(const char* sFileName, const char* sLogerName);
    bool DefaultConfig(const char* sLogerName);
    static CCommonLog& GetInstance();
    Logger& GetLogger();
private:
    CCommonLog();
    virtual ~CCommonLog();
    Logger m_Logger;
    CCommonLog* m_pLog;
};

#define LOG_TRACE(p) LOG4CPLUS_TRACE(CCommonLog::GetInstance().GetLogger(), p)
#define LOG_DBG(p)   LOG4CPLUS_DEBUG(CCommonLog::GetInstance().GetLogger(), p)
#define LOG_INFO(p)  LOG4CPLUS_INFO(CCommonLog::GetInstance().GetLogger(), p)
#define LOG_WARN(p)  LOG4CPLUS_WARN(CCommonLog::GetInstance().GetLogger(), p)
#define LOG_ERR(p)   LOG4CPLUS_ERROR(CCommonLog::GetInstance().GetLogger(), p)
#define LOG_FATAL(p) LOG4CPLUS_FATAL(CCommonLog::GetInstance().GetLogger(), p)
#endif
