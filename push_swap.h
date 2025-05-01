/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:01:26 by dedme             #+#    #+#             */
/*   Updated: 2025/05/01 17:16:32 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_pile
{
	int	*pile;
	int	count;
}				t_pile;

typedef struct s_all_pile
{
	t_pile	a;
	t_pile	b;
	int	error;
}				t_all_pile;

char	*convert_to_bin(int nbr);
int		ft_numlen(int nb);
int		ft_picknum(int nb, int pos);
int		*put_in_tab(int argc, char **argv, int *return_error);
int		error_write_return(int error, int *return_error);
long	ft_atoi(const char *nptr);
int		ft_verif(int argc, char **argv, int *return_error);
void	ft_sort(t_all_pile pile);

#endif