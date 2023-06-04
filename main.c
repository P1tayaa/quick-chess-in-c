
#include "chess.h"

void    print_string(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        write (1, &str[i], 1);
        i++;
    }
}

void	free_board(t_board_cell    **board);

void    kill_game(t_chess_game *chess_game)
{
    free_board(chess_game->board);
	free(chess_game);
}

char    *start_read_terminal();
t_chess_game    *make_chess_game(void);
bool player_manager(t_chess_game **chess_game);


int main(void)
{
    t_chess_game *chess_game;

    chess_game = make_chess_game();
    chess_game -> game_done = false;
    simple_print(chess_game);
    while (!chess_game -> game_done)
    {
        if (player_manager(&chess_game))
            simple_print(chess_game);
    }
    // input = start_read_terminal();
    kill_game(chess_game);
    return(0);
}
