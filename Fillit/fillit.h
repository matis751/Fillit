/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:12:12 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/15 20:53:57 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include "libft/includes/libft.h"

#define BUFF 21

typedef struct		s_positon
{
		u_int16_t	p3;
		u_int16_t	p2;
		u_int16_t	p1;
		u_int16_t	p0;
}							t_position;

union				u_map
{
	u_int64_t		map;
	t_position		position;
};

typedef struct		s_piece
{
	int			x;
	int			y;
	int			larg;
	int			haut;
	int 		collision;
	struct s_piece	*befor;
	struct s_piece	*next;
	union u_map	value;
}					t_piece;
/*createur*/
void new_piece(t_piece **piece);
void initialise_piece(t_piece *piece);
void next_piece(t_piece **piece);
/*check_piece*/
int	verif_forme(char *buff, t_piece *piece);
int	verif_line(char *buff);
t_piece	*read_file(int fd, int nb_piece);
void	piece_id(char *buff, t_piece **tetri);

#endif
