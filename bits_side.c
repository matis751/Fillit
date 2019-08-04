/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_side.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 19:29:28 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/04 16:36:27 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int en_bit (int position, unsigned char *piece_bit)
{
	*position -= 1;
	*piece_bit |= nb;
}

int bits(buff) /*transforme ma piece en bit*/
{
	unsigned char piece_bit = SHORT; 
	int x = 0 ;
	int position = 0;
	while (buff[x])
	{
		if (buff[x] == '#')
			en_bit(x, &piece_bit);
		x++;
	}
	pint_bits(piece_bit)
	return (1);
}
