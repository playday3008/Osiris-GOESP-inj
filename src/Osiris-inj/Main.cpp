#include <Windows.h>
#include <TlHelp32.h>
// Junk code to make injector undetected
#include "JunkCode.h"

#define DLL_NAME "Osiris.dll"

// And you need:
// 1. change all bytes(0x00, 0x01, 0x03....) in define "JUNKS" to random bytes
// 2. change size this block by adding new bytes
#define JUNKS \
__asm _emit 0x89 \
__asm _emit 0x06 \
__asm _emit 0x80 \
__asm _emit 0x97 \
__asm _emit 0x12 \
__asm _emit 0x98 \
__asm _emit 0x67 \
__asm _emit 0x64 \
__asm _emit 0x74 \
__asm _emit 0x22 \
__asm _emit 0x96 \
__asm _emit 0x95 \
__asm _emit 0x35 \
__asm _emit 0x60 \
__asm _emit 0x53 \
__asm _emit 0x64 \
__asm _emit 0x77 \
__asm _emit 0x52 \
__asm _emit 0x17 \
__asm _emit 0x12 \
__asm _emit 0x22 \
__asm _emit 0x49 \
__asm _emit 0x90 \
__asm _emit 0x67 \
__asm _emit 0x04 \
__asm _emit 0x26 \
__asm _emit 0x59 \
__asm _emit 0x33 \
__asm _emit 0x10 \
__asm _emit 0x98 \
__asm _emit 0x64 \
__asm _emit 0x96 \
__asm _emit 0x74 \
__asm _emit 0x64 \
__asm _emit 0x55 \
__asm _emit 0x35 \
__asm _emit 0x48 \
__asm _emit 0x47 \
__asm _emit 0x44 \
__asm _emit 0x89 \
__asm _emit 0x97 \
__asm _emit 0x78 \
__asm _emit 0x56 \
__asm _emit 0x50 \
__asm _emit 0x87 \
__asm _emit 0x69 \
__asm _emit 0x88 \
__asm _emit 0x79 \
__asm _emit 0x89 \
__asm _emit 0x23 \
__asm _emit 0x44 \
__asm _emit 0x16 \
__asm _emit 0x18 \
__asm _emit 0x03 \
__asm _emit 0x50 \
__asm _emit 0x76 \
__asm _emit 0x75 \
__asm _emit 0x53 \
__asm _emit 0x73 \
__asm _emit 0x35 \
__asm _emit 0x48 \
__asm _emit 0x78 \
__asm _emit 0x80 \
__asm _emit 0x67 \
__asm _emit 0x30 \
__asm _emit 0x02 \
__asm _emit 0x21 \
__asm _emit 0x07 \
__asm _emit 0x30 \
__asm _emit 0x37 \
__asm _emit 0x82 \
__asm _emit 0x59 \
__asm _emit 0x13 \
__asm _emit 0x88 \
__asm _emit 0x65 \
__asm _emit 0x22 \
__asm _emit 0x37 \
__asm _emit 0x14 \
__asm _emit 0x46 \
__asm _emit 0x72 \
__asm _emit 0x23 \
__asm _emit 0x63 \
__asm _emit 0x91 \
__asm _emit 0x83 \
__asm _emit 0x37 \
__asm _emit 0x51 \
__asm _emit 0x71 \
__asm _emit 0x08 \
__asm _emit 0x30 \
__asm _emit 0x37 \
__asm _emit 0x59 \
__asm _emit 0x22 \
__asm _emit 0x72 \
__asm _emit 0x74 \
__asm _emit 0x06 \
__asm _emit 0x99 \
__asm _emit 0x21 \
__asm _emit 0x85 \
__asm _emit 0x42 \
__asm _emit 0x47 \


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
	pBut();
	yAD();
	mop();
	LlKk();
	AfUh();
	HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, dwProcess);
	
	_JUNK_BLOCK(jmp_label16)
	xtXP();
	BNxW();
	Wchh();
	Xze();
	DbL();
	LPVOID allocatedMem = VirtualAllocEx(hProcess, NULL, sizeof(myDLL), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	
	_JUNK_BLOCK(jmp_label17)
	dmfc();
	tXm();
	dgm();
	qmY();
	MYa();
	WriteProcessMemory(hProcess, allocatedMem, myDLL, sizeof(myDLL), NULL);
	
	_JUNK_BLOCK(jmp_label18)
	gHo();
	iHj();
	TNsp();
	DHaz();
	SieU();
	CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibrary, allocatedMem, 0, 0);
	
	_JUNK_BLOCK(jmp_label19)
	CloseHandle(hProcess);
	
	_JUNK_BLOCK(jmp_label20)
	return 0;
}