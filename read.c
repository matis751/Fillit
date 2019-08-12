/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 07:35:23 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/12 14:21:59 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int reader(char *av, t_piece **TPiece, t_map *Map)
{
	int fd;
	t_piece *Piece;
	char *buff;
	int ret;

	ret = 0;
	Piece = *TPiece;
	fd = open(av, O_RDONLY);
	buff = ft_strnew(21);
	if (fd < 1 || buff == NULL)
		return (0);
	while ((ret = read(fd, buff, 21)) > 0)
	{
		Piece->next = (t_piece *)malloc(sizeof(t_piece));
		bits(buff, Piece);
		ft_parametres_larg(Piece);
		ft_parametres_haut(Piece, Map);
		Map->carrer = ft_valeur(Map->carrer,(ft_valeur(Piece->larg, Piece->haut)));
		ft_next_piece(&Piece);
		free(buff);
		buff = ft_strnew(21);
	}
	Map->line = Map->carrer;
	free(buff);
	*TPiece = Piece;
	return (ret >= 0 ? 1 : 0);
}
