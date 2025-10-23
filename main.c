#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "functions/board.h"
#include "functions/box.h"
#include "functions/character.h"
#include "functions/goal.h"

int main()
{
    board *map = malloc(sizeof(*map));
    map->size_x = 10;
    map->size_y = 10;
    board_init(map);
    print_board(map);
    exit(0);
}