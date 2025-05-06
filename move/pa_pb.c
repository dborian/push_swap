/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:06:46 by dedme             #+#    #+#             */
/*   Updated: 2025/05/06 09:25:15 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_all_pile *pile)
{
	int	i;

	i = pile->a.count;
	while (i > 0)
	{
		pile->a.pile[i] = pile->a.pile[i - 1];
		--i;
	}
	++(pile->a.count);
	pile->a.pile[0] = pile->b.pile[0];
	i = 0;
	while (i < pile->b.count - 1)
	{
		pile->b.pile[i] = pile->b.pile[i + 1];
		++i;
	}
	--(pile->b.count);
	write(1, "pa\n", 3);
}

void	pb(t_all_pile *pile)
{
	int	i;

	i = pile->b.count;
	while (i > 0)
	{
		pile->b.pile[i] = pile->b.pile[i - 1];
		--i;
	}
	++(pile->b.count);
	pile->b.pile[0] = pile->a.pile[0];
	i = 0;
	while (i < pile->a.count - 1)
	{
		pile->a.pile[i] = pile->a.pile[i + 1];
		++i;
	}
	--(pile->a.count);
	write(1, "pb\n", 3);
}
