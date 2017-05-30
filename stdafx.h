// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO:  在此处引用程序需要的其他头文件
#include "hook_lib/MinHook.h"
#include "spdlog/spdlog.h"
#include <iostream>
#include <memory>


#include "misc/misc.h"

#include "minhook_init/MinHook_Init.h"


namespace spd = spdlog;

//lib
#if defined _M_X64
#ifdef _DEBUG
#pragma comment(lib, "hook_lib/libMinHook-x64-v140-mdd.lib")
#else
#pragma comment(lib, "hook_lib/libMinHook-x64-v140-md.lib")
#endif

#elif defined _M_IX86
#ifdef _DEBUG
#pragma comment(lib, "hook_lib/libMinHook-x86-v140-mdd.lib")
#else
#pragma comment(lib, "hook_lib/libMinHook-x86-v140-md.lib")
#endif
#endif



