/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:01:26 by dedme             #+#    #+#             */
/*   Updated: 2025/05/04 05:36:58 by dedme            ###   ########.fr       */
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
void	pa(t_all_pile *pile);
void	pb(t_all_pile *pile);
void	ss(t_all_pile *pile);
void	sa_sb(int *tab);
void	ra_rb(int *tab);
void	rr(t_all_pile *pile);
void	rra_rrb(int *tab);
void	rrr(t_all_pile *pile);
int		ft_normalize(t_pile *pile, int *error);

#endif