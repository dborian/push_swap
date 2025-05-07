/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_exception.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 04:10:06 by dedme             #+#    #+#             */
/*   Updated: 2025/05/07 04:15:35 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_all_pile *pile)
{
	int	*p;

	p = pile->a.pile;
	if (p[0] > p[1] && p[1] < p[2] && p[0] < p[2])
	{
		write(1, "sa\n", 3);
	}
	else if (p[0] > p[1] && p[1] > p[2])
	{
		write(1, "sa\n", 3);
		write(1, "rra\n", 4);
	}
	else if (p[0] > p[1] && p[1] < p[2] && p[0] > p[2])
	{
		write(1, "ra\n", 3);
	}
	else if (p[0] < p[1] && p[1] > p[2] && p[0] < p[2])
	{
		write(1, "sa\n", 3);
		write(1, "ra\n", 3);
	}
	else if (p[0] < p[1] && p[1] > p[2] && p[0] > p[2])
	{
		write(1, "rra\n", 4);
	}
}

int	ft_find_min(t_pile *pile)
{
	int	i;
	int	min;

	i = 1;
	min = pile->pile[0];
	while (i < pile->count)
	{
		if (pile->pile[i] < min)
			min = pile->pile[i];
		i++;
	}
	return (min);
}

int	ft_find_pos(t_pile *pile, int val)
{
	int	i;

	i = 0;
	while (i < pile->count)
	{
		if (pile->pile[i] == val)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_push_min_to_b(t_all_pile *pile)
{
	int	min;
	int	pos;
	int	i;

	min = ft_find_min(&pile->a);
	pos = ft_find_pos(&pile->a, min);
	if (pos <= pile->a.count / 2)
	{
		i = 0;
		while (i++ < pos)
		{
			ra(&pile->a);
		}
	}
	else
	{
		i = pos;
		while (i++ < pile->a.count)
		{
			rra_rrb(pile->a.pile);
			write(1, "rra\n", 4);
		}
	}
	pb(pile);
}

void	ft_sort_five(t_all_pile *pile)
{
	while (pile->a.count > 3)
	{
		ft_push_min_to_b(pile);
		if (pile->error != 0)
			return ;
	}
	ft_sort_three(pile);
	if (pile->b.count == 2 && pile->b.pile[0] < pile->b.pile[1])
	{
		sa_sb(pile->b.pile);
		write(1, "sb\n", 3);
	}
	pa(pile);
	pa(pile);
}
