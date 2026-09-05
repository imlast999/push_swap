/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:50:34 by abenich           #+#    #+#             */
/*   Updated: 2026/08/29 16:50:36 by abenich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(int *A, int size_a)
{
	int	min;
	int	min_index;
	int	i;

	i = 0;
	min_index = 0;
	min = A[0];
	while (size_a > i)
	{
		if (A[i] < min)
		{
			min = A[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	find_max_index(int *B, int *size_b)
{
	int	max;
	int	max_index;
	int	i;

	i = 0;
	max = B[0];
	max_index = 0;
	while (*size_b > i)
	{
		if (B[i] > max)
		{
			max = B[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

void	move_min_to_top(int *A, int *size_a, t_ops *ops)
{
	int	i;

	i = find_min_index(A, *size_a);
	if (i > *size_a / 2)
	{
		while (*size_a - i > 0)
		{
			rra(A, size_a, ops);
			i++;
		}
	}
	else if (i <= *size_a / 2)
	{
		while (i > 0)
		{
			ra(A, size_a, ops);
			i--;
		}
	}
}

void	move_max_to_top(int *B, int *size_b, t_ops *ops)
{
	int	i;

	i = find_max_index(B, size_b);
	if (*size_b / 2 < i)
	{
		while (*size_b - i > 0)
		{
			rrb(B, size_b, ops);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			rb(B, size_b, ops);
			i--;
		}
	}
}

void	b_to_a(t_stack *stack)
{
	while (stack->size_b > 0)
	{
		move_max_to_top(stack->B, &stack->size_b, stack->ops);
		pa(stack);
	}
}
