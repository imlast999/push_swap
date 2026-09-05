/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:51:34 by abenich           #+#    #+#             */
/*   Updated: 2026/08/29 18:39:54 by efresnil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putdouble_fd(double n, int fd)
{
	int	integer;
	int	decimal;

	integer = (int)n;
	decimal = (int)((n - integer) * 100 + 0.5);
	ft_putnbr_fd(integer, fd);
	ft_putstr_fd(".", fd);
	if (decimal < 10)
		ft_putstr_fd("0", fd);
	ft_putnbr_fd(decimal, fd);
}

static	int	parsing(int	*error, int digits, long result, int sign)
{
	if (result > 214748364
		|| (result == 214748364 && sign == 1 && digits > 7)
		|| (result == 214748364 && sign == -1 && digits > 8))
	{
		*error = 1;
		return (0);
	}
	return (1);
}

static int	get_sign(char *str, int a, int i, int sign)
{
	if (str[i] == '-' && a == 0)
		sign = -1;
	else if (str[i] == '+' && a == 0)
		sign = 1;
	return (sign);
}

int	atoi_plus(char *str, int *error)
{
	long	result;
	int		sign;
	int		i;
	int		a;
	int		digits;

	a = 0;
	i = 0;
	sign = 1;
	result = 0;
	while (str[i])
	{
		sign = get_sign(str, a, i, sign);
		if (str[i] >= '0' && str[i] <= '9')
		{
			digits = str[i] - '0';
			if (parsing(error, digits, result, sign) == 0)
				return (0);
			result = result * 10 + digits;
			a = 1;
		}
		i++;
	}
	return (result * sign);
}
