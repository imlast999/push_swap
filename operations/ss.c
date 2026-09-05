/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:06:00 by abenich           #+#    #+#             */
/*   Updated: 2026/08/29 16:09:00 by abenich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stack)
{
	int	tmp;

	if (stack->size_a > 1)
	{
		tmp = stack->A[0];
		stack->A[0] = stack->A[1];
		stack->A[1] = tmp;
	}
	if (stack->size_b > 1)
	{
		tmp = stack->B[0];
		stack->B[0] = stack->B[1];
		stack->B[1] = tmp;
	}
	if (stack->size_b > 1 || stack->size_a > 1)
	{
		stack->ops->ss++;
		stack->ops->total++;
		ft_putstr_fd("ss\n", 1);
	}
}
