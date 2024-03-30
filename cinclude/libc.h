#pragma once
#define VIDEO_MEMORY 0xb8000
char* vidmem = (char*)0xb8000;
// #include "keyboard.h"

typedef char* String;

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

void printC(String str, char color, int os) {
    int k = VIDEO_MEMORY + os;
    int g = k + 1 + os;
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


