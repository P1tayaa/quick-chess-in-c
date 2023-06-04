

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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
		bool	game_done;
		t_board_cell	**board;
		int				number_of_cell;
		int				curent_player;
}		t_chess_game;

typedef struct s_coordinates
{
	int	x;
	int	y;
}		t_coordinates;

void    print_string(char *str);

void    simple_print(t_chess_game *chess_game);
