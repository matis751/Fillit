/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 20:05:21 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/01 20:21:09 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int print_bit(unsigned int a)
{
	int x = 256;
	while (x >>= 1)
		(a & x) ? write (1, "1", 1) : write (1, "0", 1);
	return (1);
}

int main(int a, char **b)
{
	if (a == 2)
		print_bit(**b);
	return (0);
}
