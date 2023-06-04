
#include "chess.h"

t_board_cell    **make_board()
{
	t_board_cell    **board;
	int				i;
	int				j;

	board = (t_board_cell **)malloc(9 * sizeof(t_board_cell *));
	if (!board)
		return(NULL);
	i = 0;
	while (i < 8)
	{
		board[i] = (t_board_cell *)malloc(9 * sizeof(t_board_cell));
		j = 0;
		while (j < 8)
		{
			if ((i + j) % 2 == 1)
				board[i][j].is_white = true;
			else 
				board[i][j].is_white = false;
			board[i][j].piece = 'O';
			board[i][j].has_piece = false;
			j++;
		}
		i++;
	}
	return (board);
}

void	free_board(t_board_cell    **board)
{
	int				i;

	i = 0;
	while (i < 8)
	{
		free(board[i]);
		i++;
	}
	free(board);
}

void	set_pieces(t_chess_game **chess_game);

t_chess_game    *make_chess_game(void)
{
	t_chess_game    *chess_game;

	chess_game = malloc(sizeof(t_chess_game));
	if (! chess_game)
		return (NULL);
	chess_game -> number_of_cell = 8;
	chess_game -> curent_player = 0;
	chess_game->board = make_board();
	if (! chess_game->board)
		return (free(chess_game),NULL);
	set_pieces(&chess_game);
	simple_print(chess_game);
	free_board(chess_game->board);
	free(chess_game);
}
