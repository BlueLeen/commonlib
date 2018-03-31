/*********************************************************
 * Copyright (C) 2015 All rights reserved.
 * Author        : Ewen Dong
 * Email         : ewen.dong@cloudminds.com
 * Filename      : CommonDefine.h
 * Last modified : 2015-08-25
 * Description   : 
 *********************************************************/
#ifndef _COMMONDEFINE_H_
#define _COMMONDEFINE_H_

#include <stdint.h>     // define int8_t ...
#include <string>

enum ERESULT {
    E_OK = 0,
    E_FAIL = -1,
    E_PENDING_READ = -2,
    E_CONNECTION = -3,
    E_TIMEOUT = -4,
    E_PARTIAL = -5,
};

enum EDIRECTION {
    DIR_STOP = -1,
    DIR_FORWARD = 0,
    DIR_BACKWARD = 180,
    DIR_LEFT = 90,
    DIR_RIGHT = -90,
    DIR_FORWARDLEFT = 45,
    DIR_FORWARDRIGHT = -45,
    DIR_BACKWARDRIGHT = -135,
    DIR_BACKWARDLEFT = 135
};

typedef struct tag_Action {
    double dTurnAngle;
    double dDistance;
    double dSpeed;
} SAction;

// Const define
const uint16_t DEFAULT_VELOCITY = 127;
const std::string  ROBOT_LISTEN_ADDR = "192.168.4.1";
//const std::string  ROBOT_LISTEN_ADDR = "127.0.0.1";
const std::string  SDK_LISTEN_ADDR = "0.0.0.0";
const int ROBOT_LISTEN_PORT = 12477;
const int SDK_LISTEN_PORT = 12477;

#endif
