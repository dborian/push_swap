/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 07:08:03 by dedme             #+#    #+#             */
/*   Updated: 2025/05/06 09:17:38 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*put_in_tab(int argc, char **argv, int *return_error)
{
	int		*tab;
	long	temp;
	int		i;
	int		j;

	j = 1;
	i = 0;
	tab = malloc(sizeof(int) * argc);
	if (!tab)
	{
		error_write_return(1, return_error);
		return (NULL);
	}
	while (i < argc - 1)
	{
		temp = ft_atoi(argv[j++]);
		if (temp < -2147483648 || temp > 2147483647)
		{
			error_write_return(3, return_error);
			free(tab);
			return (NULL);
		}
		tab[i++] = temp;
	}
	return (tab);
}
