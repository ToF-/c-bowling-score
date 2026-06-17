#include <stdio.h>
#include "bowling.h"

#define MAX_INPUT 21

int main(int argc, char *argv[]) {
    int max_tests;

    scanf("%d", &max_tests);
    for (int t = 0; t < max_tests; t++) {
        struct game game;
        int max_rolls;
        int data[MAX_INPUT];
        scanf("%d", &max_rolls);
        for (int r = 0; r < max_rolls; r++) {
            scanf("%d", &data[r]);
        }
        init_game(&game, data, max_rolls);
        printf("%d\n", score(&game));
    }

    return 0;
}
