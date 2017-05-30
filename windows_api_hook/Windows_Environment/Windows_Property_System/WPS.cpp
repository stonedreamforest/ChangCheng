#include "stdafx.h"
#include "WPS.h"





//Property Bag Functions:https://msdn.microsoft.com/en-us/library/windows/desktop/ee845049(v=vs.85).aspx
#include <Propsys.h>
#pragma comment(lib, "Propsys.lib")


HRESULT(WINAPI *Gb_PSPropertyBag_Delete)(_In_ IPropertyBag *propBag , _In_ LPCWSTR propName) = nullptr;
HRESULT(WINAPI *Gb_PSPropertyBag_ReadBOOL)(_In_ IPropertyBag *propBag , _In_ LPCWSTR propName , _Out_ BOOL *value) = nullptr;
HRESULT(WINAPI *Gb_PSPropertyBag_ReadBSTR)(_In_  IPropertyBag *propBag , _In_  LPCWSTR propName , _Out_ BSTR *value) = nullptr;
HRESULT(WINAPI *Gb_PSPropertyBag_ReadDWORD)(_In_  IPropertyBag *propBag , _In_  LPCWSTR propName , _Out_ DWORD *value) = nullptr;
HRESULT(WINAPI *Gb_PSPropertyBag_ReadGUID)(_In_ IPropertyBag *propBag , _In_ LPCWSTR propName , _Out_ GUID *value) = nullptr;
HRESULT(WINAPI *Gb_PSPropertyBag_ReadInt)(_In_ IPropertyBag *propBag , _In_ LPCWSTR propName , _Out_ int *value) = nullptr;
HRESULT(WINAPI *Gb_PSPropertyBag_ReadLONG)(_In_  IPropertyBag *propBag , _In_  LPCWSTR propName , _Out_ LONG *value) = nullptr;
HRESULT(WINAPI *Gb_PSPropertyBag_ReadPOINTL)(_In_  IPropertyBag *propBag ,_In_  LPCWSTR propName ,_Out_ POINTL *value) = nullptr;

WPS::WPS(){
	CC_HOOK_CREATE_ENABLE(PSPropertyBag_Delete , Mine_PSPropertyBag_Delete , Gb_PSPropertyBag_Delete);
	CC_HOOK_CREATE_ENABLE(PSPropertyBag_ReadBOOL , Mine_PSPropertyBag_ReadBOOL , Gb_PSPropertyBag_ReadBOOL);
	CC_HOOK_CREATE_ENABLE(PSPropertyBag_ReadBSTR , Mine_PSPropertyBag_ReadBSTR , Gb_PSPropertyBag_ReadBSTR);
	CC_HOOK_CREATE_ENABLE(PSPropertyBag_ReadDWORD , Mine_PSPropertyBag_ReadDWORD , Gb_PSPropertyBag_ReadDWORD);
	CC_HOOK_CREATE_ENABLE(PSPropertyBag_ReadGUID , Mine_PSPropertyBag_ReadGUID , Gb_PSPropertyBag_ReadGUID);
	CC_HOOK_CREATE_ENABLE(PSPropertyBag_ReadInt , Mine_PSPropertyBag_ReadInt , Gb_PSPropertyBag_ReadInt);
	CC_HOOK_CREATE_ENABLE(PSPropertyBag_ReadLONG , Mine_PSPropertyBag_ReadLONG , Gb_PSPropertyBag_ReadLONG);
	CC_HOOK_CREATE_ENABLE(PSPropertyBag_ReadPOINTL , Mine_PSPropertyBag_ReadPOINTL , Gb_PSPropertyBag_ReadPOINTL);
}


WPS::~WPS(){
	CC_HOOK_DISABLE(PSPropertyBag_Delete);
	CC_HOOK_DISABLE(PSPropertyBag_ReadBOOL);
	CC_HOOK_DISABLE(PSPropertyBag_ReadBSTR);
	CC_HOOK_DISABLE(PSPropertyBag_ReadDWORD);
	CC_HOOK_DISABLE(PSPropertyBag_ReadGUID);
	CC_HOOK_DISABLE(PSPropertyBag_ReadInt);
	CC_HOOK_DISABLE(PSPropertyBag_ReadLONG);
	CC_HOOK_DISABLE(PSPropertyBag_ReadPOINTL);
}


HRESULT WINAPI Mine_PSPropertyBag_Delete(_In_ IPropertyBag *propBag , _In_ LPCWSTR propName){
	__try{
		return Gb_PSPropertyBag_Delete(propBag , propName);
	}
	__finally{
		CC_2_FUN_CALL_SUCCESS("Mine_PSPropertyBag_Delete" , (CC_UINT)propBag , CC_CPSIN(WCHAR2UTF8(propName)));
	}
}

HRESULT WINAPI Mine_PSPropertyBag_ReadBOOL(_In_ IPropertyBag *propBag , _In_ LPCWSTR propName , _Out_ BOOL *value){
	__try{
		return Gb_PSPropertyBag_ReadBOOL(propBag , propName , value);
	}
	__finally{
		CC_3_FUN_CALL_SUCCESS("Mine_PSPropertyBag_ReadBOOL" , (CC_UINT)propBag , CC_CPSIN(WCHAR2UTF8(propName)) , CC_UINT(value));
	}
}

HRESULT WINAPI Mine_PSPropertyBag_ReadBSTR(_In_ IPropertyBag *propBag , _In_ LPCWSTR propName , _Out_ BSTR *value){
	__try{
		return Gb_PSPropertyBag_ReadBSTR(propBag , propName , value);
	}
	__finally{
		CC_3_FUN_CALL_SUCCESS("Mine_PSPropertyBag_ReadBSTR" , (CC_UINT)propBag , CC_CPSIN(WCHAR2UTF8(propName)) , CC_CPSIN(WCHAR2UTF8(value)));
	}
}

HRESULT WINAPI Mine_PSPropertyBag_ReadDWORD(_In_ IPropertyBag *propBag , _In_ LPCWSTR propName , _Out_ DWORD *value){
	__try{
		return Gb_PSPropertyBag_ReadDWORD(propBag , propName , value);
	}
	__finally{
		CC_3_FUN_CALL_SUCCESS("Mine_PSPropertyBag_ReadDWORD" , (CC_UINT)propBag , CC_CPSIN(WCHAR2UTF8(propName)) , CC_UINT(value));

	}
}

HRESULT WINAPI Mine_PSPropertyBag_ReadGUID(_In_ IPropertyBag *propBag , _In_ LPCWSTR propName , _Out_ GUID *value){
	__try{
		return Gb_PSPropertyBag_ReadGUID(propBag , propName , value);
	}
	__finally{
		CC_3_FUN_CALL_SUCCESS("Mine_PSPropertyBag_ReadGUID" , (CC_UINT)propBag , CC_CPSIN(WCHAR2UTF8(propName)) , CC_UINT(value));
	}
}

HRESULT WINAPI Mine_PSPropertyBag_ReadInt(_In_ IPropertyBag *propBag , _In_ LPCWSTR propName , _Out_ int *value){
	__try{
		return PSPropertyBag_ReadInt(propBag , propName , value);
	}
	__finally{
		CC_3_FUN_CALL_SUCCESS("Mine_PSPropertyBag_ReadInt" , (CC_UINT)propBag , CC_CPSIN(WCHAR2UTF8(propName)) , CC_UINT(value));
	}
}

HRESULT WINAPI Mine_PSPropertyBag_ReadLONG(_In_ IPropertyBag *propBag , _In_ LPCWSTR propName , _Out_ LONG *value){
	__try{
		return Gb_PSPropertyBag_ReadLONG(propBag , propName , value);
	}
	__finally{
		CC_3_FUN_CALL_SUCCESS("Mine_PSPropertyBag_ReadLONG" , (CC_UINT)propBag , CC_CPSIN(WCHAR2UTF8(propName)) , CC_UINT(value));
	}
}

HRESULT WINAPI Mine_PSPropertyBag_ReadPOINTL(_In_ IPropertyBag *propBag , _In_ LPCWSTR propName , _Out_ POINTL *value){
	__try{
		return Gb_PSPropertyBag_ReadPOINTL(propBag , propName , value);
	}
	__finally{
		CC_3_FUN_CALL_SUCCESS("Mine_PSPropertyBag_ReadLONG" , (CC_UINT)propBag , CC_CPSIN(WCHAR2UTF8(propName)) , CC_UINT(value));
	}
}
