#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../struct.h"

int board_init(board *map) // creates the map to play in
{
    map->board_content = malloc(map->size_y * sizeof(char *)); // line amount
    for (int i = 0; i <= map->size_y - 1; i++)
    {
        map->board_content[i] = malloc(map->size_x * sizeof(char)); // collumn amount
        if (i == 0 || i == map->size_x - 1)
        {
            map->board_content[i] = "#########\0"; // top and bottom border
        }

        else
        {
            map->board_content[i] = "#       #\0"; // non border lines
        }
    }
    return (1); // 1 = worked as intended
}