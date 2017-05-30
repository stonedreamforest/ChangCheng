#pragma once
class WPS{
public:
	WPS();
	~WPS();
};





HRESULT WINAPI Mine_PSPropertyBag_Delete(_In_ IPropertyBag *propBag , _In_ LPCWSTR propName);
HRESULT WINAPI Mine_PSPropertyBag_ReadBOOL(_In_ IPropertyBag *propBag , _In_ LPCWSTR propName , _Out_ BOOL *value);
HRESULT WINAPI Mine_PSPropertyBag_ReadBSTR(_In_  IPropertyBag *propBag , _In_  LPCWSTR propName , _Out_ BSTR *value);
HRESULT WINAPI Mine_PSPropertyBag_ReadDWORD(_In_  IPropertyBag *propBag , _In_  LPCWSTR propName , _Out_ DWORD *value);
HRESULT WINAPI Mine_PSPropertyBag_ReadGUID(_In_  IPropertyBag *propBag ,_In_  LPCWSTR propName ,_Out_ GUID *value);
HRESULT WINAPI Mine_PSPropertyBag_ReadInt(_In_  IPropertyBag *propBag ,_In_  LPCWSTR propName ,_Out_ int *value);
HRESULT WINAPI Mine_PSPropertyBag_ReadLONG(_In_  IPropertyBag *propBag , _In_  LPCWSTR propName , _Out_ LONG *value);
HRESULT WINAPI Mine_PSPropertyBag_ReadPOINTL(_In_  IPropertyBag *propBag , _In_  LPCWSTR propName , _Out_ POINTL *value);
