/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:32:59 by allefran          #+#    #+#             */
/*   Updated: 2025/05/06 10:40:09 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_pile *pile)
{
	int	i;

	i = -1;
	while (++i < pile->count - 1)
		if (pile->pile[i] >= pile->pile[i + 1])
			return (0);
	return (1);
}
