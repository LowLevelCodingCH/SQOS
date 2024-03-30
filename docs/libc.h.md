```c
printC(String str, char color, int os)
```

(String, Color, Offset)

Offset should equal the _length of the last string times 2_, the _length of the current string times 2_, and the _length of all other strings times 1_.

`(length of the last string * 2) + (length of the current string * 2) + (length of all other strings)`

Colors: The upper 4 bits are the background, the lower 4 the foreground.

```c
//VV
0x0f
```

printC means print with Color, hence the name.


```c
print(String str, int os)
```

"print" is the same deal, but it has no color.


There is a `typedef char* String;` in utils.h.