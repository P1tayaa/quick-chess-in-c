
#include "chess.h"

bool    vallid_player_input(char *str)
{
    if (str == NULL)
        return (false);
    if (strlen(str) != 6)
        return(print_string("not 5 char\n"), false);
    if (str[0] < 'A' || str[0] > 'H')
        return(print_string("first letter wrong\n"), false);
    if (str[1] < '1' || str[1] > '8')
        return(print_string("second number wrong\n"), false);
    if (str[2] != ' ')
        return(print_string("third letter not space\n"), false);
    if (str[3] < 'A' || str[3] > 'H')
        return(print_string("forth letter wrong\n"), false);
    if (str[4] < '1' || str[4] > '8')
        return(print_string("fifth number wrong\n"), false);
    return (true);
}

char    *start_read_terminal();
bool    move_peice(t_coordinates from, t_coordinates to, t_board_cell ***board);
t_coordinates   get_piece_of(char *input);

bool player_manager(t_chess_game **chess_game)
{
    char player;
    char *input;

    if ((*chess_game) -> curent_player == 0)
        player = 'W';
    else 
        player = 'B';
    printf("player %c it is your turn, what are you playing?\n(exemple of input: \"E2 E4\" will move the pone by 2)\n",
        player);
    while (1 == 1)
    {
        input = start_read_terminal();
        if (vallid_player_input(input))
            break;
        print_string("invalid input\n");
    }
    printf("%d, %d\n %d, %d\n", get_piece_of(input).x, get_piece_of(input).y, get_piece_of(&input[3]).x,  get_piece_of(&input[3]).y);
    move_peice(get_piece_of(input), get_piece_of(&input[3]), &(*chess_game)->board);
    return (true);
}
