#ifndef __BOARD_H__
#define __BOARD_H__

void board_init(board *map);
void print_board(board *map, object *player, object *box, object *goal);

#endif