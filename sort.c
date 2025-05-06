/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:34:00 by dedme             #+#    #+#             */
/*   Updated: 2025/05/06 09:20:16 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_pick_bin(int nb, int pos)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	if (pos == 0)
		return (0);
	while (i < pos - 1)
		nb = nb / 2 + (i++ *0);
	num = nb % 2;
	return (num);
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

int	ft_count_bits(int nb)
{
	int	bits;

	bits = 0;
	while ((nb >> bits) != 0)
		bits++;
	return (bits);
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
	t_len = pile->a.count;
	best = ft_find_better(&pile->a);
	len = ft_count_bits(best)+1;
	while (j < len)
	{
		while (++i < t_len)
		{
			if (ft_pick_bin(pile->a.pile[0], j) == 1)
				ra(&pile->a);
			else
				pb(&*pile);
		}
		while (pile->b.count > 0)
			pa(&*pile);
		j++;
		i = -1;
	}
}
