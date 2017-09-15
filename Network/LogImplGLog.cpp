#include "stdafx.h"
#include "Log.h"

#define GOOGLE_GLOG_DLL_DECL
#define GLOG_NO_ABBREVIATED_SEVERITIES

#include <glog/logging.h>

bool LogImplGlog::Initialize()
{
     google::InitGoogleLogging("title");
//     
//     FLAGS_log_dir = ".\\";
// 
//     LOG(INFO) << "test";

    return true;
}

bool LogImplGlog::Write(WCHAR * log_string)
{
    return true;
}
