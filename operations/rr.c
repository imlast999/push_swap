/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:13:00 by abenich           #+#    #+#             */
/*   Updated: 2026/08/29 16:16:00 by abenich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rr_helper(int *a, int size_a)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = a[0];
	while (size_a - 1 > i)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = tmp;
}

void	rr(t_stack *stack)
{
	if (stack->size_a > 1)
	{
		rr_helper(stack->a, stack->size_a);
	}
	if (stack->size_b > 1)
	{
		rr_helper(stack->b, stack->size_b);
	}
	if (stack->size_b > 1 || stack->size_a > 1)
	{
		stack->ops->rr++;
		stack->ops->total++;
		ft_putstr_fd("rr\n", 1);
	}
}
