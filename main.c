/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:09:14 by dedme             #+#    #+#             */
/*   Updated: 2025/05/04 11:17:37 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_all_pile pile;
	int	i;

	i = 0;
	if (argc < 2)
		return (error_write_return(2, &pile.error));
	pile.error = 0;
	pile.a.pile = put_in_tab(argc, argv, &pile.error);
	pile.a.count = argc - 1;
	if (!pile.a.pile)
		return (pile.error);
	pile.b.pile = malloc(sizeof(int) * argc);
	pile.b.count = 0;
	if (!pile.b.pile)
	{
		free(pile.a.pile);
		return (error_write_return(1, &pile.error));
	}
	while (i < pile.a.count)
	{
		printf("tab[%d] = %d\n", i, pile.a.pile[i]);
		i++;
	}
	i = 0;
	ft_normalize(&pile.a, &pile.error);
	while (i < pile.a.count)
	{
		printf("tab[%d] = %d\n", i, pile.a.pile[i]);
		i++;
	}
	free(pile.a.pile);
	free(pile.b.pile);
	return (pile.error);
}