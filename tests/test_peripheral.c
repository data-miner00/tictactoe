#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../src/peripheral.h"

static void test_readInt_simpleDigits(void) {
    char buf[] = "5\n";
    stdin = fmemopen(buf, strlen(buf), "r");
    assert(readInt() == 5);
    fclose(stdin);
}

static void test_readInt_leadingGarbage(void) {
    char buf[] = "  \n5";
    stdin = fmemopen(buf, strlen(buf), "r");
    assert(readInt() == 5);
    fclose(stdin);
}

static void test_readInt_multiDigit(void) {
    char buf[] = "42";
    stdin = fmemopen(buf, strlen(buf), "r");
    assert(readInt() == 42);
    fclose(stdin);
}

int main(void) {
    test_readInt_simpleDigits();
    test_readInt_leadingGarbage();
    test_readInt_multiDigit();

    printf("All peripheral tests passed.\n");
    return 0;
}
