```c
void printC(String str, char color, int os)
```

(String, Color, Offset)

Offset should equal the _length of the last string times 2_, the _length of the current string times 2_, and the _length of all other strings times 1 except the current and last ones_.

`(length of the last string * 2) + (length of the current string * 2) + (length of all other strings)`

Colors: The upper 4 bits are the background, the lower 4 the foreground.

```c
//VV
0x0f
```

printC means print with Color, hence the name.


```c
void print(String str, int os)
```

"print" is the same deal, but it has no color.


```c
void Fprint(String s)
```
Prints only once, good for a start.
Does not work yet.

```c
void clearScr()
```
Clears the screen


```c
void CHvidmalloc(int pos, char putter)
```
Allocates one character to a position in video memory.


```c
void CHvidmalloc(int pos, char putter, char color)
```
Allocates one character to a position in video memory but in color.


```c
int Ssizeof(String str)
```
Returns the actual size of a string.


```c
void Halt()
```
Halts.

```c
int strcmp(char s1[], char s2[])
```
Compares two strings and returns zero if they are equal.

There is a `typedef char* String;` in utils.h.

### Unsure:
the file where i put stuff when idk if it works or not