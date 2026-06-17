#include <stdio.h>
#include "bowling.h"

void init_game(struct game *game, int *rolls, int nb_rolls) {
    for(int i = 0; i < nb_rolls; i++) {
        game->rolls[i] = rolls[i];
    };
    for(int i = nb_rolls; i < MAX_ROLLS; i++) {
        game->rolls[i] = 0;
    }
    game->nb_rolls = nb_rolls;
}

int score(struct game *game) {

#define NEW_FRAME(h) ( h % 2 == 0 )
#define STRIKE(i) ( game->rolls[i] == 10 )
#define SPARE(i) ( game->rolls[i] + game->rolls[i+1] == 10 )

    int result = 0;
    int half_frames = 0;
    for(int index = 0; index < game->nb_rolls && half_frames < 20; index++) {
        if(NEW_FRAME(half_frames) && STRIKE(index)) {
            result += game->rolls[index+1];
            result += game->rolls[index+2];
            half_frames++;
        }
        else if(NEW_FRAME(half_frames) && SPARE(index)) {
            result += game->rolls[index+2];
        }
        result += game->rolls[index];
        half_frames++;
    }
    return result;
}
