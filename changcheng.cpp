// changcheng.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "windows_api_hook/Windows_Environment/Windows_Property_System/WPS.h"

#include <Propsys.h>
//#pragma comment(lib, "Propsys.lib")

int main()
{
	MinHook_Init mhi;
	WPS wps;
	PSPropertyBag_Delete(NULL , NULL);
    return 0;
}

