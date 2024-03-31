export PATH=$PATH:/usr/local/i386elfgcc/bin

nasm "asmfiles/bootloader.asm" -f bin -o "Binaries/boot.bin"
nasm "asmfiles/kernel_entry.asm" -f elf -o "Binaries/kernel_entry.o"
i386-elf-gcc -ffreestanding -m32 -g -c "cfiles/kernel.c" -o "Binaries/kernel.o"
nasm "asmfiles/padding.asm" -f bin -o "Binaries/zeroes.bin"
nasm "asmfiles/filesys.asm" -f bin -o "Binaries/filesys.bin"
nasm "asmfiles/systempad.asm" -f bin -o "Binaries/systempad.bin"
nasm "asmfiles/asmfunctions.asm" -f elf -o "Binaries/asmfunctions.o"

i386-elf-ld -o "Binaries/full_kernel.bin" -Ttext 0x1000 "Binaries/kernel_entry.o" "Binaries/kernel.o" "Binaries/asmfunctions.o" --oformat binary

cat "Binaries/boot.bin" "Binaries/full_kernel.bin" "Binaries/filesys.bin" "Binaries/zeroes.bin" "Binaries/systempad.bin" > "Binaries/OS.bin"

qemu-system-x86_64 -drive format=raw,file="Binaries/OS.bin",index=0,if=floppy,  -m 128M