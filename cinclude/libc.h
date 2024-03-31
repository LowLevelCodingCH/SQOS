#pragma once
#include <math.h>
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


float Q_rsqrt(float number) // original code, even with what the fuck, a nice word
{
  long i;
  float x2, y;
  const float threehalfs = 1.5F;

  x2 = number * 0.5F;
  y  = number;
  i  = * ( long * ) &y;                       // evil floating point bit level hacking
  i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
  y  = * ( float * ) &i;
  y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
  // y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

  return y;
}

void mcopy(String source, String dest, int no_bytes){
    int i;
    for ( i =0; i < no_bytes ; i ++) {
        *( dest + i ) = *( source + i );
    }
}

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
/*
void mcopyF(String source, String dest){
    int i;
    for ( i =0; i < Ssizeof(source) ; i ++) {
        *( dest + i ) = *( source + i );
    }
}*/