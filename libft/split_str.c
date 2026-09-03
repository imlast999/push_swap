/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efresnil <efresnil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 17:47:31 by efresnil          #+#    #+#             */
/*   Updated: 2026/09/02 17:47:35 by efresnil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	split_str(char **split)
{
	int	i;
	int	j;

	if (!split || !split[0])
		return (0);
	i = 0;
	while (split[i])
	{
		j = 0;
		if (split[i][j] == '-')
		{
			j++;
			if (split[i][j] == 0)
				return (0);
		}
		while (split[i][j])
		{
			if (!(split[i][j] >= '0' && split[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	count_all_numbers(char **av, int start)
{
	char	**split;
	int		i;
	int		count;

	count = 0;
	while (av[start])
	{
		split = ft_split(av[start], ' ');
		if (!split || !split[0])
		{
			free_split(split);
			return (0);
		}
		i = 0;
		while (split[i])
		{
			count++;
			i++;
		}
		free_split(split);
		start++;
	}
	return (count);
}

int	parsing_helper(t_stack *stack, char **split, int *i, int *error)
{
	int	j;

	j = 0;
	while (split[j])
	{
		stack->A[*i] = atoi_plus(split[j], error);
		if (*error == 1)
		{
			return (0);
		}
		j++;
		(*i)++;
	}
	return (1);
}
