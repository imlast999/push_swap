/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 19:37:22 by abenich           #+#    #+#             */
/*   Updated: 2026/08/29 19:37:24 by abenich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	bench_1(t_info *info)
{
	ft_putstr_fd("Disorder :", 2);
	ft_putdouble_fd(info->disordr * 100, 2);
	ft_putstr_fd(" %\n", 2);
	ft_putstr_fd("Strategy : ", 2);
	ft_putstr_fd(info->stg, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("Complexity : ", 2);
	ft_putstr_fd(info->complexity, 2);
	ft_putstr_fd("\n", 2);
}

static	void	bench_2(t_ops *ops)
{
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
}

static	void	bench_3(t_ops *ops)
{
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

void	bench(int ac, char **av, t_info *info, t_ops *ops)
{
	if (there_is_bench(ac, av) == 1)
	{
		bench_1(info);
		bench_2(ops);
		bench_3(ops);
	}
}
