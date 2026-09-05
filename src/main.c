/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:51:58 by abenich           #+#    #+#             */
/*   Updated: 2026/08/29 18:55:38 by efresnil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_numbers(t_stack *stack, char **av, int start)
{
	int		i;
	int		error;
	char	**split;

	error = 0;
	i = 0;
	while (av[start])
	{
		split = ft_split(av[start], ' ');
		if (!split)
		{
			get_error(stack->a, stack->b);
			return (0);
		}
		if (parsing_helper(stack, split, &i, &error) == 0)
		{
			free_split(split);
			get_error(stack->a, stack->b);
			return (0);
		}
		free_split(split);
		start++;
	}
	return (1);
}

static int	prepare_stack(t_stack *stack, char **av, int start)
{
	stack->a = malloc(stack->size_a * sizeof(int));
	stack->b = malloc(stack->size_a * sizeof(int));
	if (!stack->a || !stack->b)
	{
		get_error(stack->a, stack->b);
		return (0);
	}
	if (parse_numbers(stack, av, start) == 0)
		return (0);
	if (dup_check(stack->a, stack->size_a) == 1)
	{
		get_error(stack->a, stack->b);
		return (0);
	}
	return (1);
}

void	init_info(t_info *info, t_stack *stack, int strategy)
{
	info->sorted = is_sorted(stack->a, &stack->size_a);
	info->size = stack->size_a;
	info->disordr = disorder(stack->a, &stack->size_a);
	info->stg = "none";
	info->complexity = "O(1)";
	if (stack->size_a > 1)
		get_s_c(strategy, &info->stg,
			&info->complexity, info->disordr);
}

static int	init_args(t_stack *stack, int ac, char **av, int *strategy)
{
	int	start;

	*strategy = get_strategy(ac, av);
	if (*strategy == 5)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (*strategy == 0)
		return (0);
	start = get_start(ac, av, *strategy);
	if (init_checker(ac, av, start) == 0)
		return (0);
	stack->size_a = count_all_numbers(av, start);
	if (!stack->size_a)
		return (0);
	stack->size_b = 0;
	return (start);
}

int	main(int ac, char **av)
{
	int		start;
	int		strategy;
	t_ops	ops;
	t_stack	stack;

	ops = (t_ops){0};
	stack.ops = &ops;
	start = init_args(&stack, ac, av, &strategy);
	if (start == 0)
		return (0);
	if (prepare_stack(&stack, av, start) == 0)
		return (0);
	return (run_sort(ac, av, strategy, &stack));
}
