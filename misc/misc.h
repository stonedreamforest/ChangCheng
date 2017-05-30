#pragma once


extern std::shared_ptr<spdlog::logger> myhook_logger;

extern char *utf8;


char *wchar2utf8(const wchar_t *str);


void log_err_handler();
































#define WCHAR2UTF8(string) wchar2utf8((const wchar_t *)string)




#if defined _M_X64
#define CC_INT	long long 
#define CC_UINT	unsigned long long 
#elif defined _M_IX86
#define CC_INT	int 
#define CC_UINT	unsigned int 
#endif






#define CC_HOOK_CREATE_ENABLE(Real_Fun,Mine_Fun,Gb_Real_Fun)	if(MH_CreateHook(&Real_Fun , &Mine_Fun ,reinterpret_cast<LPVOID*>(&Gb_Real_Fun)) != MH_OK){	\
																	CC_3_FUN_CALL_FAILED("CC_MH_CREATEHOOK",CC_UINT(Real_Fun),CC_UINT(Mine_Fun),CC_UINT(Gb_Real_Fun));\
																}\
																if(MH_EnableHook(&Real_Fun) != MH_OK){\
																	CC_1_FUN_CALL_FAILED("MH_EnableHook",CC_UINT(Real_Fun));\
																}

#define CC_HOOK_DISABLE(Real_Fun)								if(MH_DisableHook(&Real_Fun) != MH_OK){	\
																	CC_1_FUN_CALL_FAILED("MH_DisableHook",CC_UINT(Real_Fun));	\
																}









#define CC_HOOKLOG_START																	myhook_logger->info("开始记录");
#define CC_HOOKLOG_STOP																		myhook_logger->info("停止记录");

#define CC_0_FUN_CALL_FAILED(FUN_NAME)														myhook_logger->info("函数[{}]->调用失败。",FUN_NAME)
#define CC_1_FUN_CALL_FAILED(FUN_NAME,arg1)													myhook_logger->info("函数[{}]->调用失败。参数[1]:{}:",FUN_NAME,arg1)
#define CC_2_FUN_CALL_FAILED(FUN_NAME,arg1,arg2)											myhook_logger->info("函数[{}]->调用失败。参数[1]:{}, 参数[2]:{}",FUN_NAME,arg1,arg2)
#define CC_3_FUN_CALL_FAILED(FUN_NAME,arg1,arg2,arg3)										myhook_logger->info("函数[{}]->调用失败。参数[1]:{}, 参数[2]:{}, 参数[3]:{}, ",FUN_NAME,arg1,arg2,arg3)
#define CC_4_FUN_CALL_FAILED(FUN_NAME,arg1,arg2,arg3,arg4)									myhook_logger->info("函数[{}]->调用失败。参数[1]:{}, 参数[2]:{}, 参数[3]:{}, 参数[4]:{}, ",FUN_NAME,arg1,arg2,arg3,arg4)
#define CC_5_FUN_CALL_FAILED(FUN_NAME,arg1,arg2,arg3,arg4,arg5)								myhook_logger->info("函数[{}]->调用失败。参数[1]:{}, 参数[2]:{}, 参数[3]:{}, 参数[4]:{}, 参数[5]:{}, ",FUN_NAME,arg1,arg2,arg3,arg4,arg5)
#define CC_6_FUN_CALL_FAILED(FUN_NAME,arg1,arg2,arg3,arg4,arg5,arg6)						myhook_logger->info("函数[{}]->调用失败。参数[1]:{}, 参数[2]:{}, 参数[3]:{}, 参数[4]:{}, 参数[5]:{}, 参数[6]:{}, ",FUN_NAME,arg1,arg2,arg3,arg4,arg5,arg6)
#define CC_7_FUN_CALL_FAILED(FUN_NAME,arg1,arg2,arg3,arg4,arg5,arg6,arg7)					myhook_logger->info("函数[{}]->调用失败。参数[1]:{}, 参数[2]:{}, 参数[3]:{}, 参数[4]:{}, 参数[5]:{}, 参数[6]:{}, 参数[7]:{}, ",FUN_NAME,arg1,arg2,arg3,arg4,arg5,arg6,arg7)
#define CC_8_FUN_CALL_FAILED(FUN_NAME,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8)				myhook_logger->info("函数[{}]->调用失败。参数[1]:{}, 参数[2]:{}, 参数[3]:{}, 参数[4]:{}, 参数[5]:{}, 参数[6]:{}, 参数[7]:{}, 参数[8]:{}, ",FUN_NAME,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8)
#define CC_9_FUN_CALL_FAILED(FUN_NAME,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9)			myhook_logger->info("函数[{}]->调用失败。参数[1]:{}, 参数[2]:{}, 参数[3]:{}, 参数[4]:{}, 参数[5]:{}, 参数[6]:{}, 参数[7]:{}, 参数[8]:{}, 参数[9]:{}, ",FUN_NAME,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9)
#define CC_10_FUN_CALL_FAILED(FUN_NAME,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10)	myhook_logger->info("函数[{}]->调用失败。参数[1]:{}, 参数[2]:{}, 参数[3]:{}, 参数[4]:{}, 参数[5]:{}, 参数[6]:{}, 参数[7]:{}, 参数[8]:{}, 参数[9]:{}, 参数[10]:{},",FUN_NAME,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10)

#define CC_0_FUN_CALL_SUCCESS(FUN_NAME)														myhook_logger->info("函数[{}]->调用成功。",FUN_NAME)
#define CC_1_FUN_CALL_SUCCESS(FUN_NAME,arg1)												myhook_logger->info("函数[{}]->调用成功。参数[1]:{}:",FUN_NAME,arg1)
#define CC_2_FUN_CALL_SUCCESS(FUN_NAME,arg1,arg2)											myhook_logger->info("函数[{}]->调用成功。参数[1]:{}, 参数[2]:{}",FUN_NAME,arg1,arg2)
#define CC_3_FUN_CALL_SUCCESS(FUN_NAME,arg1,arg2,arg3)										myhook_logger->info("函数[{}]->调用成功。参数[1]:{}, 参数[2]:{}, 参数[3]:{}, ",FUN_NAME,arg1,arg2,arg3)
#define CC_4_FUN_CALL_SUCCESS(FUN_NAME,arg1,arg2,arg3,arg4)									myhook_logger->info("函数[{}]->调用成功。参数[1]:{}, 参数[2]:{}, 参数[3]:{}, 参数[4]:{}, ",FUN_NAME,arg1,arg2,arg3,arg4)
#define CC_5_FUN_CALL_SUCCESS(FUN_NAME,arg1,arg2,arg3,arg4,arg5)							myhook_logger->info("函数[{}]->调用成功。参数[1]:{}, 参数[2]:{}, 参数[3]:{}, 参数[4]:{}, 参数[5]:{}, ",FUN_NAME,arg1,arg2,arg3,arg4,arg5)
#define CC_6_FUN_CALL_SUCCESS(FUN_NAME,arg1,arg2,arg3,arg4,arg5,arg6)						myhook_logger->info("函数[{}]->调用成功。参数[1]:{}, 参数[2]:{}, 参数[3]:{}, 参数[4]:{}, 参数[5]:{}, 参数[6]:{}, ",FUN_NAME,arg1,arg2,arg3,arg4,arg5,arg6)
#define CC_7_FUN_CALL_SUCCESS(FUN_NAME,arg1,arg2,arg3,arg4,arg5,arg6,arg7)					myhook_logger->info("函数[{}]->调用成功。参数[1]:{}, 参数[2]:{}, 参数[3]:{}, 参数[4]:{}, 参数[5]:{}, 参数[6]:{}, 参数[7]:{}, ",FUN_NAME,arg1,arg2,arg3,arg4,arg5,arg6,arg7)
#define CC_8_FUN_CALL_SUCCESS(FUN_NAME,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8)				myhook_logger->info("函数[{}]->调用成功。参数[1]:{}, 参数[2]:{}, 参数[3]:{}, 参数[4]:{}, 参数[5]:{}, 参数[6]:{}, 参数[7]:{}, 参数[8]:{}, ",FUN_NAME,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8)
#define CC_9_FUN_CALL_SUCCESS(FUN_NAME,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9)		myhook_logger->info("函数[{}]->调用成功。参数[1]:{}, 参数[2]:{}, 参数[3]:{}, 参数[4]:{}, 参数[5]:{}, 参数[6]:{}, 参数[7]:{}, 参数[8]:{}, 参数[9]:{}, ",FUN_NAME,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9)
#define CC_10_FUN_CALL_SUCCESS(FUN_NAME,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10)	myhook_logger->info("函数[{}]->调用成功。参数[1]:{}, 参数[2]:{}, 参数[3]:{}, 参数[4]:{}, 参数[5]:{}, 参数[6]:{}, 参数[7]:{}, 参数[8]:{}, 参数[9]:{}, 参数[10]:{},",FUN_NAME,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10)





#define CC_Check_PString_IsNullptr(PString)	PString == nullptr ? "nullptr" : PString
#define CC_CPSIN							CC_Check_PString_IsNullptr