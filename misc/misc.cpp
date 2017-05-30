#include "stdafx.h"
#include "misc.h"




std::shared_ptr<spdlog::logger> myhook_logger = NULL;
char *utf8 = nullptr;

char * wchar2utf8(const wchar_t *str){
	if(str == nullptr){
		return "nullptr";
	}
	int len = WideCharToMultiByte(CP_ACP , 0 , str , wcslen(str) , NULL , 0 , NULL , NULL);
	if(utf8 != nullptr){
		delete utf8;
	}
	utf8 = new char[len + 1];
	WideCharToMultiByte(CP_ACP , 0 , str , wcslen(str) , utf8 , len , NULL , NULL);
	utf8[len] = '\0';
	return utf8;
}

void log_err_handler(){
	spd::set_error_handler([](const std::string& msg){
		myhook_logger->info("已捕获的异常：{}" , msg);
	});
}
