/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:51:48 by abenich           #+#    #+#             */
/*   Updated: 2026/08/29 16:51:50 by abenich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_start(int ac, char **av, int strategy)
{
	int	start;

	start = 0;
	if ((strategy >= 1 && strategy <= 4) || strategy == 7)
	{
		if (ac > 2)
		{
			if ((av[1][0] == '-' && av[1][1] == '-')
			&& (av[2][0] == '-' && av[2][1] == '-'))
			{
				start = 3;
			}
			else
				start = 2;
		}
	}
	else if (strategy == 6)
	{
		start = 1;
	}
	return (start);
}

void	get_error(int *A, int *B)
{
	ft_putstr_fd("Error\n", 2);
	free (A);
	free (B);
}

void	get_s_c(int strategy, char **stg, char **complexity, double disordr)
{
	if (strategy == 1)
	{
		*stg = "simple";
		*complexity = "O(n^2)";
	}
	else if (strategy == 2)
	{
		*stg = "medium";
		*complexity = "O(n sqrt(n))";
	}
	else if (strategy == 3)
	{
		*stg = "complex";
		*complexity = "O(n log n)";
	}
	else if (strategy == 4 || strategy == 6 || strategy == 7)
	{
		*stg = "adaptive";
		*complexity = get_complexity(disordr);
	}
}

int	run_selected_sort(t_stack *stack, int strategy, int size)
{
	if (strategy == 1)
	{
		simple_sort(stack);
		return (1);
	}
	else if (strategy == 2)
		return (medium_sort(stack));
	else if (strategy == 3)
		return (complex_sort(stack, size));
	else if (strategy == 4 || strategy == 6 || strategy == 7)
		return (adaptive(stack, size));
	return (0);
}

int	sort_size(t_stack *stack, int strategy, int size)
{
	int	result;

	if (size == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack->a, &stack->size_a, stack->ops);
	}
	else if (size == 3)
		sort_three(stack->a, &stack->size_a, stack->ops);
	else if (size == 4)
		sort_four(stack);
	else if (size > 4)
	{
		result = run_selected_sort(stack, strategy, size);
		if (result == 0)
			return (0);
	}
	return (1);
}
