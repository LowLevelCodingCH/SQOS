#pragma once
#include "stdint.h"
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