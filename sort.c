/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:34:00 by dedme             #+#    #+#             */
/*   Updated: 2025/05/05 09:16:43 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pick_bin(int nb, int pos)
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

void	ft_sort(t_all_pile *pile)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
}