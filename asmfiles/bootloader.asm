[org 0x7c00]                         
mov [BOOT_DISK], dl                        
msga: db 0x0a,0x0a,0x0a,0x0a,0x0a,0x0a,0x0a,0x0a,0x0a,0x0a,0x0a,0x0a,0x0a,"LOADING KERNEL-1... (nxkernel.o)",0
msgb: db "NXBOOTLOADER",0xa,0x0
printB:
    mov ah, 0x0e
    mov al, [msgb + bx]
    int 0x10
    cmp al, 0
    je kbi
    inc bx
    jmp printB                

mov ah, 0x0e

kbi:
    mov ah, 0
    int 0x16
    mov ah, 0x0e
    int 0x10
    pusha
    mov al, ' '
    int 0x10
    popa
    cmp al, '1'
    je printA
    cmp al, '2'
    je printB ; other kernels
    cmp al, '3'
    je exit
    cmp al, '4'
    je printB
    jmp kbi

printA:
    KERNEL_LOCATION equ 0x1000 
    mov ah, 0x0e
    mov al, [msga + bx]
    int 0x10
    cmp al, 0
    je cont
    inc bx
    jmp printA

cont:
    mov cx, 0x0F
    mov dx, 0x4240

    mov ah, 0x86
    int 0x15
xor ax, ax                          
mov es, ax
mov ds, ax
mov bp, 0x8000
mov sp, bp

mov bx, KERNEL_LOCATION
mov dh, 2

mov ah, 0x02
mov al, dh 
mov ch, 0x00
mov dh, 0x00
mov cl, 0x02
mov dl, [BOOT_DISK]
int 0x13                ; no error management, do your homework!

                                    
mov ah, 0x0
mov al, 0x3
int 0x10                ; text mode


CODE_SEG equ GDT_code - GDT_start
DATA_SEG equ GDT_data - GDT_start

cli
lgdt [GDT_descriptor]
mov eax, cr0
or eax, 1
mov cr0, eax
jmp CODE_SEG:start_protected_mode

jmp $
                                    
BOOT_DISK: db 0

GDT_start:
    GDT_null:
        dd 0x0
        dd 0x0

    GDT_code:
        dw 0xffff
        dw 0x0
        db 0x0
        db 0b10011010
        db 0b11001111
        db 0x0

    GDT_data:
        dw 0xffff
        dw 0x0
        db 0x0
        db 0b10010010
        db 0b11001111
        db 0x0

GDT_end:

GDT_descriptor:
    dw GDT_end - GDT_start - 1
    dd GDT_start


[bits 32]
start_protected_mode:
    mov ax, DATA_SEG
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	
	mov ebp, 0x90000		; 32 bit stack base pointer
	mov esp, ebp

    jmp KERNEL_LOCATION

                                     
exit:
    hlt
    jmp exit
times 510-($-$$) db 0              
dw 0xaa55
