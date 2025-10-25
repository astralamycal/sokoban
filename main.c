#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "functions/board.h"
#include "functions/box.h"
#include "functions/player.h"
#include "functions/goal.h"

int main()
{
    // setting up the board
    board *map = malloc(sizeof(*map));
    map->size_x = BOARD_SIZE_BASE;
    map->size_y = BOARD_SIZE_BASE;
    board_init(map);

    // setting up goal
    object *goal = malloc(sizeof(*goal));
    goal_init(goal, map);

    // setting up player
    object *player = malloc(sizeof(*player));
    player_init(player, map);

    // setting up box
    object *box = malloc(sizeof(*box));
    box_init(box, map);

    // main loop
    print_board(map, player, box, goal);
    exit(0);
}