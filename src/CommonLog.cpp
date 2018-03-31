/*********************************************************
 * Copyright (C) 2015 All rights reserved.
 * Author        : Ewen Dong
 * Email         : ewen.dong@cloudminds.com
 * Filename      : CommonLog.cpp
 * Last modified : 2015-08-25
 * Description   : 
 *********************************************************/
#include <iostream>

#include "log4cplus/loglevel.h"
#include "log4cplus/configurator.h"
#include "log4cplus/fileappender.h"
#include "log4cplus/layout.h"

#include "CommonLog.h"

using namespace std;

////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCommonLog::CCommonLog() {
}

CCommonLog::~CCommonLog() {
}

CCommonLog& CCommonLog::GetInstance() {
    static CCommonLog log;
    return log;
}

bool CCommonLog::OpenLogConfig(const char* sFileName, const char* sLogerName) {
    FILE *log = fopen(sFileName,"r");
    if(log != NULL) {
        try {
            PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT(sFileName));
//            m_Logger = Logger::getInstance(sLogerName);
            auto logger = Logger::getInstance(sLogerName);
            m_Logger = logger;
            m_pLog = this;
            fclose(log);
            return true;
        } catch(...) {
            cerr << "Error:log4cplus.properties format is wrong" << endl;
        }
    } else {
        cerr << "Load specified log4cplus.properties is not exist, specified path:" << sFileName << endl;
    }
    return false;
}

bool CCommonLog::DefaultConfig(const char* sLogerName) {
    BasicConfigurator config;  
    config.configure();  
    auto logger = Logger::getInstance(sLogerName);
    m_Logger = logger;
    m_pLog = this;
    return true;
}

Logger& CCommonLog::GetLogger() {
    return m_Logger;
}
