#include "stdafx.h"
#include "ARR.h"



//ApplicationRecoveryFinished function£ºhttps://msdn.microsoft.com/en-us/library/windows/desktop/dd877200(v=vs.85).aspx


VOID(WINAPI *Gb_ApplicationRecoveryFinished)(_In_ BOOL bSuccess) = nullptr;
HRESULT(WINAPI *Gb_ApplicationRecoveryInProgress)(_Out_ PBOOL pbCanceled) = nullptr;
HRESULT(WINAPI *Gb_GetApplicationRecoveryCallback)(_In_  HANDLE hProcess ,
												   _Out_ APPLICATION_RECOVERY_CALLBACK *pRecoveryCallback ,
												   _Out_ PVOID *ppvParameter ,
												   _Out_ PDWORD pdwPingInterval ,
												   _Out_ PDWORD  pdwFlags) = nullptr;
HRESULT(WINAPI *Gb_GetApplicationRestartSettings)(_In_ HANDLE hProcess , _Out_opt_ PWSTR  pwzCommandline , _Inout_   PDWORD pcchSize , _Out_opt_ PDWORD pdwFlags) = nullptr;
HRESULT(WINAPI *Gb_RegisterApplicationRecoveryCallback)(_In_ APPLICATION_RECOVERY_CALLBACK pRecoveryCallback , _In_opt_ PVOID pvParameter , _In_ DWORD dwPingInterval , _In_ DWORD dwFlags) = nullptr;
HRESULT(WINAPI *Gb_RegisterApplicationRestart)(_In_opt_ PCWSTR pwzCommandline , _In_ DWORD  dwFlags) = nullptr;
HRESULT (WINAPI *Gb_UnregisterApplicationRecoveryCallback)(void) = nullptr;
HRESULT (WINAPI *Gb_UnregisterApplicationRestart)(void) = nullptr;





ARR::ARR(){
	CC_HOOK_CREATE_ENABLE(ApplicationRecoveryFinished , Mine_ApplicationRecoveryFinished , Gb_ApplicationRecoveryFinished);
	CC_HOOK_CREATE_ENABLE(ApplicationRecoveryInProgress , Mine_ApplicationRecoveryInProgress , Gb_ApplicationRecoveryInProgress);
	CC_HOOK_CREATE_ENABLE(GetApplicationRecoveryCallback , Mine_GetApplicationRecoveryCallback , Gb_GetApplicationRecoveryCallback);
	CC_HOOK_CREATE_ENABLE(GetApplicationRestartSettings , Mine_GetApplicationRestartSettings , Gb_GetApplicationRestartSettings);
	CC_HOOK_CREATE_ENABLE(RegisterApplicationRecoveryCallback , Mine_RegisterApplicationRecoveryCallback , Gb_RegisterApplicationRecoveryCallback);
	CC_HOOK_CREATE_ENABLE(RegisterApplicationRestart , Mine_RegisterApplicationRestart , Gb_RegisterApplicationRestart);
	CC_HOOK_CREATE_ENABLE(UnregisterApplicationRecoveryCallback , Mine_UnregisterApplicationRecoveryCallback , Gb_UnregisterApplicationRecoveryCallback);
	CC_HOOK_CREATE_ENABLE(UnregisterApplicationRestart , Mine_UnregisterApplicationRestart , Gb_UnregisterApplicationRestart);
}


ARR::~ARR(){
	CC_HOOK_DISABLE(ApplicationRecoveryFinished);
	CC_HOOK_DISABLE(ApplicationRecoveryInProgress);
	CC_HOOK_DISABLE(GetApplicationRecoveryCallback);
	CC_HOOK_DISABLE(GetApplicationRestartSettings);
	CC_HOOK_DISABLE(RegisterApplicationRecoveryCallback);
	CC_HOOK_DISABLE(RegisterApplicationRestart);
	CC_HOOK_DISABLE(UnregisterApplicationRecoveryCallback);
	CC_HOOK_DISABLE(UnregisterApplicationRestart);
}

VOID WINAPI Mine_ApplicationRecoveryFinished(_In_ BOOL bSuccess){
	__try{
		return Gb_ApplicationRecoveryFinished(bSuccess);
	}
	__finally{
		CC_1_FUN_CALL_SUCCESS("Mine_ApplicationRecoveryFinished" , (CC_UINT)bSuccess);
	}
}

HRESULT WINAPI Mine_ApplicationRecoveryInProgress(_Out_ PBOOL pbCanceled){
	__try{
		return Gb_ApplicationRecoveryInProgress(pbCanceled);
	}
	__finally{
		CC_1_FUN_CALL_SUCCESS("Mine_ApplicationRecoveryInProgress" , (CC_UINT)*pbCanceled);
	}
}

HRESULT WINAPI Mine_GetApplicationRecoveryCallback(_In_ HANDLE hProcess ,
												   _Out_ APPLICATION_RECOVERY_CALLBACK *pRecoveryCallback ,
												   _Out_ PVOID *ppvParameter ,
												   _Out_ PDWORD pdwPingInterval ,
												   _Out_ PDWORD pdwFlags){
	__try{
		return Gb_GetApplicationRecoveryCallback(hProcess , pRecoveryCallback , ppvParameter , pdwPingInterval , pdwFlags);
	}
	__finally{
		CC_5_FUN_CALL_SUCCESS("Mine_GetApplicationRecoveryCallback" , (CC_UINT)hProcess , (CC_UINT)pRecoveryCallback , (CC_UINT)ppvParameter , (CC_UINT)*pdwPingInterval , (CC_UINT)*pdwFlags);
	}
}

HRESULT WINAPI Mine_GetApplicationRestartSettings(_In_ HANDLE hProcess , _Out_opt_ PWSTR pwzCommandline , _Inout_ PDWORD pcchSize , _Out_opt_ PDWORD pdwFlags){
	__try{
		return Gb_GetApplicationRestartSettings(hProcess , pwzCommandline , pcchSize , pdwFlags);
	}
	__finally{
		CC_4_FUN_CALL_SUCCESS("Mine_GetApplicationRestartSettings" , (CC_UINT)hProcess , CC_CPSIN(WCHAR2UTF8(pwzCommandline)) , (CC_UINT)*pcchSize , (CC_UINT)*pdwFlags);
	}
}

HRESULT WINAPI Mine_RegisterApplicationRecoveryCallback(_In_ APPLICATION_RECOVERY_CALLBACK pRecoveryCallback , _In_opt_ PVOID pvParameter , _In_ DWORD dwPingInterval , _In_ DWORD dwFlags){
	__try{
		return Gb_RegisterApplicationRecoveryCallback(pRecoveryCallback , pvParameter , dwPingInterval , dwFlags);
	}
	__finally{
		CC_4_FUN_CALL_SUCCESS("Mine_RegisterApplicationRecoveryCallback" , (CC_UINT)pRecoveryCallback , (CC_UINT)pvParameter , dwPingInterval , dwFlags);
	}
}

HRESULT WINAPI Mine_RegisterApplicationRestart(_In_opt_ PCWSTR pwzCommandline , _In_ DWORD dwFlags){
	__try{
		return Gb_RegisterApplicationRestart(pwzCommandline , dwFlags);
	}
	__finally{
		CC_2_FUN_CALL_SUCCESS("Mine_RegisterApplicationRestart" , CC_CPSIN(WCHAR2UTF8(pwzCommandline)) , dwFlags);
	}
}

HRESULT WINAPI Mine_UnregisterApplicationRecoveryCallback(void){
	__try{
		return Gb_UnregisterApplicationRecoveryCallback();
	}
	__finally{
		CC_0_FUN_CALL_SUCCESS("Mine_UnregisterApplicationRecoveryCallback");
	}
}

HRESULT WINAPI Mine_UnregisterApplicationRestart(void){
	__try{
		return Gb_UnregisterApplicationRestart();
	}
	__finally{
		CC_0_FUN_CALL_SUCCESS("Mine_UnregisterApplicationRestart");
	}
}
