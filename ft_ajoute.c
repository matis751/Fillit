/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ajoute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:04:16 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/12 14:38:05 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_ajoute_piece(t_piece *Piece)
{

	ft_next_piece(&Piece);
	ft_premiere_piece(Piece);
}
void ft_ajoute_map(t_map **Map)
{
	t_map *Tmp_Map;

	Tmp_Map->carrer = 0;
	Tmp_Map->line = 0;
	Tmp_Map->size = 0;
	Tmp_Map->right = NULL;
	Tmp_Map->left = NULL;
	
	*Map = Tmp_Map;
}
void ft_next_right_map(t_map **Map)
{
	
	t_map *Tmp_Map;

	Tmp_Map->right = (t_map *)malloc(sizeof(t_map));
	Tmp_Map = *Map;
	Tmp_Map->befor= Tmp_Map;
	Tmp_Map = Tmp_Map->right;
	ft_ajoute_map(&Tmp_Map);

	*Map = Tmp_Map;
}

void ft_next_left_map(t_map **Map)
{
	
	t_map *Tmp_Map;

	Tmp_Map->left = (t_map *)malloc(sizeof(t_map));
	Tmp_Map = *Map;
	Tmp_Map->befor= Tmp_Map;
	Tmp_Map = Tmp_Map->left;
	ft_ajoute_map(&Tmp_Map);

	*Map = Tmp_Map;
}

void ft_next_piece(t_piece **Piece)
{
	t_piece *Tmp_Piece;

	Tmp_Piece = *Piece;
	Tmp_Piece->befor= Tmp_Piece;
	Tmp_Piece = Tmp_Piece->next;

	*Piece = Tmp_Piece;
}

void ft_premiere_piece(t_piece *Piece)
{
	Piece->size = 0;
	Piece->verif = 0;
	Piece->haut = 0;
	Piece->larg = 0;
	Piece->content = ULL;
	Piece->next = NULL;
}
