/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 23:53:12 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/09 16:05:38 by mel-oual         ###   ########.fr       */
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
	int haut;
	int larg;
	struct s_Piece *befor;
	struct s_Piece *next;
	char l;
} t_piece ;

typedef struct s_Map
{
	int carrer;
	long int size : 64;
} t_map ;

int ft_compareversion2(char *buff);
int ft_valeur(int a, int b);
void ft_ajoute(t_piece *Piece);
void printer(t_map *Map, t_piece *Piece, char c);
int ft_voisin(char **buff);
void ft_carrer(t_map *Map);
int tracking(t_piece *Piece, t_map *Map);
void	print_bits3(unsigned long int octet);
t_map *creat_map(t_piece *Piece, t_map *Map);

#endif
