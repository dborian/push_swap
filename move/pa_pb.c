/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:06:46 by dedme             #+#    #+#             */
/*   Updated: 2025/05/05 09:23:09 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void pa(t_all_pile *pile, int *error)
{
	int	*tab;
	int	i;
	int	j;

	j = 0;
	i = 0;
	tab = malloc(sizeof(int) * pile->a.count);
	if (!tab)
		error_write_return(1, error);
	while (i < pile->a.count)
		tab[j++] = pile->a.pile[i++];
	i = 1;
	j = 0;
	pile->a.pile[0] = pile->b.pile[0];
	while (i < pile->a.count)
		pile->a.pile[i++] = tab[j++];
	pile->a.count++;
	i = 1;
	j = 0;
	while (i < pile->b.count)
	{
		pile->b.pile[j++] = pile->b.pile[i++];
	}
	pile->b.count--;
	free(tab);
}

void pb(t_all_pile *pile)
{
	int	tab[32];
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < pile->b.count)
		tab[j++] = pile->b.pile[i++];
	i = 1;
	j = 0;
	pile->b.pile[0] = pile->a.pile[0];
	while (i < pile->b.count)
		pile->b.pile[i++] = tab[j++];
	pile->b.count++;
	i = 1;
	j = 0;
	while (i < pile->a.count)
	{
		pile->a.pile[j++] = pile->a.pile[i++];
	}
	pile->a.count--;
}