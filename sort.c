/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:34:00 by dedme             #+#    #+#             */
/*   Updated: 2025/05/06 01:06:41 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_pick_bin(int nb, int pos)
{
	return ((nb >> (pos - 1)) & 1);
}

int	ft_find_better(t_pile *pile)
{
	int	i;
	int	best;

	i = 0;
	best = pile->pile[0];
	while (i < pile->count)
	{
		if (pile->pile[i] > best)
			best = pile->pile[i];
		i++;
	}
	return (best);
}

void	ft_sort(t_all_pile *pile)
{
	int	i;
	int	j;
	int	best;
	int	len;
	int	t_len;

	i = 0;
	j = 1;
	len = 0;
	t_len = pile->a.count;
	best = ft_find_better(&pile->a);
	while (j < 32)
	{
		if (ft_pick_bin(best, j) == 1)
			len = j;
		j++;
	}
	j = 1;
	while (j <= len)
	{
		while (i < t_len)
		{
			if (ft_pick_bin(pile->a.pile[0], j) == 1)
			{
				ra_rb(&pile->a.pile[0]);
				write(1, "ra\n", 3);
			}
			else
			{
				pb(&*pile, &pile->error);
				if (pile->error != 0)
					return ;
				write(1, "pb\n", 3);
			}
			i++;
		}
		while (pile->b.count > 0)
		{
			write(1, "pa\n", 3);
			pa(&*pile, &pile->error);
		}
		i = 0;
		j++;
	}
}
