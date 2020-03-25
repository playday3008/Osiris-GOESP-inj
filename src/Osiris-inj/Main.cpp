#include <Windows.h>
#include <TlHelp32.h>
// Junk code to make injector undetected
#include "JunkCode.h"
#include <iostream>

#define DLL_NAME "Osiris.dll"

// And you need:
// 1. change all bytes(0x00, 0x01, 0x03....) in define "JUNKS" to random bytes
// 2. change size this block by adding new bytes
#define JUNKS \
__asm _emit 0xF5 \
__asm _emit 0xE6 \
__asm _emit 0x2E \
__asm _emit 0xB5 \
__asm _emit 0x89 \
__asm _emit 0x91 \
__asm _emit 0x48 \
__asm _emit 0xE7 \
__asm _emit 0xCF \
__asm _emit 0x31 \
__asm _emit 0x82 \
__asm _emit 0x53 \
__asm _emit 0x80 \
__asm _emit 0xE3 \
__asm _emit 0xB1 \
__asm _emit 0x4C \
__asm _emit 0xDB \
__asm _emit 0xF5 \
__asm _emit 0x0B \
__asm _emit 0x1E \
__asm _emit 0xF3 \
__asm _emit 0x1A \
__asm _emit 0xFE \
__asm _emit 0x84 \
__asm _emit 0x7C \
__asm _emit 0x0B \
__asm _emit 0x2A \
__asm _emit 0xAF \
__asm _emit 0x21 \
__asm _emit 0xF1 \
__asm _emit 0x73 \
__asm _emit 0x96 \
__asm _emit 0x01 \
__asm _emit 0x3D \
__asm _emit 0x10 \
__asm _emit 0xE1 \
__asm _emit 0x6D \
__asm _emit 0x50 \
__asm _emit 0x6F \
__asm _emit 0x3D \
__asm _emit 0xCC \
__asm _emit 0x43 \
__asm _emit 0x2F \
__asm _emit 0x9B \
__asm _emit 0xF8 \
__asm _emit 0x00 \
__asm _emit 0x34 \
__asm _emit 0x41 \
__asm _emit 0x0E \
__asm _emit 0x07 \
__asm _emit 0xC6 \
__asm _emit 0xA7 \
__asm _emit 0x41 \
__asm _emit 0xEA \
__asm _emit 0x22 \
__asm _emit 0x7B \
__asm _emit 0x28 \
__asm _emit 0x61 \
__asm _emit 0x27 \
__asm _emit 0xCE \
__asm _emit 0x8B \
__asm _emit 0xA6 \
__asm _emit 0x9A \
__asm _emit 0xB4 \
__asm _emit 0x6A \
__asm _emit 0x0A \
__asm _emit 0x94 \
__asm _emit 0xD8 \
__asm _emit 0x17 \
__asm _emit 0x2F \
__asm _emit 0xBF \
__asm _emit 0xD6 \
__asm _emit 0x27 \
__asm _emit 0xDC \
__asm _emit 0x8C \
__asm _emit 0xAF \
__asm _emit 0x54 \
__asm _emit 0x3D \
__asm _emit 0xE0 \
__asm _emit 0x89 \
__asm _emit 0xAE \
__asm _emit 0xA0 \
__asm _emit 0x22 \
__asm _emit 0xFC \
__asm _emit 0x75 \
__asm _emit 0xA8 \
__asm _emit 0x8E \
__asm _emit 0xB6 \
__asm _emit 0x31 \
__asm _emit 0x3E \
__asm _emit 0xC5 \
__asm _emit 0xB7 \
__asm _emit 0xDB \
__asm _emit 0x5B \
__asm _emit 0xDB \
__asm _emit 0x26 \
__asm _emit 0x31 \
__asm _emit 0x6F \
__asm _emit 0xC8 \
__asm _emit 0x9A \
__asm _emit 0xC5 \
__asm _emit 0xFD \
__asm _emit 0x18 \
__asm _emit 0xA2 \
__asm _emit 0xEF \
__asm _emit 0xFD \
__asm _emit 0x7B \
__asm _emit 0x6E \
__asm _emit 0x86 \
__asm _emit 0x69 \
__asm _emit 0xB5 \
__asm _emit 0x14 \
__asm _emit 0xAB \
__asm _emit 0xB0 \
__asm _emit 0x1F \
__asm _emit 0x1C \
__asm _emit 0x8F \
__asm _emit 0x86 \
__asm _emit 0x04 \
__asm _emit 0x33 \
__asm _emit 0xB7 \
__asm _emit 0x92 \
__asm _emit 0x15 \
__asm _emit 0x5C \
__asm _emit 0x0F \
__asm _emit 0x0E \
__asm _emit 0x35 \
__asm _emit 0xDA \
__asm _emit 0x65 \
__asm _emit 0x3B \
__asm _emit 0x9E \
__asm _emit 0x08 \
__asm _emit 0x49 \
__asm _emit 0xCB \
__asm _emit 0xAA \
__asm _emit 0xC1 \
__asm _emit 0x14 \
__asm _emit 0x84 \
__asm _emit 0x1B \
__asm _emit 0xF8 \
__asm _emit 0xAE \
__asm _emit 0xA4 \
__asm _emit 0xB4 \
__asm _emit 0xE2 \
__asm _emit 0x05 \
__asm _emit 0x58 \
__asm _emit 0xCD \
__asm _emit 0xF7 \
__asm _emit 0x7D \
__asm _emit 0x53 \


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