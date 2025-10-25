#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../struct.h"

void box_init(object *box, board *map)
{
    int placed = 0;
    while (placed == 0) // while box not placed
    {
        box->coord_y = (rand() % (map->size_y - 4)) + 2;           // sets the random coordinate y while avoiding walls
        box->coord_x = (rand() % (map->size_x - 4)) + 2;           // sets the random coordinate x while avoiding walls
        if (map->board_content[box->coord_y][box->coord_x] == ' ') // check if spot is free
        {
            map->board_content[box->coord_y][box->coord_x] = 'X';
            placed = 1;
        }
    }
}