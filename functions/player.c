#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../struct.h"

void player_init(object *player, board *map)
{
    int placed = 0;
    while (placed == 0) // while goal not placed
    {
        player->coord_y = (rand() % (map->size_x - 2)) + 1;              // sets the random coordinate y while avoiding walls
        player->coord_x = (rand() % (map->size_x - 2)) + 1;              // sets the random coordinate x while avoiding walls
        if (map->board_content[player->coord_y][player->coord_x] == ' ') // check if spot is free
        {
            map->board_content[player->coord_y][player->coord_x] = 'o';
            placed = 1;
        }
    }
}