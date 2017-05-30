#pragma once
class ARR{
public:
	ARR();
	~ARR();
};



VOID WINAPI Mine_ApplicationRecoveryFinished(_In_ BOOL bSuccess);
HRESULT WINAPI Mine_ApplicationRecoveryInProgress(_Out_ PBOOL pbCanceled);
HRESULT WINAPI Mine_GetApplicationRecoveryCallback(_In_  HANDLE hProcess ,
												   _Out_ APPLICATION_RECOVERY_CALLBACK *pRecoveryCallback ,
												   _Out_ PVOID *ppvParameter ,
												   _Out_ PDWORD pdwPingInterval ,
												   _Out_ PDWORD  pdwFlags);
HRESULT WINAPI Mine_GetApplicationRestartSettings(_In_ HANDLE hProcess , _Out_opt_ PWSTR  pwzCommandline , _Inout_   PDWORD pcchSize , _Out_opt_ PDWORD pdwFlags);
HRESULT WINAPI Mine_RegisterApplicationRecoveryCallback(_In_ APPLICATION_RECOVERY_CALLBACK pRecoveryCallback , _In_opt_ PVOID pvParameter , _In_ DWORD dwPingInterval , _In_ DWORD dwFlags);
HRESULT WINAPI Mine_RegisterApplicationRestart(_In_opt_ PCWSTR pwzCommandline , _In_ DWORD  dwFlags);
HRESULT WINAPI Mine_UnregisterApplicationRecoveryCallback(void);
HRESULT WINAPI Mine_UnregisterApplicationRestart(void);