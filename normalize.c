/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 09:57:56 by dedme             #+#    #+#             */
/*   Updated: 2025/05/03 10:27:40 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_verif(int *tab, int size)
{
	int	i;

	i = 1;
	while (tab[i] >= tab[i - 1] && i <= size)
	{
		i++;
	}
	if (i <= size)
		return (1);
	else
		return (0);
}

static void	ft_sort_int_tab(int *tab, int *pile, int size)
{
	int	i;
	int	best;

	i = 0;
	best = 0;
	while (ft_verif(tab, pile) != 0)
	{
		i = 0;
		while (i <= size)
		{
			if (tab[best] < tab[i])
				best = i;
			i++;
		}
		i = tab[size];
		tab[size] = tab[best];
		tab[best] = i;
		size--;
		best = 0;
	}
}

void	ft_normalize(t_pile *pile)
{
	int	*tab;

	tab = malloc(sizeof(int) * pile->count);
	ft_sort_int_tab(&tab[0], pile->pile, pile->count)
	free(tab);
}