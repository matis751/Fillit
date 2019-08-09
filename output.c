/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:22:43 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/09 16:41:40 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void output(t_map *Map, t_Piece *Piece)
{
	while (Piece->next != NULL)
	{
		while (!(tracking(Piece, Map)))
			Map->carrer++;
		Piece->befor = Piece;
		Piece = Piece->next;
	}
	printer(Map, Piece, c)
}
