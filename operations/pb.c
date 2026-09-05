/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 15:24:00 by abenich           #+#    #+#             */
/*   Updated: 2026/08/29 15:27:00 by abenich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	pb_helper(t_stack *stack)
{
	stack->size_a--;
	stack->size_b++;
	stack->ops->pb++;
	stack->ops->total++;
	ft_putstr_fd("pb\n", 1);
}

void	pb(t_stack *stack)
{
	int	x;
	int	i;

	x = stack->size_b;
	i = stack->size_a;
	if (stack->size_a == 0)
		return ;
	while (x > 0)
	{
		stack->b[x] = stack->b[x - 1];
		x--;
	}
	stack->b[0] = stack->a[0];
	x = 0;
	while (i - 1 > x)
	{
		stack->a[x] = stack->a[x + 1];
		x++;
	}
	pb_helper(stack);
}
