/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:34:00 by abenich           #+#    #+#             */
/*   Updated: 2026/08/29 16:37:00 by abenich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(int *A, int *size_a, t_ops *ops)
{
	if (A[0] > A[1] && A[2] > A[1] && A[2] > A[0])
	{
		sa(A, size_a, ops);
	}
	else if (A[1] > A[0] && A[1] > A[2] && A[0] > A[2])
	{
		rra(A, size_a, ops);
	}
	else if (A[0] > A[2] && A[2] > A[1])
	{
		ra(A, size_a, ops);
	}
	else if (A[0] > A[2] && A[1] > A[2] && A[0] > A[1])
	{
		ra(A, size_a, ops);
		sa(A, size_a, ops);
	}
	else if (A[1] > A[0] && A[1] > A[2] && A[2] > A[0])
	{
		rra(A, size_a, ops);
		sa(A, size_a, ops);
	}
}

static	void	helper_sort(t_stack *stack)
{
	pb(stack);
	sort_three(stack->a, &stack->size_a, stack->ops);
	pa(stack);
}

void	sort_four(t_stack *stack)
{
	if (stack->a[0] > stack->a[3] && stack->a[1] > stack->a[3]
		&& stack->a[2] > stack->a[3])
	{
		rra(stack->a, &stack->size_a, stack->ops);
		helper_sort(stack);
	}
	else if (stack->a[0] > stack->a[1] && stack->a[3] > stack->a[1]
		&& stack->a[2] > stack->a[1])
	{
		sa(stack->a, &stack->size_a, stack->ops);
		helper_sort(stack);
	}
	else if (stack->a[0] > stack->a[2] && stack->a[1] > stack->a[2]
		&& stack->a[3] > stack->a[2])
	{
		rra(stack->a, &stack->size_a, stack->ops);
		rra(stack->a, &stack->size_a, stack->ops);
		helper_sort(stack);
	}
	else
	{
		helper_sort(stack);
	}
}
