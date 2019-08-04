/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 22:27:39 by mel-oual          #+#    #+#             */
/*   Updated: 2017/03/02 22:47:04 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tsrc;
	char	*tdst;
	size_t	i;

	i = -1;
	tsrc = (char *)src;
	tdst = (char *)dst;
	if (tsrc < tdst)
		while ((int)(--len) >= 0)
			*(tdst + len) = *(tsrc + len);
	else
		while (++i < len)
			*(tdst + i) = *(tsrc + i);
	return (dst);
}
