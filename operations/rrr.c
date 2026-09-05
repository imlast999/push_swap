/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:20:00 by abenich           #+#    #+#             */
/*   Updated: 2026/08/29 16:23:00 by abenich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rrr_helper(int *a, int last)
{
	int	tmp;

	tmp = a[last];
	while (last > 0)
	{
		a[last] = a[last - 1];
		last--;
	}
	a[0] = tmp;
}

void	rrr(t_stack *stack)
{
	int	a;
	int	b;

	a = stack->size_a - 1;
	if (stack->size_a > 1)
	{
		rrr_helper(stack->a, a);
	}
	b = stack->size_b - 1;
	if (stack->size_b > 1)
	{
		rrr_helper(stack->b, b);
	}
	if (stack->size_b > 1 || stack->size_a > 1)
	{
		stack->ops->rrr++;
		stack->ops->total++;
		ft_putstr_fd("rrr\n", 1);
	}
}
