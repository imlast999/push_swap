/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stg_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:51:23 by abenich           #+#    #+#             */
/*   Updated: 2026/08/29 16:51:25 by abenich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "push_swap.h"

int	counting(int *A, int *size_a)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	while (i < *size_a)
	{
		j = i + 1;
		while (j < *size_a)
		{
			if (A[i] > A[j])
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

double	disorder(int *A, int *size_a)
{
	double	max_inversions;
	int		inversions;
	double	disorder;

	if (*size_a < 2)
		return (0);
	inversions = counting(A, size_a);
	max_inversions = *size_a * (*size_a - 1) / 2;
	disorder = inversions / max_inversions;
	return (disorder);
}

char	*get_stg(double disorder)
{
	char	*stg;

	if (disorder < 0.2)
		stg = "simple";
	else if (disorder < 0.5)
		stg = "medium";
	else
		stg = "complex";
	return (stg);
}

char	*get_complexity(double disorder)
{
	char	*complexity;

	if (disorder < 0.2)
		complexity = "O(n^2)";
	else if (disorder < 0.5)
		complexity = "O(n sqrt(n))";
	else
		complexity = "O(n log n)";
	return (complexity);
}

int	get_bench_strategy(int ac, char **av)
{
	char	**split;

	if (ac <= 2)
		return (5);
	if (ft_strcmp(av[2], "--simple") == 0)
		return (1);
	else if (ft_strcmp(av[2], "--medium") == 0)
		return (2);
	else if (ft_strcmp(av[2], "--complex") == 0)
		return (3);
	else if (ft_strcmp(av[2], "--adaptive") == 0)
		return (4);
	split = ft_split(av[2], ' ');
	if (split_str(split) == 1)
	{
		free_split(split);
		return (7);
	}
	free_split(split);
	return (5);
}
