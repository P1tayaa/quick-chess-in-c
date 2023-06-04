
#include "chess.h"

void	set_pieces(t_chess_game **chess_game)
{
    int i;
    const char *peice = "rkbQKbkr";

    i = 0;
    while (i < (*chess_game) ->number_of_cell)
    {
        (*chess_game) ->board[0][i].piece = peice[i];
        (*chess_game) ->board[0][i].has_piece = true;
        (*chess_game) ->board[0][i].has_white_piece = false;
        i++;
    }
    while (i > -1)
    {
        (*chess_game) ->board[7][i].piece = peice[i];
        (*chess_game) ->board[7][i].has_piece = true;
        (*chess_game) ->board[7][i].has_white_piece = true;
        i--;
    }
    while (i < (*chess_game) ->number_of_cell - 1)
    {
        i++;
        (*chess_game) ->board[6][i].has_white_piece = true;
        (*chess_game) ->board[6][i].has_piece = true;
        (*chess_game) ->board[6][i].piece = 'i';
        (*chess_game) ->board[1][i].has_white_piece = false;
        (*chess_game) ->board[1][i].has_piece = true;
        (*chess_game) ->board[1][i].piece = 'i';
    }
}
