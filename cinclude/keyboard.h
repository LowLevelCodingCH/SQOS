// DRIVER

#define PIC1_PORT_A 0x20
#define PIC2_PORT_A 0xA0
#define PIC1_COMMAND PIC1_PORT_A
#define PIC2_COMMAND PIC2_PORT_A
#define PIC1_DATA (PIC1_PORT_A + 1)
#define PIC2_DATA (PIC2_PORT_A + 1)
#define PIC_EOI 0x20

#define KEYBOARD_IRQ 1

void outb(unsigned short port, unsigned char val) {
    asm volatile("outb %0, %1" : : "a"(val), "Nd"(port));
}

unsigned char inb(unsigned short port) {
    unsigned char ret;
    asm volatile("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

void keyboard_handler() {
    unsigned char scan_code = inb(0x60);
    // Handle the key press here
    // For simplicity, just print the scan code
    // Replace this with your actual handling code
    // For example, you might buffer the key presses and process them later
    // Send End of Interrupt (EOI) signal to PIC
    vidmem[40] = 'O';
    outb(PIC1_COMMAND, PIC_EOI);
}

void init_keyboard() {
    // Enable IRQ line for the keyboard (IRQ 1)
    // Configure PIC (Programmable Interrupt Controller)
    outb(0x21, inb(0x21) & ~2); // Clear bit 1 of port 0x21 to enable IRQ 1

    // Install the keyboard interrupt handler
    // This would typically involve setting up the IDT
    // but for simplicity, let's assume it's already set up
    // and the keyboard interrupt is mapped to the keyboard_handler function

    // Mask all IRQs except IRQ 1 (keyboard)
    //outb(PIC1_DATA, 0xFE);
}