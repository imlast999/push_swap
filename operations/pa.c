/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 15:31:00 by abenich           #+#    #+#             */
/*   Updated: 2026/08/29 15:34:00 by abenich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack)
{
	int	x;
	int	b;
	int	i;

	i = 0;
	x = stack->size_a;
	b = stack->size_b;
	if (stack->size_b == 0)
		return ;
	while (x > 0)
	{
		stack->a[x] = stack->a[x - 1];
		x--;
	}
	stack->a[0] = stack->b[0];
	while (b - 1 > i)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	(stack->size_a)++;
	(stack->size_b)--;
	stack->ops->pa++;
	stack->ops->total++;
	ft_putstr_fd("pa\n", 1);
}
