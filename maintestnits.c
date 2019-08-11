/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:37:11 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/11 16:02:23 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 #include <stdio.h>
#include "fillit.h"


void	print_bits2(unsigned long int octet)
{
	long int	i =  2147483648;
	printf("bits :\n");
	while (i >>= 1)
		(octet & i) ? write(1, "1", 1) : write(1, "0", 1);
	printf("\n");
}

int long ft_reverse(int long bit)
{
	int i = -1;
	int long masque;
	int long ret;
	int count;

	count = 0;
	ret = 0;
	masque = ULL;
	while (i++ < 64)
		{
			if(masque & bit)
			{
				ret +=1;
			}
			else
				masque >>= 1;
		}
	return (bit);



}
int main()
{
	long int x;
	long int ret;

	ret = 0;
	x = 275;
	printf("avant x = \n");
	print_bits2(x);
	ret = ft_reverse(275);
	printf("ret = %ld\n", ret);
	printf("en reverse\n");
	print_bits2(ret);
	return (1);
}
