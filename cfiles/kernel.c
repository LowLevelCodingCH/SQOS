#include "../cinclude/libc.h"

void kernel(){
	NxFprint("Hi");
	NxDelB('-',0x0c);
	NxPrint("Hi", 160*0);
	NxPrint("aa", 160*2+8);
	return;
}
