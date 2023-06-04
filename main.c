
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

t_chess_game    *make_chess_game(void);

int main(void)
{
    t_chess_game *chess_game;

    chess_game = make_chess_game();
    return(0);
}
