
#include "fillit.h"

void free_map(t_map **TMap)
{
	t_map *tmp;
	t_map *Map;

	Map = *TMap;
	while(Map)
	{
		tmp = Map->right;
		free(Map);
		Map = tmp;
	}
	free(tmp);
	*TMap = Map;
}

void free_piece(t_piece **TPiece)
{
	t_piece *tmp;
	t_piece *Piece;
	
	Piece = *TPiece;
	while(Piece)
	{
		tmp = Piece->next;
		free(Piece);
		Piece = tmp;
	}
	free(tmp);
	*TPiece = Piece;
}
