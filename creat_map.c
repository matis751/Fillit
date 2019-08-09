/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 00:30:57 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/09 14:47:01 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
void	print_bits3(unsigned long int octet)
{
	long int	i =  2147483648;
	printf("bits :\n");
	while (i >>= 1)
		(octet & i) ? write(1, "1", 1) : write(1, "0", 1);
	printf("\n");
}

int ft_valeur(int a, int b)
{
	return (a > b ? a : b);
}

t_map *creat_map(t_piece *Piece, t_map *Map)
{

	if (!(Map->carrer))
		Map->carrer = ft_valeur(Piece->haut, Piece->larg);
	print_bits3(Map->size);
	return (Map);
}
