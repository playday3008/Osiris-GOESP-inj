#include <Windows.h>
#include <TlHelp32.h>
// Junk code to make injector undetected
#include "JunkCode.h"
#include <iostream>

#define DLL_NAME "GOESP.dll"

// And you need:
// 1. change all bytes(0x00, 0x01, 0x03....) in define "JUNKS" to random bytes
// 2. change size this block by adding new bytes
#define JUNKS \
__asm _emit 0xD7 \
__asm _emit 0xF2 \
__asm _emit 0x33 \
__asm _emit 0xBC \
__asm _emit 0x21 \
__asm _emit 0xAF \
__asm _emit 0x54 \
__asm _emit 0x7E \
__asm _emit 0x68 \
__asm _emit 0x78 \
__asm _emit 0x5C \
__asm _emit 0xF0 \
__asm _emit 0xE4 \
__asm _emit 0x7E \
__asm _emit 0x69 \
__asm _emit 0xE4 \
__asm _emit 0x64 \
__asm _emit 0xE3 \
__asm _emit 0xBB \
__asm _emit 0x1E \
__asm _emit 0xDB \
__asm _emit 0x3F \
__asm _emit 0xE7 \
__asm _emit 0xAA \
__asm _emit 0x60 \
__asm _emit 0x4F \
__asm _emit 0xD6 \
__asm _emit 0x03 \
__asm _emit 0x8D \
__asm _emit 0x01 \
__asm _emit 0x84 \
__asm _emit 0xCC \
__asm _emit 0xF2 \
__asm _emit 0xB9 \
__asm _emit 0x41 \
__asm _emit 0xEB \
__asm _emit 0x9F \
__asm _emit 0xDF \
__asm _emit 0xB3 \
__asm _emit 0x69 \
__asm _emit 0x9D \
__asm _emit 0x3E \
__asm _emit 0x92 \
__asm _emit 0xC4 \
__asm _emit 0x86 \
__asm _emit 0xC7 \
__asm _emit 0x0A \
__asm _emit 0x8D \
__asm _emit 0xF8 \
__asm _emit 0xEC \
__asm _emit 0x6C \
__asm _emit 0xAA \
__asm _emit 0xF6 \
__asm _emit 0xF5 \
__asm _emit 0x2E \
__asm _emit 0x45 \
__asm _emit 0x97 \
__asm _emit 0xCF \
__asm _emit 0x27 \
__asm _emit 0xBB \
__asm _emit 0x65 \
__asm _emit 0x68 \
__asm _emit 0x84 \
__asm _emit 0xAE \
__asm _emit 0x0F \
__asm _emit 0xF4 \
__asm _emit 0x85 \
__asm _emit 0xE3 \
__asm _emit 0x68 \
__asm _emit 0x1B \
__asm _emit 0xC0 \
__asm _emit 0xB4 \
__asm _emit 0xC5 \
__asm _emit 0x88 \
__asm _emit 0x0D \
__asm _emit 0x50 \
__asm _emit 0x93 \
__asm _emit 0x3C \
__asm _emit 0x69 \
__asm _emit 0x86 \
__asm _emit 0x8F \
__asm _emit 0x79 \
__asm _emit 0x44 \
__asm _emit 0x1E \
__asm _emit 0x8C \
__asm _emit 0xC7 \
__asm _emit 0x12 \
__asm _emit 0x30 \
__asm _emit 0xC0 \
__asm _emit 0xE3 \
__asm _emit 0xBE \
__asm _emit 0x3B \
__asm _emit 0xB7 \
__asm _emit 0xDB \
__asm _emit 0x42 \
__asm _emit 0xCF \
__asm _emit 0x0F \
__asm _emit 0xD3 \
__asm _emit 0x00 \
__asm _emit 0xC3 \
__asm _emit 0xBA \
__asm _emit 0x73 \
__asm _emit 0x8C \
__asm _emit 0x50 \
__asm _emit 0xF0 \
__asm _emit 0x66 \
__asm _emit 0xBF \
__asm _emit 0xC4 \
__asm _emit 0x2A \
__asm _emit 0xBD \
__asm _emit 0x86 \
__asm _emit 0xD0 \
__asm _emit 0x08 \
__asm _emit 0xAA \
__asm _emit 0x51 \
__asm _emit 0x6A \
__asm _emit 0x8B \
__asm _emit 0xA6 \
__asm _emit 0xB5 \
__asm _emit 0x7C \
__asm _emit 0xDC \
__asm _emit 0x9B \
__asm _emit 0x7B \
__asm _emit 0x93 \
__asm _emit 0x73 \
__asm _emit 0x5A \
__asm _emit 0xAE \
__asm _emit 0x41 \
__asm _emit 0x01 \
__asm _emit 0x46 \
__asm _emit 0xA0 \
__asm _emit 0x7B \
__asm _emit 0x77 \
__asm _emit 0xE7 \
__asm _emit 0x06 \
__asm _emit 0x4C \
__asm _emit 0x0C \
__asm _emit 0xE9 \
__asm _emit 0x88 \
__asm _emit 0x10 \
__asm _emit 0x2B \
__asm _emit 0x4A \
__asm _emit 0x42 \
__asm _emit 0x8A \
__asm _emit 0x73 \
__asm _emit 0x50 \
__asm _emit 0x95 \
__asm _emit 0x7F \
__asm _emit 0x05 \
__asm _emit 0xA0 \
__asm _emit 0x06 \
__asm _emit 0x18 \
__asm _emit 0xF9 \
__asm _emit 0xD8 \


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

//   ____    ___                      ____                                                      
//  /\  _`\ /\_ \                    /\  _`\                                                    
//  \ \ \L\ \//\ \      __     __  __\ \ \/\ \     __     __  __                                
//   \ \ ,__/ \ \ \   /'__`\  /\ \/\ \\ \ \ \ \  /'__`\  /\ \/\ \                               
//    \ \ \/   \_\ \_/\ \L\.\_\ \ \_\ \\ \ \_\ \/\ \L\.\_\ \ \_\ \                              
//     \ \_\   /\____\ \__/.\_\\/`____ \\ \____/\ \__/.\_\\/`____ \                             
//      \/_/   \/____/\/__/\/_/ `/___/> \\/___/  \/__/\/_/ `/___/> \                            
//                                 /\___/                     /\___/                            
//   

int main()
{
	std::cout << "   ____       _      _         __   __________  ___________ ____ " << std::endl;
	Sleep(50);
	std::cout << "  / __ \\_____(_)____(_)____   / /  / ____/ __ \\/ ____/ ___// __ \\" << std::endl;
	Sleep(50);
	std::cout << " / / / / ___/ / ___/ / ___/  / /  / / __/ / / / __/  \\__ \\/ /_/ /" << std::endl;
	Sleep(50);
	std::cout << "/ /_/ (__  ) / /  / (__  )  / /  / /_/ / /_/ / /___ ___/ / ____/ " << std::endl;
	Sleep(50);
	std::cout << "\\____/____/_/_/  /_/____/  / /   \\____/\\____/_____//____/_/      " << std::endl;
	Sleep(50);
	std::cout << "    ____  __            __///                                    " << std::endl;
	Sleep(50);
	std::cout << "   / __ \\/ /___ ___  __/ __ \\____ ___  __                        " << std::endl;
	Sleep(50);
	std::cout << "  / /_/ / / __ `/ / / / / / / __ `/ / / /                        " << std::endl;
	Sleep(50);
	std::cout << " / ____/ / /_/ / /_/ / /_/ / /_/ / /_/ /                         " << std::endl;
	Sleep(50);
	std::cout << "/_/   /_/\\__,_/\\__, /_____/\\__,_/\\__, /                          " << std::endl;
	Sleep(50);
	std::cout << "              /____/            /____/                           " << std::endl << std::endl;
	Sleep(2000);
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