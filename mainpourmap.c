/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:28:05 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/12 14:54:21 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ajuste(long int *bit)
{
	long int masque;
	masque = 1;
	while(!(masque & *bit))
		*bit >>= 1;
}
int ft_parametres_haut(t_piece *Piece, t_map *Map)
{
	int x;
	int y;
	Piece->verif = VERIF;
	x = Piece->content;
	Piece->haut = 1;
	while (x >>= 4)
			Piece->haut++;
	printf("Hauteur = %d\n", Piece->haut);
	y = ft_valeur(Piece->haut, Piece->larg);
	y > Map->carrer ? Map->carrer = y : Map->carrer ;
	return (0);
}

int	ft_parametres_larg(t_piece *Piece)
{
	int x;
	Piece->larg = 0;
	Piece->verif = VERIF; /*15*/

		x = Piece->content;
		while (x != 0)
		{
			Piece->size |= x;
			if (Piece->size % 4 == 3)
				while (Piece->verif >>= 1)
					if (Piece->verif == Piece->size)
					{
						Piece->larg++;
						Piece->size >>= 1;
					}
			x >>= 4;
		}
		if (!(Piece->larg))
			Piece->larg++;
		printf("largeur = %d\n", Piece->larg);
		return (1);
}

void en_bit (int position, long int *piece_bit)
{	
	static int x;
	int b = 1;
	x += position;
	while (b++ != x)
		(16 % b) == 0  && b != 2 ? position-- : b ;
	*piece_bit >>= position;
	*piece_bit |= UL;
	x = 0;

}

int bits(char *buff, t_piece *Piece) /*transforme ma piece en bit*/
{
	long int piece_bit = UL;
	int y = 0;
	char *tmp;
	char *tmp2;
	int espace = 0;
	
	while (y != 3)
	{
		tmp = ft_strchr(buff, '#');
		tmp2 = ft_strchr (tmp + 1, '#');
		espace = tmp2 - tmp;
		printf("espace = %d\n", espace);
		en_bit(espace, &piece_bit);
		buff = tmp2;
		y++;
	}
	ajuste(&piece_bit);
	Piece->content = piece_bit;
	printf("Valeur de la piece : %ld\n", Piece->content);
	printf("Valeur en bit : \n");
	print_bits2(Piece->content);
	return (1);
}

int main(int ac, char **av)
{
	t_map *Map;
	t_piece *Piece;
	t_piece *Ancre;
	Piece = (t_piece *)malloc(sizeof(t_piece));
	Map = (t_map *)malloc(sizeof(t_map));
	ft_premiere_piece(Piece);
	ft_ajoute_map(&Map);
	Ancre = Piece;

	reader(av[1], &Piece, Map);
	Piece = Ancre;
	tracking(Map, Piece);
	return (1);
}
