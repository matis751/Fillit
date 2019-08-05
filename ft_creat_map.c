/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 00:30:57 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/05 00:43:08 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_valeur(int a, int b)
{
	return (a > b ? a : b);
}

int ft_creat_map(t_piece *Piece)
{
	t_Map *Map;

	Map = (t_map *)malloc(sizeof(t_map));
	Map->min = ft_valeur(Piece->haut, Piece->larg) + 1;
	Map->carrer =  


	return (1);
}
