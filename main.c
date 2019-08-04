/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 19:11:28 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/01 19:11:42 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	piece_id(char *buff, t_piece **tetri)
{
	t_piece	*piece;
	int x;
	int line;

	piece = (t_piece *)malloc(sizeof(t_piece));
	x = 0;
	line = 0;
	piece = *tetri;
	while (buff[x])
	{
		if (buff[x] == '\n')
		{
			if (line)
			{
				piece->haut++;
				piece->larg = piece->larg > line ? piece->larg : line;
			}
			line = 0;
		}
		if (buff[x] == '#')
			line++;
		x++;
	}
}

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

t_piece	*read_file(int fd)
{
	int ret;
	int nb_piece;
	char *buff;
	t_piece *piece;

	ret = 0;
	nb_piece = 0;
	buff = ft_strnew(1000);
	if (!(piece = (t_piece *)malloc(27 * sizeof(t_piece))))
		return (NULL);
	while ((ret = read(fd, buff, BUFF)) > 0)
	{
		buff[BUFF - 1] = '\0';
		if (!(verif_line(buff) && verif_forme(buff, piece)))
			return (NULL);
		nb_piece++;
	}
	return (piece);
}

int	main(int ac, char **av)
{
	int ret;
	t_piece *piece;

	ret = 0;
	if (ac != 2 || !(piece = read_file(open(av[1], O_RDONLY))))
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_putstr("OK");
	return (1);
}
