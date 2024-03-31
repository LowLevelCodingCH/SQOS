```c
typedef char* String;
extern void NxMcopy(String source, String dest, int no_bytes);
extern int  NxStrCmp(char s1[], char s2[]);
extern void NxFprint(String s);
extern void NxHalt();
extern int  NxSsizeof(String str);
extern void NxCHvidmalloc(int pos, char putter);
extern void NxClearScr();
extern void NxCHvidmallocC(int pos, char putter, char color);
extern void NxClearScrC(char color);
extern void NxFillS(char filler, char color);
extern void NxDelB(char filler, char color);
extern void NxPrintC(String str, char color, int os);
extern void NxPrint(String str, int os);
extern void NxShutdown();
```


Function: NxMcopy

    Description: Copies a specified number of bytes from the source string to the destination string.
    Parameters:
        source: Pointer to the source string.
        dest: Pointer to the destination string.
        no_bytes: Number of bytes to be copied.
    Return Type: void

Function: NxStrCmp

    Description: Compares two strings s1 and s2 lexicographically.
    Parameters:
        s1: First string to compare.
        s2: Second string to compare.
    Return Type: int
        Returns 0 if s1 is equal to s2.
        Returns a value greater than 0 if s1 is lexicographically greater than s2.
        Returns a value less than 0 if s1 is lexicographically less than s2.

Function: NxFprint

    Description: Prints a string to the console.
    Parameters:
        s: String to be printed.
    Return Type: void

Function: NxHalt

    Description: Halts the execution of the program.
    Parameters: None
    Return Type: void

Function: NxSsizeof

    Description: Returns the size of the string.
    Parameters:
        str: String for which size is to be determined.
    Return Type: int
        Size of the string in bytes.

Function: NxCHvidmalloc

    Description: Allocates memory at a specified position and fills it with a specified character.
    Parameters:
        pos: Position where memory is to be allocated.
        putter: Character to fill the allocated memory.
    Return Type: void

Function: NxClearScr

    Description: Clears the screen.
    Parameters: None
    Return Type: void

Function: NxCHvidmallocC

    Description: Allocates memory at a specified position, fills it with a specified character, and sets the color.
    Parameters:
        pos: Position where memory is to be allocated.
        putter: Character to fill the allocated memory.
        color: Color to set.
    Return Type: void

Function: NxClearScrC

    Description: Clears the screen with a specified color.
    Parameters:
        color: Color to clear the screen with.
    Return Type: void

Function: NxFillS

    Description: Fills the screen with a specified character and color.
    Parameters:
        filler: Character to fill the screen with.
        color: Color to set.
    Return Type: void

Function: NxDelB

    Description: Fills a row from the screen with a specified color.
    Parameters:
        filler: Character to fill with.
        color: Color to fill with.
    Return Type: void

Function: NxPrintC

    Description: Prints a string with a specified color and offset.
    Parameters:
        str: String to be printed.
        color: Color of the string.
        offset: Offset value.
    Return Type: void

Function: NxPrint

    Description: Prints a string with an offset value.
    Parameters:
        str: String to be printed.
        offset: Offset value.
    Return Type: void

Function: NxShutdown

    Description: Shuts down the operating system.
    Parameters: None
    Return Type: void


Text will wrap around the rows, if you do (160*number_of_rows+offset) _offset has to be even_.