

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include <stdio.h>

typedef struct	s_board_cell
{
	bool	is_white;
	bool	has_piece;
	bool	has_white_piece;
	char	piece;
}		t_board_cell;

typedef struct	s_chess_game
{
		t_board_cell	**board;
		int				number_of_cell;
		int				curent_player;
}		t_chess_game;

void    print_string(char *str);

void    simple_print(t_chess_game *chess_game);
