/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:06:46 by dedme             #+#    #+#             */
/*   Updated: 2025/05/02 04:36:58 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void pa(t_all_pile *pile)
{
	int	tab[32];
	int	i;
	int	j;

	j = 0;
	i = 0;
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