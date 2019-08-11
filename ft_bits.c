/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:37:11 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/11 13:54:28 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_bit_get(long int *bit, int pos)
{
	unsigned char masque;
	int i;

	i = -1;
	masque = 0x80;
	while(i++ < (pos % 64))
		masque >>= 1;
	return (masque && bit[int(pos / 64)] == masque ? 1 : 0);
}

int ft_bit_get_While(long int *bit, int pos)
{
	unsigned char masque;
	int i;

	i = -1;
	masque = 0x80;
	while((pos % 64))
	{
		(masque & bit[int(pos / 64)] == masque ? 1 : 0);
		masque >>= 1;
	}
	return (masque & bit[int(pos / 64)] == masque ? 1 : 0);
}

int ft_bit_set(const unsigned char *bit, int pos, int etat)
{
	unsigned char masque;
	int i;

	i = -1;
	masque = 0x80;
	while(i++ < (pos % 8))
		masque >>= 1;
	if(etat)
		return (bits[pos / 8] |= masque); 
	else
		return (bits[pos / 8] &= (~masque));
	return (0);
}
int ft_XOR(const unsigned char *bit1, const unsigned char *bit2, const unsigned
		char bitx, int taille)
{
	int i;

	i = -1;
	while (i++ < taille)
	{
		if (ft_bit_get(bit1, i) != ft_bit_get(bit2, i))
			ft_bit_set(bitx, i, 1);
		else
			ft_bit_set(bitx, i, 0);
	}
	return (bitx)
}

int ft_bit_rot_left(unsigned char *bit, int taille, int nbre)
{
	int fbit;
	int lbit;
	int i;
	int j;

	j = -1;
	i = -1;
	fbit = 0;
	lbit = 0;

	if (taille > 0)
	{
		while (j++ < nbre)
		{
			while (i++ <= ((taille - 1) / 8))
			{
				lbit = ft_bit_get(&bits[i], 0);
				if(i == 0)
					fbit = lbit;
				else
					ft_bit_set(&bit[i - 1], 7, lbit);
				bit[i] == bit[i] << 1;
			}
			ft_bit_set(bit, taille - 1, fbit);
		}
	}
	return (bit);
}

