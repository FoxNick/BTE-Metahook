#pragma once

struct hook_s
{
	void *pOldFuncAddr;
	void *pNewFuncAddr;
	void *pClass;
	int iTableIndex;
	int iFuncIndex;
	HMODULE hModule;
	const char *pszModuleName;
	const char *pszFuncName;
	struct hook_s *pNext;
	void *pInfo;
};

class IFileSystem;

extern HINSTANCE g_hInstance, g_hThisModule, g_hEngineModule;
extern DWORD g_dwEngineBase, g_dwEngineSize;
extern DWORD g_dwEngineBuildnum;
extern int g_iVideoMode;
extern bool g_bIsNewEngine;
extern int g_iVideoWidth, g_iVideoHeight;
extern int g_iBPP;
extern bool g_bWindowed;
extern bool g_bIsUseSteam;
extern bool g_bIsDebuggerPresent;
extern HWND g_hWnd;
extern IFileSystem *&g_pFileSystem;

extern struct cvar_s *developer;