/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:22:43 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/13 23:21:31 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <limits.h>
void setbit(__uint128_t *bit, int pos[])
{
	int x;
	__uint128_t masque;
	masque = 1;
	x = 0;
	while(x != 4)
		*bit |= (masque << (pos[x++] - 1));
}
int getbit(__uint128_t bit, int pos[])
{
	int x;
	__uint128_t masque;
	masque = 1;
	x = 0;
	while(x != 4)
	{
		if (masque << (pos[x] - 1) & bit)
			return(0);
		x++;
	}
	return (1);
}
void pos_bit( __uint128_t bit, t_piece *Piece)
{
	 __uint128_t masque;
	 int nbre;
	 int x;
	 int position;

	 position = 0;
	 nbre = 0;
	 x = 0;
	 masque = 1;
	 while(nbre != 4)
	 {
		position++;
		if(masque & bit)
		{
			nbre++;
			Piece->pos[x++] = 128 - (128 - position);
		}
		masque <<= 1;
	}
}
	
int count_bit( __uint128_t bit)
{
	 __uint128_t masque;
	long int x;
	x = 0;
	masque = 1;
	while(masque != 0)
	{
		(masque & bit) ? x++ : x;
		masque <<= 1;
	}
	printf("Le nombre de bit = %ld\n", x);
	return (1);
}

int first_bit( __uint128_t bit)
{
	int x;
	 __uint128_t masque;
	masque = 1;
	masque <<= 127;
	x = 1;
	while (!((masque >>= 1) & bit))
		x++;
	return (128 - x);
}
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
		(Map->carrer > y ? Map->carrer = y : Map->carrer);
		Map->befor= Map;
		Map = Map->right;
	}
	
}
int bit_while(long int map, int carrer)
{
	 __uint128_t x;
	 __uint128_t masque;

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

void	print_bits2( __uint128_t octet)
{
	 __uint128_t	i =  1;
	i <<= 127;
	printf("bits :\n");
	while (i >>= 1)
		(octet & i) ? write(1, "1", 1) : write(1, "0", 1);
	printf("\n");
}
										
int ft_insert(t_piece *Piece, t_map *Map)
{
	int x;
	int ret;
	int v = 0;
	int first = 0;
	int first1 = 0;
	__uint128_t y;
	first = 0;
	ret = 0;
	t_map *Ancre;
	Ancre = Map;

	while(Piece->next)
	{
		while((first = first_bit(Piece->content)) < 127)
		{
			pos_bit(Piece->content, Piece);
			if (getbit(Map->size, &Piece->pos[0]))
			{
				setbit(&Map->size, &Piece->pos[0]);
				Piece->content = y;
				printf("La Map Apres en bits :\n");
				print_bits2(Map->size);
				count_bit(Map->size);
				if (Map->right == NULL)
				{
					printf("vouvelle brnqche\n");
					ft_next_right_map(&Map);
				}
				else{ 
					printf("justnext\n");
					ft_justnext_right(&Map);
				}
			}
			printf("La Piece en bits :\n");
			print_bits2(Piece->content);
			y = Piece->content;
			Piece->content <<= 1;
		}
		v++;
		printf("!!!!le nombre de Piece = %d!!!!\n\n", v);
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
	printf("Le plus petit carrer : %d\n", Map->carrer);
}
























