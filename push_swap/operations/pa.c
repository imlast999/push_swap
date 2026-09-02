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

#include "libft.h"

void	pa(t_stack *stack)
{
	int	a;
	int	b;
	int	i;

	i = 0;
	a = stack->size_a;
	b = stack->size_b;
	if (stack->size_b == 0)
		return ;
	while (a > 0)
	{
		stack->A[a] = stack->A[a - 1];
		a--;
	}
	stack->A[0] = stack->B[0];
	while (b - 1 > i)
	{
		stack->B[i] = stack->B[i + 1];
		i++;
	}
	(stack->size_a)++;
	(stack->size_b)--;
	stack->ops->pa++;
	stack->ops->total++;
	ft_putstr_fd("pa\n", 1);
}
