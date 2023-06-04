
#include "chess.h"

char	print_rkb(char	type, int x, int y)
{
	char const *rook = "\n:::::::::\n::|_|_|::\n:::| |:::\n:::| |:::\n::/___\\::";
	char const *knight = "\n:::::::::\n:::_,,:::\n::\"- \\~::\n:::| |:::\n::/___\\::";
	char const *bishop = "\n:::::::::\n:::(/):::\n:::| |:::\n:::| |:::\n::/___\\::";

	if (type == 'r')
		return (rook[(y * 9) + (1 + y) + x]);
	if (type == 'b')
		return (bishop[(y * 9) + (1 + y) + x]);
	if (type == 'k')
		return (knight[(y * 9) + (1 + y) + x]);
	return (':');
}
char	print_KiQ(char	type, int x, int y)
{
	char const *king = "\n:::_+_:::\n:::) (:::\n:::| |:::\n:::| |:::\n::/___\\::";
	char const *pone = "\n:::::::::\n:::( ):::\n:::) (:::\n::/___\\::\n:::::::::";
	char const *queen = "\n:::www:::\n:::) (:::\n:::| |:::\n:::| |:::\n::/___\\::";

	if (type == 'K')
		return (king[(y * 9) + (1 + y) + x]);
	if (type == 'i')
		return (pone[(y * 9) + (1 + y) + x]);
	if (type == 'Q')
		return (queen[(y * 9) + (1 + y) + x]);
	return (':');
}

void    simple_print(t_chess_game *chess_game)
{
	int 	i;
	int 	j;
	char	current_peice;
	bool	current_iswhite;

	i = 0;
	while (i < (chess_game -> number_of_cell) * 5)
	{
		j = 0;
		while (j < (chess_game -> number_of_cell) * 9)
		{
			current_peice = chess_game -> board[i / 5][j / 9].piece;
			current_iswhite = chess_game -> board[i / 5][j / 9].is_white;
			if (current_peice == 'O')
			{
				if (current_iswhite == true)
					print_string(" ");
				else
					print_string("#");
			}
			else 
			{
				if (current_peice == 'r' || current_peice == 'k' || current_peice == 'b')
					current_peice = print_rkb(current_peice, j % 9, i % 5);
				else if (current_peice == 'i' || current_peice == 'K' || current_peice == 'Q')
					current_peice = print_KiQ(current_peice, j % 9, i % 5);
				if (current_peice == ':')
				{
					if (current_iswhite == true)
						print_string(" ");
					else
						print_string("#");
				}
				else 
				{
					if (current_peice == ' ' && chess_game -> board[i / 5][j / 9].has_white_piece == false)
						current_peice = '@';
					write(1, &current_peice, 1);
				}
			}
			j++;
		}
		print_string("\n");
		i++;
	}
	
}
