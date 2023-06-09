
#include "chess.h"

t_coordinates   get_piece_of(char *input)
{
    t_coordinates    coordinate;

    coordinate.x = input[0] - 'A';
    coordinate.y = 7 - (input[1] - '1');
    return (coordinate);
}

bool    move_peice(t_coordinates from, t_coordinates to, t_board_cell ***board)
{
    printf("%d", (*board)[from.y][from.x].has_piece);
    if (!(*board)[from.y][from.x].has_piece)
        return (false);
    if ((*board)[to.y][to.x].has_piece)
    {
        print_string("the piece ");
        write(1, &((*board)[to.y][to.x].piece), 1);
        print_string(" ");
        if ((*board)[to.y][to.x].has_white_piece)
            print_string("W killed\n");
        else
            print_string("B killed\n");
    }
    (*board)[to.y][to.x].has_piece = true;
    (*board)[from.y][from.x].has_piece = false;
    (*board)[to.y][to.x].has_white_piece = (*board)[from.y][from.x].has_white_piece;
    (*board)[to.y][to.x].piece = (*board)[from.y][from.x].piece;
    (*board)[from.y][from.x].piece = 'O';
    return (true);
}
