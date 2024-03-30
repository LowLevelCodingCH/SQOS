#pragma once

typedef char* String;

void printC(String str, char color, int os) {
    int k = 0xb8000 + os;
    int g = k + 1 + os;
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


void print(String str, int os) {
    int k = 0xb8000 + os;
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



//@credits @nanobyte-dev on yt
/*void _cdecl printf(const char* fmt, ...)
{
    int* argp = (int*)&fmt;
    int state = PRINTF_STATE_NORMAL;
    int length = PRINTF_LENGTH_DEFAULT;
    int radix = 10;
    bool sign = false;

    argp++;

    while (*fmt)
    {
        switch (state)
        {
            case PRINTF_STATE_NORMAL:
                switch (*fmt)
                {
                    case '%':   state = PRINTF_STATE_LENGTH;
                                break;
                    default:    putc(*fmt);
                                break;
                }
                break;

            case PRINTF_STATE_LENGTH:
                switch (*fmt)
                {
                    case 'h':   length = PRINTF_LENGTH_SHORT;
                                state = PRINTF_STATE_LENGTH_SHORT;
                                break;
                    case 'l':   length = PRINTF_LENGTH_LONG;
                                state = PRINTF_STATE_LENGTH_LONG;
                                break;
                    default:    goto PRINTF_STATE_SPEC_;
                }
                break;

            case PRINTF_STATE_LENGTH_SHORT:
                if (*fmt == 'h')
                {
                    length = PRINTF_LENGTH_SHORT_SHORT;
                    state = PRINTF_STATE_SPEC;
                }
                else goto PRINTF_STATE_SPEC_;
                break;

            case PRINTF_STATE_LENGTH_LONG:
                if (*fmt == 'l')
                {
                    length = PRINTF_LENGTH_LONG_LONG;
                    state = PRINTF_STATE_SPEC;
                }
                else goto PRINTF_STATE_SPEC_;
                break;

            case PRINTF_STATE_SPEC:
            PRINTF_STATE_SPEC_:
                switch (*fmt)
                {
                    case 'c':   putc((char)*argp);
                                argp++;
                                break;

                    case 's':   if (length == PRINTF_LENGTH_LONG || length == PRINTF_LENGTH_LONG_LONG) 
                                {
                                    puts_f(*(const char far**)argp);
                                    argp += 2;
                                }
                                else 
                                {
                                    puts(*(const char**)argp);
                                    argp++;
                                }
                                break;

                    case '%':   putc('%');
                                break;

                    case 'd':
                    case 'i':   radix = 10; sign = true;
                                argp = printf_number(argp, length, sign, radix);
                                break;

                    case 'u':   radix = 10; sign = false;
                                argp = printf_number(argp, length, sign, radix);
                                break;

                    case 'X':
                    case 'x':
                    case 'p':   radix = 16; sign = false;
                                argp = printf_number(argp, length, sign, radix);
                                break;

                    case 'o':   radix = 8; sign = false;
                                argp = printf_number(argp, length, sign, radix);
                                break;

                    // ignore invalid spec
                    default:    break;
                }

                // reset state
                state = PRINTF_STATE_NORMAL;
                length = PRINTF_LENGTH_DEFAULT;
                radix = 10;
                sign = false;
                break;
        }

        fmt++;
    }
}*/