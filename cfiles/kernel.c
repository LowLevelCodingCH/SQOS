#include "../cinclude/libc.h"
#include "../cinclude/stdint.h"
// #include "../cinclude/filesys.h"

void main(){
	String clang = "The C programming language.";
	int clanglen = Ssizeof(clang);
	clearScr();
	print(clang, 0);
	print("hi", clanglen*2 + 2*2);
	return;
}
