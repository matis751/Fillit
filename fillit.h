/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 23:53:12 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/01 19:15:43 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../libft/includes/libft.h"

#define LINE 5
#define BUFF 21

int ft_compareversion2(char *buff);
int ft_voisin(char **buff);

typedef struct s_liste
{
	int value;
	int niveau;
	char *position;
	char *parent;
	char *fils;
} t_liste ;

typedef struct s_Piece
{
	int collision;
	int line;
	int haut;
	int larg;
	int col;
} t_piece ;

typedef struct s_Map
{
	int collision;
	int haut;
	int larg;
} t_map ;
#endif
