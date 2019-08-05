/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 23:53:12 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/05 00:43:12 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../libft/includes/libft.h"

#define SHORT 0b0000000000000001
#define ULL -9223372036854775807
#define VERIF 15
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
	unsigned int size : 4;
	unsigned int verif : 4;
	int content;
	int collision;
	int line;
	int haut;
	int larg;
	struct s_Piece *befor;
	struct s_Piece *next;
} t_piece ;

typedef struct s_Map
{
	int min;
	long long int size_map : 64;
	int collision;
	int haut;
	int larg;
} t_map ;
#endif
