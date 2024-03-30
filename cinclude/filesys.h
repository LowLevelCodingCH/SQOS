#include "libc.h"

#define SECTOR_SIZE 512

void read_disk() {
    unsigned char buffer[SECTOR_SIZE];
    unsigned int lba = 0; // Logical Block Address of the sector to read
    unsigned int cylinder = 0; // Cylinder number
    unsigned int head = 0; // Head number
    unsigned int sector = 3; // Sector number (1-based)

    // Prepare parameters for disk read
    unsigned char drive = 0x80; // Assuming disk is the first hard drive
    unsigned int buffer_offset = (unsigned int)buffer;
    unsigned char count = 1; // Number of sectors to read

    // Cylinder and sector are both 10-bit values, so we need to split them
    unsigned char cl = (cylinder & 0xFF);
    unsigned char ch = ((cylinder >> 8) & 0xFF);
    unsigned char dh = (head & 0xFF);

    // Adjust sector number to 0-based for BIOS interrupt
    sector--;

    // Issue the disk read interrupt
    __asm__ __volatile__(
        "mov $0x02, %%ah\n\t"         // Function code: read sectors into memory
        "mov %0, %%al\n\t"            // Number of sectors to read
        "mov %1, %%ch\n\t"            // Cylinder
        "mov %2, %%cl\n\t"            // Sector
        "mov %3, %%dh\n\t"            // Head
        "mov %4, %%dl\n\t"            // Drive number
        "mov %5, %%bx\n\t"            // Offset of the buffer
        "int $0x13\n\t"               // Issue BIOS interrupt
        :
        : "m"(count), "m"(ch), "m"(cl), "m"(dh), "m"(drive), "m"(buffer_offset)
        : "cc", "%ah", "%al", "%ch", "%cl", "%dh", "%dl", "%bx"
    );

    // Print the content of the buffer (for demonstration purposes)
    for (int i = 0; i < SECTOR_SIZE; i++) {
        // Assuming VGA text mode for printing
        // (you might need to change this depending on your system)
        *((char*)(VIDEO_MEMORY + (i * 2))) = buffer[i];
        *((char*)(VIDEO_MEMORY + (i * 2) + 1)) = 0x07; // White on black
    }
}
