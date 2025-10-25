#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../struct.h"

void board_init(board *map) // creates the map to play in
{
    map->board_content = malloc((map->size_y + 1) * sizeof(char *)); // line amount + 1 for NULL end
    for (int y = 0; y < map->size_y; y++)
    {
        map->board_content[y] = malloc((map->size_x + 1) * sizeof(char)); // collumn amount + 1 for char* end
        for (int x = 0; x < map->size_x; x++)
        {
            if (y == 0 || y == map->size_x - 1)
            {
                map->board_content[y][x] = '#'; // top and bottom border
            }

            else
            {
                if (x == 0 || x == (map->size_x - 1))
                {
                    map->board_content[y][x] = '#'; // border collumns
                }

                else
                {
                    map->board_content[y][x] = ' '; // non border collumns
                }
            }
        }
        map->board_content[y][map->size_x + 1] = '\0'; // adds end of char* symbol
    }
    map->board_content[map->size_y + 1] = NULL; // adds end of board NULL value
}

void print_board(board *map, object *player, object *box, object *goal) // shows the current map status
{
    system("clear");

    printf("Player : %d %d \n", player->coord_y, player->coord_x);
    printf("Box : %d %d \n", box->coord_y, box->coord_x);
    printf("Goal : %d %d \n", goal->coord_y, goal->coord_x);
    printf("\n");

    for (int y = 0; y < map->size_y; y++)
    {
        for (int x = 0; x < map->size_x; x++)
        {
            printf("%c ", map->board_content[y][x]); // shows each space with spaces in between
        }
        printf("\n");
    }
}