/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 09:12:24 by dedme             #+#    #+#             */
/*   Updated: 2025/05/06 05:07:04 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

	void	ra_rb(t_pile *pile)
	{
		int	temp;
		int i;

		i = 1;
		temp = pile->pile[0];
		while (i < pile->count)
		{
			pile->pile[i-1] = pile->pile[i];
			i++;
		}
		pile->pile[i-1] = temp;
	}

void	rr(t_all_pile *pile)
{
	ra_rb(&pile->a);
	ra_rb(&pile->b);
}