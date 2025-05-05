/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:04:06 by dedme             #+#    #+#             */
/*   Updated: 2025/05/06 00:10:51 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_numlen(int nb)
{
	int	len;
	int	i;

	i = 10;
	len = 1;
	while (nb / i != 0)
	{
		i = i * 10;
		len++;
	}
	return (len);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	long	nb;
	int		v;

	v = 1;
	nb = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-')
		v = -1 + (i++ *0);
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i++] - 48);
	}
	if (!(nptr[i] >= '0' && nptr[i] <= '9') && nptr[i] != 0)
		return (2147483648);
	return (nb * v);
}

int	ft_verif(int argc, char **argv, int *return_error)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j++ < argc - 1)
	{
		while (argv[j][i])
		{
			if (!(argv[j][i++] <= '9' || argv[j][i++] >= '0'))
				return (error_write_return(3, return_error));
		}
	}
	return (0);
}

int	ft_no_double(t_pile *pile)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < pile->count)
	{
		while (i < pile->count)
		{
			if (pile->pile[j] == pile->pile[i] && j != i)
				return (1);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}