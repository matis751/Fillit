/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ajoute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:04:16 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/09 16:19:00 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_ajoute_Piece(t_piece *Piece);
{

	Piece->befor = Piece;
	Piece = Piece->next;
	ft_premiere_piece(Piece);
}

void ft_premiere_piece(t_piece *Piece)
{
	if (Piece)
		Piece = (t_piece *)malloc(sizeof(t_piece));
	Piece->size = 0;
	Piece->verif = 0;
	Piece->haut = 0;
	Piece->larg = 0;
	Piece->content = 0;
	Piece->next = NULL;
}
