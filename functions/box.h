#ifndef __BOX_H__
#define __BOX_H__

void box_init(object *box, board *map);
int move_box(board *map, object *box, object *offset);

#endif