/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 09:12:24 by dedme             #+#    #+#             */
/*   Updated: 2025/05/03 09:26:08 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra_rb(int *tab)
{
	int	temp;
	int i;

	i = 1;
	temp = tab[0];
	while (tab[i])
	{
		tab[i-1] = tab[i];
		i++;
	}
	tab[i-1] = temp;
}

void	rr(t_all_pile *pile)
{
	ra_rb(pile->a.pile);
	ra_rb(pile->b.pile);
}