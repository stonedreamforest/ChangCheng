#include "stdafx.h"
#include "MinHook_Init.h"


MinHook_Init::MinHook_Init(){
	//确保有目录logs
	CreateDirectory(L"d:\\logs" , NULL);
	myhook_logger = spd::basic_logger_mt("myhook_logger for changcheng" , "d:/logs/hook_logger");
	//初始化异常处理
	log_err_handler();
	CC_HOOKLOG_START;
	// Initialize MinHook.
	if(MH_Initialize() != MH_OK){
		CC_0_FUN_CALL_FAILED("MH_Initialize");
	}

	
}


MinHook_Init::~MinHook_Init(){
	// Uninitialize MinHook.
	if(MH_Uninitialize() != MH_OK){
		CC_0_FUN_CALL_FAILED("MH_Uninitialize");
	}
	CC_HOOKLOG_STOP;
	//释放并关闭所有记录器
	spd::drop_all();
}
