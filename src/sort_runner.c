/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_runner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 18:07:02 by abenich           #+#    #+#             */
/*   Updated: 2026/08/29 18:07:03 by abenich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	free (stack->a);
	free (stack->b);
}

int	run_sort(int ac, char **av, int strategy, t_stack *stack)
{
	t_info	info;

	init_info(&info, stack, strategy);
	if (stack->size_a > 1 && info.sorted == 0)
	{
		if (sort_size(stack, strategy, info.size) == 0)
		{
			free_stack(stack);
			return (0);
		}
	}
	bench(ac, av, &info, stack->ops);
	free_stack(stack);
	return (0);
}

int	init_checker(int ac, char **av, int start)
{
	if (start >= ac)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (is_valid_numbers(ac, av, start) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}
