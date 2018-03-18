#include <metahook.h>

#include <io.h>
#include <memory>

static HANDLE g_hChildStdoutRd;
static HANDLE g_hChildStdoutWr;

struct ThreadDeleter
{
	void operator()(HANDLE thread)
	{
		TerminateThread(thread, 0);
	}
	using pointer = HANDLE;
};

std::unique_ptr<HANDLE, ThreadDeleter> g_phThread;

DWORD WINAPI Console_Thread_Out(LPVOID lpThreadParameter)
{
	static CHAR chBuf[1024];
	DWORD dwRead;
	BOOL fSuccess;
	while (1)
	{
		// �ӹܵ�����һͷ�ػ�����
		fSuccess = ReadFile(g_hChildStdoutRd, chBuf, 1024, &dwRead, NULL);
		chBuf[dwRead] = '\0';
		gEngfuncs.Con_Printf("%s", chBuf);
	}
}

void Console_Init()
{
	// ����һ���ܵ��������ض����׼���
	if (!CreatePipe(&g_hChildStdoutRd, &g_hChildStdoutWr, NULL, 0))
	{
		return;
	}
	// ����׼����ض�������ܵ���
	auto hCrt = _open_osfhandle((long)g_hChildStdoutWr, 0x4000);
	auto hf = _fdopen(hCrt, "w");
	*stdout = *hf;
	setvbuf(stdout, NULL, _IONBF, 0);
	// ����һ���̣߳��ӹܵ�����һͷ�ػ�����
	auto &&hThread = CreateThread(NULL,
		1024,
		(LPTHREAD_START_ROUTINE)Console_Thread_Out,
		(LPVOID)NULL,
		0,
		NULL);
	g_phThread.reset(hThread);
}

void Console_Shutdown()
{
	//CloseHandle(g_hChildStdoutRd);
	//CloseHandle(g_hChildStdoutWr);
}