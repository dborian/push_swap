/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:01:26 by dedme             #+#    #+#             */
/*   Updated: 2025/05/07 05:12:34 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_pile
{
	int	*pile;
	int	count;
}				t_pile;

typedef struct s_all_pile
{
	t_pile	a;
	t_pile	b;
	int		len;
	int		error;
}				t_all_pile;

char	*convert_to_bin(int nbr);
int		ft_numlen(int nb);
int		*put_in_tab(int argc, char **argv, int *return_error);
int		error_write_return(int error, int *return_error);
long	ft_atoi(const char *nptr);
int		ft_verif(int argc, char **argv, int *return_error);
void	ft_sort(t_all_pile *pile);
void	pa(t_all_pile *pile);
void	pb(t_all_pile *pile);
void	ss(t_all_pile *pile);
void	sa_sb(int *tab);
void	ra(t_pile *pile);
void	rb(t_pile *pile);
void	rr(t_all_pile *pile);
void	rra_rrb(int *tab);
void	rrr(t_all_pile *pile);
int		ft_normalize(t_pile *pile, int *error);
int		ft_no_double(t_pile *pile);
int		ft_is_sorted(t_pile *pile);
void	ft_sort_five(t_all_pile *pile);
void	ft_push_min_to_b(t_all_pile *pile);
int		ft_find_pos(t_pile *pile, int val);
int		ft_find_min(t_pile *pile);
void	ft_sort_three(t_all_pile *pile);

#endif