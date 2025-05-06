/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 09:27:33 by dedme             #+#    #+#             */
/*   Updated: 2025/05/06 05:00:42 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra_rrb(int *tab)
{
	int	temp;
	int i;

	i = 1;
	while (tab[i])
		i++;
	i--;
	temp = tab[i];
	i--;
	while (i >= 0)
	{
		tab[i+1] = tab[i];
		i--;
	}
	i++;
	tab[i] = temp;
}

void	rrr(t_all_pile *pile)
{
	rra_rrb(pile->a.pile);
	rra_rrb(pile->b.pile);
}