#define VIDEO_MEMORY 0xb8000
#include "../cinclude/stdint.h"

typedef char* String;

void NxMcopy(String source, String dest, int no_bytes){
    int i;
    for ( i =0; i < no_bytes ; i ++) {
        *( dest + i ) = *( source + i );
    }
}

int NxStrCmp(char s1[], char s2[]) {
    int i;
    for (i = 0; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0') return 0;
    }
    return s1[i] - s2[i];
}

void NxFprint(String s){
  char *base = (void *) VIDEO_MEMORY;
  while (*s) {
    *base++ = *s++;
    *base++ = 0x0f;
  }
}

void NxHalt(){
    asm volatile("hlt");
}

int NxSsizeof(String str){
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void NxCHvidmalloc(int pos, char putter){
    *(String)(VIDEO_MEMORY + pos) = putter;
}

void NxClearScr(){
    for(int i = 0; i < 80*100; i++){
        if(i % 2 == 0)NxCHvidmalloc(i, ' ');
    }
}

void NxCHvidmallocC(int pos, char putter, char color){
    *(String)(VIDEO_MEMORY + pos) = putter;
    *(String)(VIDEO_MEMORY + pos + 1) = color;
}

void NxClearScrC(char color){
    for(int i = 0; i < 80*100; i++){
        if(i % 2 == 0)NxCHvidmallocC(i, ' ', color);
    }
}

void NxFillS(char filler, char color){
    for(int i = 0; i < 80*100; i++){
        if(i % 2 == 0)NxCHvidmallocC(i, filler, color);
    }
}

void NxDelB(char filler, char color){
    for(int i = 0; i < 80*2; i++){
        if(i % 2 == 0)NxCHvidmallocC(i, filler, color);
    }
}

void NxPrintC(String str, char color, int os) {
    //int k = VIDEO_MEMORY + os;
    //int g = k + 1;
    //int len = 0;
    //
    //while (str[len] != '\0') {
    //    len++;
    //}
    //
    //for (int i = 0; i < len; i++) {
    //    *(char*)k = str[i];
    //    *(char*)g = color;
    //    k += 2; 
    //    g += 2;
    //}
    int strlen = NxSsizeof(str);
    for(int i = 0; i < strlen; i++){
        if(i % 2 == 0)NxCHvidmallocC(i+os, str[i], color);
        else NxCHvidmallocC(i+os+1, str[i], color);
    }
    return;
}


void NxPrint(String str, int os) {
    //int k = VIDEO_MEMORY + os;
    //int len = 0;
    //
    //while (str[len] != '\0') {
    //    len++;
    //}
    //
    //for (int i = 0; i < len; i++) {
    //    *(char*)k = str[i];
    //    k += 2; 
    //}
    int strlen = NxSsizeof(str);
    for(int i = 0; i < strlen; i++){
        NxCHvidmalloc(i+os, str[i]);
    }
    return;
}

void NxShutdown(){
    NxClearScrC(0x00);
    NxPrintC("SHUTDOWN!", 0x0c, 0);
    NxHalt();
    return;
}

void NxPrintLn(String str, int lines){
    if(NxSsizeof(str) % 2 == 0){NxPrint(str, 160*lines);}
}

void NxPrintLnC(String str, char color, int lines){
    if(NxSsizeof(str) % 2 == 0){NxPrintC(str, color, 160*lines);}
}

void NxPerror(String error, int line){
    NxPrintC(error, 0x0c, 160*line);
}

void NxSleep(long ticks){
    long startTicks = ticks;
    long timer_ticks = 0;
    while(timer_ticks < startTicks * ticks){timer_ticks++;}
    return;
}


/**************** SEND/RECEIVE BYTE ******************/
void NxOutb(uint16_t port, uint8_t data){
	asm volatile("outb %0, %1" : : "a"(data), "Nd"(port));
	return;
}

uint8_t NxInb(uint16_t port){
	uint8_t res;
	asm volatile("inb %1, %0" : "=a"(res) : "Nd"(port));
	return res;
}

/**************** SEND/RECEIVE WORD ******************/

void NxOutw(uint16_t port, uint16_t value)
{
	asm volatile ("outw %w0, %1" : : "a" (value), "id" (port) );
}

uint16_t NxInw(uint16_t port){
   uint16_t ret;
   asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
   return ret;
} 

/**************** SEND/RECEIVE LONG (32-BIT) ******************/

void NxOutl(uint16_t port, uint32_t value){
	asm volatile ("outl %%eax, %%dx" :: "d" (port), "a" (value));
}

uint32_t NxInl(uint16_t port){
   uint32_t ret;
   asm volatile ("inl %1, %0" : "=a" (ret) : "dN" (port));
   return ret;
} 