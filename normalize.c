/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 09:57:56 by dedme             #+#    #+#             */
/*   Updated: 2025/05/04 11:39:30 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_normalize(t_pile *pile, int *error)
{
	int	i;
	int	j;
	int	count;
	int	*tab;

	tab = malloc(sizeof(int) * pile->count);
	if (!tab)
		return (error_write_return(1, &*error));
	i = -1;
	j = -1;
	count = 0;
	while (++i < pile->count)
		tab[i] = pile->pile[i];
	i = -1;
	while (++i < pile->count)
	{
		while (++j < pile->count)
			if (tab[j] <= tab[i] && i != j)
				count++;
		pile->pile[i] = count;
		count = 0;
		j = -1;
	}
	free(tab);
}
