#include "../include/libc.h"
#include "../include/stdint.h"

void main(){
	printC("Nitrix> ", 0x0f, 0); // upper = bg, lower = fg
	printC("Hi", 0x0f, 16); 
	printC("Alol", 0x0f, 8 + 4 + 8); // 20
	printC("Lpppp", 0x0f, 8 + 10 + 2 + 8); // 28
	return;
}
