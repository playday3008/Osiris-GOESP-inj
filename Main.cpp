#include <Windows.h>
#include <TlHelp32.h>
// Junk code to make injector undetected
#include "JunkCode.h"

#define DLL_NAME "curium.dll"

// And you need:
// 1. change all bytes(0x00, 0x01, 0x03....) in define "JUNKS" to random bytes
// 2. change size this block by adding new bytes
#define JUNKS \
__asm _emit 0x99 \
__asm _emit 0x62 \
__asm _emit 0x97 \
__asm _emit 0x78 \
__asm _emit 0x43 \
__asm _emit 0x40 \
__asm _emit 0x44 \
__asm _emit 0x70 \
__asm _emit 0x57 \
__asm _emit 0x70 \
__asm _emit 0x77 \
__asm _emit 0x65 \
__asm _emit 0x44 \
__asm _emit 0x70 \
__asm _emit 0x27 \
__asm _emit 0x16 \
__asm _emit 0x10 \
__asm _emit 0x69 \
__asm _emit 0x13 \
__asm _emit 0x32 \
__asm _emit 0x52 \
__asm _emit 0x78 \
__asm _emit 0x37 \
__asm _emit 0x07 \


// Don't change this!
#define _JUNK_BLOCK(s) __asm jmp s JUNKS __asm s:


/////////////////////////////////////////////////////////////////////////////////////
//                                 INJECTOR CODE                                   //
/////////////////////////////////////////////////////////////////////////////////////

DWORD Process(char* ProcessName)
{
	_JUNK_BLOCK(jmp_label1)
	HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	
	_JUNK_BLOCK(jmp_label2)
	PROCESSENTRY32 ProcEntry;
	
	_JUNK_BLOCK(jmp_label3)
	ProcEntry.dwSize = sizeof(ProcEntry);
	
	_JUNK_BLOCK(jmp_label4)
	do
	{
		_JUNK_BLOCK(jmp_label5)
		if (!strcmp(ProcEntry.szExeFile, ProcessName))
		{
			_JUNK_BLOCK(jmp_label6)
			DWORD dwPID = ProcEntry.th32ProcessID;
			
			_JUNK_BLOCK(jmp_label7)
			CloseHandle(hPID);
			
			_JUNK_BLOCK(jmp_label8)
			return dwPID;
		}
		
		_JUNK_BLOCK(jmp_label9)
	}
	while (Process32Next(hPID, &ProcEntry));
	
	_JUNK_BLOCK(jmp_label10)
}

int main()
{
	_JUNK_BLOCK(jmp_label11)
	DWORD dwProcess;
	
	_JUNK_BLOCK(jmp_label12)
	char myDLL[MAX_PATH];
	
	_JUNK_BLOCK(jmp_label13)
	GetFullPathName(DLL_NAME, MAX_PATH, myDLL, 0);
	
	_JUNK_BLOCK(jmp_label4)
	dwProcess = Process("csgo.exe");
	
	_JUNK_BLOCK(jmp_label15)
	zPpw();
	JFM();
	ILa();
	LMT();
	njt();
	HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, dwProcess);
	
	_JUNK_BLOCK(jmp_label16)
	iJN();
	yGF();
	sgDK();
	WMqx();
	zFn();
	LPVOID allocatedMem = VirtualAllocEx(hProcess, NULL, sizeof(myDLL), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	
	_JUNK_BLOCK(jmp_label17)
	jksB();
	SRH();
	xIO();
	mgVE();
	iiL();
	WriteProcessMemory(hProcess, allocatedMem, myDLL, sizeof(myDLL), NULL);
	
	_JUNK_BLOCK(jmp_label18)
	dUD();
	ecS();
	Ifn();
	jCMS();
	XMFu();
	CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibrary, allocatedMem, 0, 0);
	
	_JUNK_BLOCK(jmp_label19)
	CloseHandle(hProcess);
	
	_JUNK_BLOCK(jmp_label20)
	return 0;
	_JUNK_BLOCK(jmp_label21)
}