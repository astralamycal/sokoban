#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../struct.h"

void goal_init(object *goal, board *map)
{
    int placed = 0;
    while (placed == 0) // while goal not placed
    {
        srand(time(NULL));
        goal->coord_y = (rand() % (map->size_x - 2)) + 1;            // sets the random coordinate y while avoiding walls
        goal->coord_x = (rand() % (map->size_x - 2)) + 1;            // sets the random coordinate x while avoiding walls
        if (map->board_content[goal->coord_y][goal->coord_x] == ' ') // check if spot is free
        {
            map->board_content[goal->coord_y][goal->coord_x] = '.';
            placed = 1;
        }
    }
}