/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:46:11 by abenich           #+#    #+#             */
/*   Updated: 2026/08/29 18:38:16 by efresnil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	simple_sort(t_stack *stack)
{
	int	a;

	a = stack->size_a;
	while (a > 4)
	{
		move_min_to_top(stack->A, &stack->size_a, stack->ops);
		pb(stack);
		a--;
	}
	if (a == 4)
		sort_four(stack);
	else if (a == 3)
		sort_three(stack->A, &stack->size_a, stack->ops);
	while (stack->size_b > 0)
	{
		pa(stack);
	}
}

int	medium_sort(t_stack *stack)
{
	int	*result;

	result = ranking(stack->A, &stack->size_a);
	if (result == NULL)
		return (0);
	chunking_a_b(stack);
	b_to_a(stack);
	return (1);
}

static	void	process_bit(t_stack *stack, int size, int bit)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((stack->A[0] >> bit) & 1) == 0)
			pb(stack);
		else
			ra(stack->A, &stack->size_a, stack->ops);
		i++;
	}
	while (stack->size_b > 0)
		pa(stack);
}

int	complex_sort(t_stack *stack, int size)
{
	int	bits;
	int	bit;
	int	*result;

	bit = 0;
	result = ranking(stack->A, &stack->size_a);
	if (result == NULL)
		return (0);
	bits = max_bits(size);
	while (bit < bits)
	{
		process_bit(stack, size, bit);
		bit++;
	}
	return (1);
}

int	adaptive(t_stack *stack, int size)
{
	double	disordr;
	int		a;

	a = 0;
	disordr = disorder(stack->A, &stack->size_a);
	if (disordr < 0.2)
	{
		simple_sort(stack);
		a = 1;
	}
	else if (disordr < 0.5)
		a = medium_sort(stack);
	else
		a = complex_sort(stack, size);
	return (a);
}
