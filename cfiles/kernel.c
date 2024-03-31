#include "../cinclude/libc.h"
#include "../cinclude/filesys.h"

void kernel(){
	String src = "Argk";
	String des;
	mcopy(src, des, Ssizeof(src));
	Fprint(des);
	return;
}
