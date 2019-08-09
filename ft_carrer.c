/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_carrer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 22:12:13 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/08 22:14:20 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
void ft_carrer(t_map *Map)
{
	long int x;
	x = Map->size;
	Map->carrer = 1;
	while(x >>= 4)
		Map->carrer++;
	printf("carrer = %d\n", Map->carrer);
}
