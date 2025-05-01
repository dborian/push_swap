/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:01:16 by dedme             #+#    #+#             */
/*   Updated: 2025/05/02 01:06:03 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa_sb(int *tab)
{
	int	temp;

	temp = tab[0];
	tab[0] = tab[1];
	tab[1] = temp;
}

void	ss(t_all_pile *pile)
{
	sa_sb(pile->a.pile);
	sa_sb(pile->b.pile);
}