/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:21:57 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/12 18:42:43 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int get_bit(long int bit, int position)
{
	long int masque;
	masque = 1;
	masque <<= position;
	return(masque & bit);

}
void printer(t_map *Map, t_piece *Piece)
{
	char *c;
	int y;
	int x;
	char tmp;

	y = 0;
	x = 0;
	c = ft_strnew(21 * 26);
	Map->size <<= 1;
	while(Map->size >>= 1)
	{
		if(x & Map->size)
			c[y] = 'A';
		else if(!(x & Map->size))
			c[y] = '.';
		if (!(y % Map->carrer) && y != 0)
		{
			tmp = c[y];
			c[y] = '\n';
			y++;
			c[y] = tmp;
		}
		y++;
	}
	y = 0;
	while (c[y])
	{
		write(1, &c[y], 1);
		y++;
	}
}


