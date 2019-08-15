/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:41:29 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/15 21:41:05 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	int ret;
	int fd;
	int nb_piece;
	t_piece *piece;

	ret = 0;
	nb_piece = 0;
	fd = open(av[1], O_RDONLY);
	if (ac != 2 || !(piece = read_file(fd, nb_piece)))
	{
		ft_putstr("error\n");
		return (0);
	}
	return (1);
}
