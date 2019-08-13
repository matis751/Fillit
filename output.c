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
	while (Map->right)
	{
		while (Map->size >>= 1)
			x++;
		while ((y * y) < x)
			y++;
		(Map->carrer < y ? Map->carrer = y : Map->carrer);
		Map->befor= Map;
		Map = Map->right;
	}
	
}
int bit_while(long int map, int carrer)
{
	long int x;
	int car;
	long int masque;
	int y = 64;

	x = map;
	masque = 1;
	masque <<= carrer - 1;
	while (masque <<= 1)
	{
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
	int ret;
	long int m;
	m = Map->size;
	ret = 0;
	y = 0;
	t_map *Ancre;
	Ancre = Map;

	x = Map->carrer * Map->carrer;
	while(Piece->next)
	{
		while ((ret = bit_while(m, x)))
		{
			if ((Map->size ^ Piece->content) == Map->size + Piece->content)
			{
				y = Map->size ^ Piece->content;
				printf("y = %d\n", y);
				Map->size = y;
				print_bits2(y);
				m = Map->size;
				if (Map->right == NULL)
					ft_next_right_map(&Map);
				else 
					ft_justnext_right(&Map);
			}
				Piece->content <<= 1;
		}
		if (!(bit_while(Piece->content, x)))
			Map->carrer++;
		Map = Ancre;
		ft_justnext_piece(&Piece);
	}
	Map = Ancre;
	return (!(ret) ? 1 : 0);
}
void tracking(t_map *Map, t_piece *Piece)
{
	t_piece *Ancre;
	Ancre = Piece;
	ft_insert(Piece, Map);
	ft_shear(Map);

	printer(Map, Piece);
	printf("Le plus grand carrer : %d\n", Map->carrer);
}
























