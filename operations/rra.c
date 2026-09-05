/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 15:45:00 by abenich           #+#    #+#             */
/*   Updated: 2026/08/29 18:58:23 by efresnil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(int *A, int *size_a, t_ops *ops)
{
	int		a;		
	int		tmp;

	a = *size_a - 1;
	if (*size_a > 1)
	{
		tmp = A[a];
		while (a > 0)
		{
			A[a] = A[a - 1];
			a--;
		}
		A[0] = tmp;
		ops->rra++;
		ops->total++;
		ft_putstr_fd("rra\n", 1);
	}
}
