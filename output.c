/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:22:43 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/11 15:28:45 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


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

	x = Map->carrer * Map->carrer;
		while ((Map->size ^ Piece->content) != (Map->size + Piece->content))
			Piece->content<<= 1;
		if ((Map->size ^ Piece->content) == (Map->size + Piece->content))
			return (1);
	return (0);
}
void tracking(t_map *Map, t_piece *Piece)
{
	t_piece *Ancre;
	Ancre = Piece;

	while (Piece->next != NULL)
	{
		while (!(ft_insert(Piece, Map)))
		{
			Piece = Ancre;
			Map->carrer++;
			Map->size = 0;
		}
		Map->size ^= Piece->content;
		ft_next_piece(&Piece);
	}
	printer(Map, Piece);
	printf("Le plus grand carrer : %d\n", Map->line);
}
