/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:34:00 by dedme             #+#    #+#             */
/*   Updated: 2025/05/07 05:22:57 by dedme            ###   ########.fr       */
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

int	ft_exception(t_all_pile *pile)
{
	if (pile->a.count == 3)
	{
		ft_sort_three(&*pile);
		return (1);
	}
	else if (pile->a.count == 2)
	{
		write(1, "ra\n", 3);
		return (1);
	}
	else if (pile->a.count == 5)
	{
		ft_sort_five(&*pile);
		return (1);
	}
	return (0);
}

void	ft_sort(t_all_pile *pile)
{
	int	i;
	int	j;
	int	best;
	int	len;

	if (ft_exception(&*pile) == 1)
		return ;
	i = 0;
	j = 0;
	pile->len = pile->a.count;
	best = ft_find_better(&pile->a);
	len = ft_count_bits(best)+1;
	while (++j < len)
	{
		while (++i < pile->len)
		{
			if (ft_pick_bin(pile->a.pile[0], j) == 1)
				ra(&pile->a);
			else
				pb(&*pile);
		}
		while (pile->b.count > 0)
			pa(&*pile);
		i = -1;
	}
}
