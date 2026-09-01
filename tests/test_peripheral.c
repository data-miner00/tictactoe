#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../src/peripheral.h"

static void assertReadInt(const char *input, int expected) {
    char buf[16];
    strcpy(buf, input);
    stdin = fmemopen(buf, strlen(buf), "r");
    assert(readInt() == expected);
    fclose(stdin);
}

static void test_readInt_simpleDigits(void) {
    assertReadInt("5\n", 5);
}

static void test_readInt_leadingGarbage(void) {
    assertReadInt("  \n5", 5);
}

static void test_readInt_multiDigit(void) {
    assertReadInt("42", 42);
}

int main(void) {
    test_readInt_simpleDigits();
    test_readInt_leadingGarbage();
    test_readInt_multiDigit();

    printf("All peripheral tests passed.\n");
    return 0;
}
