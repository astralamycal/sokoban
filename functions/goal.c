#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../struct.h"
#include "board.h"

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

void lose_check(object *box, object *goal, board *map)
{
    if (box->coord_y == 1 && goal->coord_y != 1) // checks if lost from top border
    {
        write_board(map, 2);
    }

    if (box->coord_y == map->size_y - 2 && goal->coord_y != map->size_y - 2) // checks if lost from bottom border
    {
        write_board(map, 2);
    }

    if (box->coord_x == 1 && goal->coord_x != 1) // checks if lost from left border
    {
        write_board(map, 2);
    }

    if (box->coord_x == map->size_x - 2 && goal->coord_x != map->size_x - 2) // checks if lost from right border
    {
        write_board(map, 2);
    }
}