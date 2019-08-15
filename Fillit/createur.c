/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:37:22 by mel-oual          #+#    #+#             */
/*   Updated: 2019/08/15 20:46:19 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void new_piece(t_piece **piece)
{
	t_piece *tpiece;

	tpiece = *piece;
	tpiece->next = (t_piece *)malloc(sizeof(t_piece));
	next_piece(&tpiece);
	initialise_piece(tpiece);
	*piece = tpiece;
}

void initialise_piece(t_piece *tpiece)
{

	tpiece->x = 0;
	tpiece->y = 0;
	tpiece->larg = 0;
	tpiece->haut = 0;
	tpiece->collision = 0;
	tpiece->next = NULL;

}
void next_piece(t_piece **piece)
{
	t_piece *tmp;
	t_piece *tpiece;

	tpiece = *piece;
	tmp = tpiece;
	tpiece = tpiece->next;
	if(tmp)
		tpiece->befor = tmp;
	*piece = tpiece;
}
