/*
Prints hello world and waits for user to press enter before closing program
Compile with the following:
cl.exe /nologo /Ox /MT /W0 /GS- /DNDEBUG /Tc simple-exe.cpp /link /OUT:executable.exe /SUBSYSTEM:CONSOLE /MACHINE:x64
*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	printf("Hello World!\n");
    getchar();
	
	return 0;
}
