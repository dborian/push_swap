/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedme <dedme@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 07:16:39 by dedme             #+#    #+#             */
/*   Updated: 2025/05/01 13:27:53 by dedme            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_write_return(int error, int *return_error)
{
	*return_error = error;
	if (error == 1)
	{
		write(2, "ERROR\nmalloc malfunction\n", 26);
		return (1);
	}
	else if (error == 2)
	{
		write(2, "ERROR\nnot enough argument\n", 26);
		return (2);
	}
	else if (error == 3)
	{
		write(2, "ERROR\nincorrect argument\n", 26);
		return (3);
	}
	return (0);
}