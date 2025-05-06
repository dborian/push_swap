/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:09:14 by dedme             #+#    #+#             */
/*   Updated: 2025/05/06 10:39:57 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_all_pile *pile)
{
	free(pile->a.pile);
	free(pile->b.pile);
}

int	ft_simple_free(t_pile *pile)
{
	free(pile->pile);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all_pile	pile;

	if (argc < 2)
		return (error_write_return(2, &pile.error));
	pile.error = 0;
	pile.a.pile = put_in_tab(argc, argv, &pile.error);
	pile.a.count = argc - 1;
	if (!pile.a.pile)
		return (pile.error);
	if (ft_is_sorted(&pile.a) == 1)
		return (ft_simple_free(&pile.a));
	pile.b.pile = malloc(sizeof(int) * argc);
	pile.b.count = 0;
	if (!pile.b.pile)
	{
		free(pile.a.pile);
		return (error_write_return(1, &pile.error));
	}
	ft_normalize(&pile.a, &pile.error);
	if (ft_no_double(&pile.a) != 0)
		error_write_return(3, &pile.error);
	else
		ft_sort(&pile);
	ft_free(&pile);
	return (pile.error);
}
