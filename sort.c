/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:34:00 by dedme             #+#    #+#             */
/*   Updated: 2025/05/06 07:50:54 by dedme            ###   ########.fr       */
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
	int bits = 0;
	while ((nb >> bits) != 0)
		bits++;
	return (bits);
}

void	print_piles(t_all_pile *pile)
{
	int	i;

	printf("Pile A: ");
	for (i = 0; i < pile->a.count; i++)
		printf("%d ", pile->a.pile[i]);
	printf("size = %d\n\n", pile->a.count);

	printf("Pile B: ");
	for (i = 0; i < pile->b.count; i++)
		printf("%d ", pile->b.pile[i]);
	printf("size = %d\n\n", pile->b.count);
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
	len = ft_count_bits(best);
	// print_piles(pile);
	while (j < len+1)
	{
		t_len = pile->a.count;
		while (i < t_len)
		{
			// printf("test = %d\n", pile->a.pile[0]);
			if (ft_pick_bin(pile->a.pile[0], j) == 1)
			{
				ra_rb(&pile->a);
				write(1, "ra\n", 3);
			}
			else
			{
				pb(&*pile);
				write(1, "pb\n", 3);
			}
			// print_piles(pile);
			i++;
		}
		i = 0;
		j++;
		t_len = pile->b.count;
		while (i < t_len)
		{
			// printf("test = %d\n", pile->a.pile[0]);
			if (ft_pick_bin(pile->b.pile[0], j) == 0)
			{
				ra_rb(&pile->b);
				write(1, "rb\n", 3);
			}
			else
			{
				pa(&*pile);
				write(1, "pa\n", 3);
			}
			// print_piles(pile);
			i++;
		}
		i = 0;
	}
}
