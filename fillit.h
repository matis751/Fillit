/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 23:53:12 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/13 21:00:06 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include "../libft/includes/libft.h"

#define SHORT 0b0000000000000001
#define UL 1073741824
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
	 __uint128_t content;
	int pos[4];
	int haut;
	int larg;
	struct s_Piece *befor;
	struct s_Piece *next;
} t_piece ;

typedef struct s_Map
{
	 __uint128_t size;
	int carrer;
	int line;
	struct s_Map *befor;
	struct s_Map *left;
	struct s_Map *right;
} t_map ;

void ft_next_right_map(t_map **Map);
void ajuste(long int *bit);
void free_piece(t_piece **Piece);
void free_map(t_map **Map);
void ft_next_left_map(t_map **Map);
void ft_next_right_map(t_map **Map);
void ft_justnext_right(t_map **Map);
void ft_ajoute_map(t_map **Map);
int ft_compareversion2(char *buff);
int ft_bit_get_while(long int bit, int pos);
int ft_insert(t_piece *Piece, t_map *Map);
int ft_bit_get(long int *bit, int pos);
void ft_next_piece(t_piece **Piece);
int	ft_parametres_larg(t_piece *Piece);
int ft_parametres_haut(t_piece *Piece, t_map *Map);
int ft_valeur(int a, int b);
int bits(char *buff, t_piece *Piece);
int reader(char *av, t_piece **Piece, t_map *Map);
void ft_ajoute_piece(t_piece *Piece);
void ft_premiere_piece(t_piece **Piece);
void output(t_map *Map, t_piece *Piece);
void printer(t_map *Map, t_piece *Piece);
int ft_voisin(char **buff);
void ft_carrer(t_map *Map);
void tracking(t_map *Map, t_piece *Piece);
void ft_justnext_piece(t_piece **Piece);
void	print_bits2( __uint128_t octet);
t_map *creat_map(t_piece *Piece, t_map *Map);

#endif
