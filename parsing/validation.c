/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:50:05 by abenich           #+#    #+#             */
/*   Updated: 2026/08/29 18:38:34 by efresnil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stg(int ac, char **av)
{
	if (ac > 1)
	{
		if (av[1][0] == '-' && av[1][1] == '-')
		{
			if (ft_strcmp(av[1], "--simple") == 0
				|| ft_strcmp(av[1], "--medium") == 0
				|| ft_strcmp(av[1], "--complex") == 0
				|| ft_strcmp(av[1], "--adaptive") == 0)
			{
				if (ac > 2)
				{
					if (av[2][0] == '-' && av[2][1] == '-')
					{
						if (!(ft_strcmp(av[2], "--bench") == 0))
							return (1);
					}
				}
			}
			if (ac > 2)
				if (ft_strcmp(av[1], "--bench") == 0)
					if (ft_strcmp(av[2], "--bench") == 0)
						return (1);
		}
	}
	return (0);
}

int	dup_check(int *A, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (A[i] == A[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_valid_numbers(int ac, char **av, int start)
{
	char	**split;

	(void)ac;
	while (av[start])
	{
		split = ft_split(av[start], ' ');
		if (split_str(split) == 0)
		{
			free_split(split);
			return (0);
		}
		free_split(split);
		start++;
	}
	return (1);
}

int	is_sorted(int *A, int *size_a)
{
	int	i;

	if (!A || *size_a <= 1)
		return (1);
	i = 0;
	while (i < *size_a - 1)
	{
		if (A[i] > A[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	max_bits(int size)
{
	int	max;
	int	bits;

	bits = 0;
	max = size - 1;
	while (max > 0)
	{
		max = max / 2;
		bits++;
	}
	return (bits);
}
