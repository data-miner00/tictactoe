#include "peripheral.h"
#include <stdio.h>

int readInt() {
    int num = 0;
    int ch = getchar();

    // 1. Skip non-digit characters (spaces, newlines, tabs)
    while (ch < '0' || ch > '9') {
        ch = getchar();
    }

    // 2. Process all consecutive digit characters
    while (ch >= '0' && ch <= '9') {
        // Multiply current total by 10 and add the new digit
        num = num * 10 + (ch - '0');
        ch = getchar();
    }

    return num;
}
