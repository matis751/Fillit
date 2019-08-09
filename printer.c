/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:21:57 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/09 15:22:37 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void printer(t_map *Map, t_piece *Piece, char c)
{
	int x;
	int y = Map->carrer;
	x = 1;
	long int	i = ULL;
	printf("\n");
	(Map->size & i) ? write(1, &c, 1) : write(1, ".", 1);
	while (i <<= 1)
	{
		if(x == Map->carrer)
		{
			if (y-- == 0)
				break;
			write (1, "\n", 1);
			x = 0;
		}
		x++;
		(Map->size & i) ? write(1, &c, 1) : write(1, ".", 1);
	}
	write(1, "\n", 1);
}
