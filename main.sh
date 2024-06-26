export PATH=$PATH:/usr/local/i386elfgcc/bin

rm -rf Binaries/Nx/*
rm -rf Binaries/Nx
rm -rf Binaries/*
rm -rf Binaries

rm -rf Nx/Kernel/*
rm -rf Nx/Kernel

rm -rf Nx/Boot/*
rm -rf Nx/Boot

rm -rf Nx/*
rm -rf Nx

mkdir Binaries
mkdir Binaries/Nx

mkdir Nx
mkdir Nx/Kernel
mkdir Nx/Boot

i386-elf-gcc -ffreestanding -m32 -g -c "cfiles/NxKernel.c" -o "Binaries/NxKernel.o"
i386-elf-gcc -ffreestanding -m32 -g -c "cfiles/libc.c" -o "Binaries/libc.o"

nasm "asmfiles/kernel_entry.asm" -f elf -o "Binaries/kernel_entry.o"
nasm "asmfiles/interrupts.asm" -f elf -o "Binaries/interrupts.o"

nasm "asmfiles/bootloader.asm" -f bin -o "Binaries/boot.bin"
nasm "asmfiles/padding.asm" -f bin -o "Binaries/zeroes.bin"

i386-elf-ld -o "Binaries/full_kernel.bin" -Ttext 0x1000 "Binaries/kernel_entry.o" "Binaries/NxKernel.o" "Binaries/libc.o" "Binaries/interrupts.o" --oformat binary

cat "Binaries/boot.bin" "Binaries/full_kernel.bin" "Binaries/zeroes.bin" > "Binaries/Nx/OS.bin"

cp Binaries/NxKernel.o Nx/Kernel
cp Binaries/boot.bin Nx/Boot

qemu-system-x86_64 -drive format=raw,file="Binaries/Nx/OS.bin",index=0,if=floppy, -m 128M

rm -rf Binaries/Nx/*
rm -rf Binaries/Nx
rm -rf Binaries/*
rm -rf Binaries