/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_side.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 19:29:28 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/01 21:13:24 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int puissance (int *nb, int puissance)
{
	int x;
	x = *nb;
	while (puissance-- >= 2)
				*nb *= x;
		return (*nb);
}

int bits(buff) /*transforme ma piece en bit*/
{
	short int type_piece = 32767; 
	int x = 0 ;
	int position = 0;
	while (buff[x])
	{
		while (buff[x] != '#')
			x++;
		if (buff[x] == '#')
			position = puissance(2, (x - 1));
	


	}


}
