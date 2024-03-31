#include "../cinclude/libc.h"
#include "../cinclude/filesys.h"

void kernel(){
	/*
	String IRam = "Init RAM: [ OK ]";
	String IMem = "Init MEM: [ OK ]";

	fillS('-',0x3d);

	printC(IRam, 0xca, 0);

	printC(IMem, 0xca, Ssizeof(IRam) * 2 + Ssizeof(IMem) * 2);
	*/

	fillS('#',0xd3);
	printC(read_file(2),0x0f,0);
	return;
}
