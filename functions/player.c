#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../struct.h"
#include "box.h"

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

void player_move(object *player, object *box, board *map)
{
    int moved = 0;                            // checks if movement is made
    int move_choice;                          // gets the choice of movement
    object *offset = malloc(sizeof(*offset)); // will take ofset depending on where player wants to move
    int scanf_test;                           // makes sure scanf works corectly

    while (moved == 0)
    {
        printf("Choose where to move, left(1), right(2), up(3), down(4) :");
        scanf_test = scanf("%d", &move_choice);

        if (scanf_test != 1)
        {
            printf("Please input a number\n");
            while (getchar() != '\n')
                ; // clears input of scanf in case of not a number
        }

        else if (move_choice == LEFT)
        {
            offset->coord_y = 0;
            offset->coord_x = -1;
            moved = 1;
        }

        else if (move_choice == RIGHT)
        {
            offset->coord_y = 0;
            offset->coord_x = 1;
            moved = 1;
        }

        else if (move_choice == UP)
        {
            offset->coord_y = -1;
            offset->coord_x = 0;
            moved = 1;
        }

        else if (move_choice == DOWN)
        {
            offset->coord_y = 1;
            offset->coord_x = 0;
            moved = 1;
        }

        else
        {
            printf("Please choose a number within the range given.\n");
        }

        if (moved != 0) // if valid move option was given
        {
            if (map->board_content[player->coord_y + offset->coord_y][player->coord_x + offset->coord_x] != ' ')
            {
                if (map->board_content[player->coord_y + offset->coord_y][player->coord_x + offset->coord_x] == 'X') // tries to move box first
                {
                    moved = move_box(map, box, offset); // gets whether box was moved or not
                }

                else if (map->board_content[player->coord_y + offset->coord_y][player->coord_x + offset->coord_x] == '#')
                {
                    printf("You can't walk into a wall...\n");
                    moved = 0;
                }

                else // case where the place is the goal
                {
                    printf("The box is supposed to go there, not you...\n");
                    moved = 0;
                }
            }

            if (moved == 1) // repeat condition in case box was moved
            {
                map->board_content[player->coord_y][player->coord_x] = ' ';
                map->board_content[player->coord_y + offset->coord_y][player->coord_x + offset->coord_x] = 'o';
                player->coord_y = player->coord_y + offset->coord_y;
                player->coord_x = player->coord_x + offset->coord_x;
            }
        }
    }
}