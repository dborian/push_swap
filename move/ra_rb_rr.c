/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 09:12:24 by dedme             #+#    #+#             */
/*   Updated: 2025/05/06 09:21:51 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_pile *pile)
{
	int	temp;
	int	i;

	i = 1;
	temp = pile->pile[0];
	while (i < pile->count)
	{
		pile->pile[i - 1] = pile->pile[i];
		i++;
	}
	pile->pile[i - 1] = temp;
	write(1, "ra\n", 3);
}

void	rb(t_pile *pile)
{
	int	temp;
	int	i;

	i = 1;
	temp = pile->pile[0];
	while (i < pile->count)
	{
		pile->pile[i - 1] = pile->pile[i];
		i++;
	}
	pile->pile[i - 1] = temp;
	write(1, "rb\n", 3);
}

void	rr(t_all_pile *pile)
{
	ra(&pile->a);
	rb(&pile->b);
}
