bits 16
global NxShutDownClient
NxShutDownClient:
    mov eax, 0x1000
    mov eax, ss
    mov esp, 0xf000
    mov eax, 0x5307
    mov ebx, 0x0001
    mov ecx, 0x0003
    int 0x15

global NxKeyBoardInput
NxKeyBoardInput:
    mov ah, 0
    int 16h
    mov ah, 0x0e
    int 0x10

global NxTextMode
NxTextMode:
    push bp
    mov bp, sp
    push bx
    mov ah, 0x0e
    mov al, 0x0a
    int 0x10