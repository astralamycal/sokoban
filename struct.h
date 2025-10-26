#ifndef __STRUCT_H__
#define __STRUCT_H__

#define BOARD_SIZE_BASE 12; // base board size to mess with

enum movements
{
    LEFT = 1,
    RIGHT,
    UP,
    DOWN
};

typedef struct s_board board;

struct s_board
{
    int size_x;
    int size_y;
    char **board_content;
};

typedef struct s_object object;

struct s_object
{
    int coord_x;
    int coord_y;
};

#endif