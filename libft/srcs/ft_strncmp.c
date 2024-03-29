/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:45:12 by mel-oual          #+#    #+#             */
/*   Updated: 2017/03/04 20:56:48 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n < 1)
		return (0);
	while (s1[i] != '\0' && i < (n - 1) && s1[i] == s2[i])
		i++;
	return (*((unsigned char*)s1 + i) - *((unsigned char*)s2 + i));
}
