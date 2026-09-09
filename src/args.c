#include <string.h>
#include "args.h"

void parseArgs(int argc, char *argv[], GameState *state) {
    // --player1 and --player2 are optional
    if (argc > 1) {
        if (strcmp(argv[1], "--player1") == 0) {
            strcpy(state->player1Name, argv[2]);
        } else if (strcmp(argv[1], "--player2") == 0) {
            strcpy(state->player2Name, argv[2]);
        }
    }
    if (argc > 3) {
        if (strcmp(argv[3], "--player1") == 0) {
            strcpy(state->player1Name, argv[4]);
        } else if (strcmp(argv[3], "--player2") == 0) {
            strcpy(state->player2Name, argv[4]);
        }
    }
}
