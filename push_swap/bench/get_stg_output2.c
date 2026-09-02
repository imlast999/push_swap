/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stg_output2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:03:44 by abenich           #+#    #+#             */
/*   Updated: 2026/08/29 18:39:15 by efresnil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_plain_numbers(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-')
		{
			j++;
			if (av[i][j] == '\0')
				return (5);
		}
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (5);
			j++;
		}
		i++;
	}
	return (6);
}

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
	return (check_plain_numbers(ac, av));
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

void	bench(int ac, char **av, double disorder, char *strategy,
	char *complexity, t_ops *ops)
{
	if (there_is_bench(ac, av) == 1)
	{
		ft_putstr_fd("Disorder :", 2);
		ft_putdouble_fd(disorder, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("Strategy : ", 2);
		ft_putstr_fd(strategy, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("Complexity : ", 2);
		ft_putstr_fd(complexity, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("sa: ", 2);
		ft_putnbr_fd(ops->sa, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("sb: ", 2);
		ft_putnbr_fd(ops->sb, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("ss: ", 2);
		ft_putnbr_fd(ops->ss, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("pa: ", 2);
		ft_putnbr_fd(ops->pa, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("pb: ", 2);
		ft_putnbr_fd(ops->pb, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("ra: ", 2);
		ft_putnbr_fd(ops->ra, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("rb: ", 2);
		ft_putnbr_fd(ops->rb, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("rr: ", 2);
		ft_putnbr_fd(ops->rr, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("rra: ", 2);
		ft_putnbr_fd(ops->rra, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("rrb: ", 2);
		ft_putnbr_fd(ops->rrb, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("rrr: ", 2);
		ft_putnbr_fd(ops->rrr, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("Total operations: ", 2);
		ft_putnbr_fd(ops->total, 2);
		ft_putstr_fd("\n", 2);
	}
}
