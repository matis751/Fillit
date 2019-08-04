/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:28:05 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/05 00:30:03 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

int ft_parametres_haut(t_piece *Piece)
{
	int x;
	Piece->verif = VERIF;
	x = Piece->content;
	Piece->haut = 1;
	while (x >>= 5)
			Piece->haut++;
	printf("Hauteur = %d\n", Piece->haut);
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
			x >>= 5;
		}
		if (!(Piece->larg))
			Piece->larg++;
		printf("largeur = %d\n", Piece->larg);
		ft_parametres_haut(Piece);
		return (1);
}

void	print_bits2(unsigned long int octet)
{
	long int	i =  2147483648;
	printf("bits :\n");
	while (i >>= 1)
		(octet & i) ? write(1, "1", 1) : write(1, "0", 1);
	printf("\n");
}

void en_bit (int position, unsigned int *piece_bit)
{
	int x;

	*piece_bit <<= position;
	*piece_bit |= 1 ;
	
}

int bits(char *buff, t_piece *Piece) /*transforme ma piece en bit*/
{
	unsigned int piece_bit = SHORT;
	int y = 0;
	char *tmp;
	char *tmp2;
	int espace = 0;
	
	while (y != 3)
	{
		tmp = ft_strchr(buff, '#');
		tmp2 = ft_strchr (tmp + 1, '#');
		espace = tmp2 - tmp;
		en_bit(espace, &piece_bit);
		buff = tmp2;
		y++;
	}
	Piece->content = piece_bit;
	return (1);
}

int main(int ac, char **av)
{
	int fd;
	int ret;
	char *buff;
	t_piece *Ancre;
	t_piece *Piece;
	Piece = (t_piece *)malloc(sizeof(t_piece));
	Ancre = Piece;

	ret = 0;
	buff = ft_strnew(21);
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while ((ret = read(fd, buff, 21)) > 0)
		{
			bits(buff, Piece);
			print_bits2(Piece->content);
			ft_parametres_larg(Piece);
			Piece->befor = Piece;
			Piece->next = (t_piece *)malloc(sizeof(t_piece));
			Piece = Piece->next;
		}
		Piece = Ancre;
	}
	return (1);
}
