/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:22:43 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/12 18:34:47 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
void ft_shear(t_map *Map)
{
	int x;
	int y;

	x = 0;
	y = 1;
	while (Map->size >>= 1)
		x++;
	while ((y * y) != x)
		y++;
	(y > Map->carrer;)
	
	
}
int bit_while(long int map, int carrer)
{
	long int x;
	int car;
	long int masque;
	int y = 64;

	x |= map;
	masque = 1;
	masque <<= y - 1;
	while (y-- != carrer)
	{
		masque >>= 1;
		if (masque & x)
			return(0);
	}
	return (1);
}

void	print_bits2(unsigned long int octet)
{
	long int	i =  2147483648;
	printf("bits :\n");
	while (i >>= 1)
		(octet & i) ? write(1, "1", 1) : write(1, "0", 1);
	printf("\n");
}
										
int ft_insert(t_piece *Piece, t_map *Map)
{
	int x;
	int y;
	y = 0;
	t_map *Ancre;
	Ancre = Map;

	x = Map->carrer * Map->carrer;
	while (bit_while(Map->size, x))
	{
		while ((Map->size ^ Piece->content) != Map->size + Piece->content)
			Piece->content <<= 1;
		if ((Map->size ^ Piece->content) == Map->size + Piece->content)
		{
			y = Map->size ^ Piece->content;
			ft_next_right_map(&Map);
			Map->size = y;
		}
	}
	Map = Ancre;
	return ((Map->size) ? 1 : 0);
}
void tracking(t_map *Map, t_piece *Piece)
{
	t_piece *Ancre;
	Ancre = Piece;

	while (Piece->next != NULL)
	{
		while(!(ft_insert(Piece, Map)))
			Map->carrer++;
		ft_next_piece(&Piece);
	}
	ft_shear(Map);
	printer(Map, Piece);
	printf("Le plus grand carrer : %d\n", Map->carrer);
}
























