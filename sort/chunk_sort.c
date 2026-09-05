/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:27:00 by abenich           #+#    #+#             */
/*   Updated: 2026/08/29 16:30:00 by abenich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_rank(int *A, int *B, int *size_a, int i)
{
	int	rank;
	int	j;

	rank = 0;
	j = 0;
	while (j < *size_a)
	{
		if (A[i] > A[j])
			rank++;
		j++;
	}
	B[i] = rank;
}

int	*ranking(int *A, int *size_a)
{
	int	i;
	int	*b;

	b = malloc(*size_a * sizeof(int));
	if (!b)
		return (NULL);
	i = 0;
	while (i < *size_a)
	{
		process_rank(A, b, size_a, i);
		i++;
	}
	i = 0;
	while (i < *size_a)
	{
		A[i] = b[i];
		i++;
	}
	free(b);
	return (A);
}

int	chunk_size(int *size_a)
{
	int	i;

	i = 1;
	while (i * i <= *size_a)
	{
		i++;
	}
	return (i - 1);
}

void	process_chunk(t_stack *stack, int start, int end, int *i)
{
	int	middle;

	middle = start + (end - start) / 2;
	if (stack->A[0] >= start && stack->A[0] < end)
	{
		pb(stack);
		if (stack->B[0] < middle)
			rb(stack->B, &stack->size_b, stack->ops);
		(*i)++;
	}
	else
		ra(stack->A, &stack->size_a, stack->ops);
}

void	chunking_a_b(t_stack *stack)
{
	int	i;
	int	chunk;
	int	start;
	int	end;
	int	size;

	start = 0;
	size = stack->size_a;
	chunk = chunk_size(&size);
	end = chunk;
	while (stack->size_a > 0)
	{
		if (end > size)
			end = size;
		i = 0;
		while (i < end - start)
			process_chunk(stack, start, end, &i);
		start = end;
		end = end + chunk;
	}
}
