#pragma once
#include "stdint.h"
#define VIDEO_MEMORY 0xb8000
#define MAX_COLS 80
#define MAX_ROWS 100
#define WHITE_ON_BLACK 0x0f
#define RED_ON_WHITE 0x0d
#define UNUSED(x) (void)(x)
#include "unsure.h"
extern void NxShutDownClient(void);
extern void NxKeyBoardInput(void);
void NxTextMode();
char *vidmem = VIDEO_MEMORY;
// #include "keyboard.h"

typedef char* String;

void StextMode(){
    NxTextMode();
}

int strcmp(char s1[], char s2[]) {
    int i;
    for (i = 0; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0') return 0;
    }
    return s1[i] - s2[i];
}

void Fprint(String s){
  char *base = (void *) VIDEO_MEMORY;
  while (*s) {
    *base++ = *s++;
    *base++ = 0x0f;
  }
}

void Halt(){
    asm volatile("hlt");
}

void Shutdown(){
    NxShutDownClient();
    return;
}

int Ssizeof(String str){
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void CHvidmalloc(int pos, char putter){
    *(String)(VIDEO_MEMORY + pos) = putter;
}

void clearScr(){
    for(int i = 0; i < 80*100; i++){
        if(i % 2 == 0)CHvidmalloc(i, ' ');
    }
}

void CHvidmallocC(int pos, char putter, char color){
    *(String)(VIDEO_MEMORY + pos) = putter;
    *(String)(VIDEO_MEMORY + pos + 1) = color;
}

void clearScrC(char color){
    for(int i = 0; i < 80*100; i++){
        if(i % 2 == 0)CHvidmallocC(i, ' ', color);
    }
}

void fillS(char filler, char color){
    for(int i = 0; i < 80*100; i++){
        if(i % 2 == 0)CHvidmallocC(i, filler, color);
    }
}

void delB(char filler, char color){
    for(int i = 0; i < 80; i++){
        if(i % 2 == 0)CHvidmallocC(i, filler, color);
    }
}

void printC(String str, char color, int os) {
    int k = VIDEO_MEMORY + os;
    int g = k + 1;
    int len = 0;
    
    while (str[len] != '\0') {
        len++;
    }
    
    for (int i = 0; i < len; i++) {
        *(char*)k = str[i];
        *(char*)g = color;
        k += 2; 
        g += 2;
    }
    return;
}


void print(String str, int os) {
    int k = VIDEO_MEMORY + os;
    int len = 0;
    
    while (str[len] != '\0') {
        len++;
    }
    
    for (int i = 0; i < len; i++) {
        *(char*)k = str[i];
        k += 2; 
    }
    return;
}

void keyboardInput(){
    NxKeyBoardInput();
}
