#pragma once
#include "stdint.h"
#define VIDEO_MEMORY 0xb8000

#define NxPushA() asm volatile("pusha")
#define NxPopA() asm volatile("popa")

typedef char* String;

extern void NxMcopy(String source, String dest, int no_bytes);
extern int  NxStrCmp(char s1[], char s2[]);
extern void NxFprint(String s);
extern void NxHalt();
extern int  NxSsizeof(String str);
extern void NxCHvidmalloc(int pos, char putter);
extern void NxClearScr();
extern void NxCHvidmallocC(int pos, char putter, char color);
extern void NxClearScrC(char color);
extern void NxFillS(char filler, char color);
extern void NxDelB(char filler, char color);
extern void NxPrintC(String str, char color, int os);
extern void NxPrint(String str, int os);
extern void NxShutdown();
extern void NxPrintLn(String str, int lines);
extern void NxPrintLnC(String str, char color, int lines);
extern void NxPerror(String error, int line);
extern void NxSleep(long ticks);

extern void NxOutb(uint16_t port, uint8_t data);
extern void NxOutw(uint16_t port, uint16_t value);
extern void NxOutl(uint16_t port, uint32_t value);
extern uint8_t NxInb(uint16_t port);
extern uint16_t NxInw(uint16_t port);
extern uint32_t NxInl(uint16_t port);

//extern void NxIrq0();
//extern void NxIrq1();
//extern void NxIrq2();
//extern void NxIrq3();
//extern void NxIrq4();
//extern void NxIrq5();
//extern void NxIrq6();
//extern void NxIrq7();
//extern void NxIrq8();
//extern void NxIrq9();
//extern void NxIrq10();
//extern void NxIrq11();
//extern void NxIrq12();
//extern void NxIrq13();
//extern void NxIrq14();
//extern void NxIrq15();