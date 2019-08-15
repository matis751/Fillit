/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:33:27 by mel-oual          #+#    #+#             */
/*   Updated: 2017/03/04 02:26:42 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int i;
	int j;

	i = 0;
	if (s == NULL || *f == NULL)
		return ;
	j = ft_strlen(s);
	while (i < j)
	{
		(*f)(i, s + i);
		i++;
	}
}
