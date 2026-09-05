/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:03:44 by abenich           #+#    #+#             */
/*   Updated: 2026/08/29 18:39:15 by efresnil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_strategy(int ac, char **av)
{
	if (ac <= 1)
		return (0);
	if (check_stg(ac, av) == 1)
		return (5);
	if (av[1][0] == '-' && av[1][1] == '-')
	{
		if (ft_strcmp(av[1], "--simple") == 0)
			return (1);
		else if (ft_strcmp(av[1], "--medium") == 0)
			return (2);
		else if (ft_strcmp(av[1], "--complex") == 0)
			return (3);
		else if (ft_strcmp(av[1], "--adaptive") == 0)
			return (4);
		else if (ft_strcmp(av[1], "--bench") == 0)
			return (get_bench_strategy(ac, av));
		return (5);
	}
	return (6);
}

int	there_is_bench(int ac, char **av)
{
	if (ac > 1)
	{
		if (ft_strcmp(av[1], "--bench") == 0)
			return (1);
	}
	if (ac > 2)
	{
		if (ft_strcmp(av[2], "--bench") == 0)
			return (1);
	}
	return (0);
}
