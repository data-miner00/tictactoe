#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../src/args.h"
#include "../src/state.h"

static GameState defaultState(void) {
    GameState state = {0};
    strcpy(state.player1Name, "Player One");
    strcpy(state.player2Name, "Player Two");
    return state;
}

static void test_parseArgs_noArgs(void) {
    char *argv[] = {"prog"};
    GameState state = defaultState();
    parseArgs(1, argv, &state);
    assert(strcmp(state.player1Name, "Player One") == 0);
    assert(strcmp(state.player2Name, "Player Two") == 0);
}

static void test_parseArgs_player1Only(void) {
    char *argv[] = {"prog", "--player1", "Alice"};
    GameState state = defaultState();
    parseArgs(3, argv, &state);
    assert(strcmp(state.player1Name, "Alice") == 0);
    assert(strcmp(state.player2Name, "Player Two") == 0);
}

static void test_parseArgs_player2Only(void) {
    char *argv[] = {"prog", "--player2", "Bob"};
    GameState state = defaultState();
    parseArgs(3, argv, &state);
    assert(strcmp(state.player1Name, "Player One") == 0);
    assert(strcmp(state.player2Name, "Bob") == 0);
}

static void test_parseArgs_unrecognizedFlag(void) {
    char *argv[] = {"prog", "--bogus", "Alice"};
    GameState state = defaultState();
    parseArgs(3, argv, &state);
    assert(strcmp(state.player1Name, "Player One") == 0);
    assert(strcmp(state.player2Name, "Player Two") == 0);
}

static void test_parseArgs_secondFlagPlayer1(void) {
    char *argv[] = {"prog", "--bogus", "ignored", "--player1", "Alice"};
    GameState state = defaultState();
    parseArgs(5, argv, &state);
    assert(strcmp(state.player1Name, "Alice") == 0);
    assert(strcmp(state.player2Name, "Player Two") == 0);
}

static void test_parseArgs_secondFlagPlayer2(void) {
    char *argv[] = {"prog", "--bogus", "ignored", "--player2", "Bob"};
    GameState state = defaultState();
    parseArgs(5, argv, &state);
    assert(strcmp(state.player1Name, "Player One") == 0);
    assert(strcmp(state.player2Name, "Bob") == 0);
}

static void test_parseArgs_bothFlags(void) {
    char *argv[] = {"prog", "--player1", "Alice", "--player2", "Bob"};
    GameState state = defaultState();
    parseArgs(5, argv, &state);
    assert(strcmp(state.player1Name, "Alice") == 0);
    assert(strcmp(state.player2Name, "Bob") == 0);
}

int main(void) {
    test_parseArgs_noArgs();
    test_parseArgs_player1Only();
    test_parseArgs_player2Only();
    test_parseArgs_unrecognizedFlag();
    test_parseArgs_secondFlagPlayer1();
    test_parseArgs_secondFlagPlayer2();
    test_parseArgs_bothFlags();

    printf("All args tests passed.\n");
    return 0;
}
