/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 19:11:28 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/15 21:38:26 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int	verif_line(char *buff)
{
	int x;
	int nb_lines;

	x = 0;
	nb_lines = 0;
	while (buff[x])
	{
		if ((buff[x] != '.' && buff[x] != '#' && buff[x] != '\n'))
			return (0);
		if (buff[x] == '\n')
		{
			if (x % 5 != 4)
				return (0);
			nb_lines++;
		}
		x++;
	}
	return (nb_lines == 4 ? 1 : 0);
}

int	verif_forme(char *buff, t_piece *piece)
{
	int x;
	int block;

	x = 0;
	block = 0;
	while (buff[x] && buff[x] != '#')
		x++;
	while (buff[x])
	{
		if (buff[x] == '#' && (buff[x + 1] == '#' && buff[x + 5] == '#'))
			piece->collision += 4;
		else if (buff[x] == '#' && (buff[x + 1] == '#' || buff[x + 5] == '#'))
			piece->collision += 2;
		if (buff[x] == '#')
			block++;
		x++;
	}
	if (block == 4 && (piece->collision == 6 || piece->collision == 8))
		return (1);
	return (0);
}

t_piece	*read_file(int fd, int nb_piece)
{
	int ret;
	char *buff;
	t_piece *ancre;
	t_piece *piece;

	ret = 0;
	buff = ft_strnew(21);
	piece = (t_piece *)malloc(sizeof(t_piece));
	initialise_piece(piece);
	ancre = piece;
	while ((ret = read(fd, buff, BUFF)) > 0)
	{
		buff[BUFF - 1] = '\0';
		if (!(verif_line(buff) && verif_forme(buff, piece)))
			return (NULL);
		new_piece(&piece);
		nb_piece++;
		free(buff);
		buff = ft_strnew(21);
	}
	return ((ret < 0) ? NULL : ancre);
}
