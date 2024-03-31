#define VIDEO_MEMORY 0xb8000

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


void NxPrint(String str, int os) {
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

void NxShutdown(){
    NxClearScrC(0x00);
    NxPrintC("SHUTDOWN!", 0x0c, 0);
    NxHalt();
    return;
}