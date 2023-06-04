
#include "chess.h"

t_coordinates   get_piece_of(char *input)
{
    t_chess_game    coordinate;

    coordinate.y = input[0] - 'A' + 1;
    coordinate.x = input[1] - '0';
    return (coordinate);
}


