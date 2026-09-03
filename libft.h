/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 18:11:02 by abenich           #+#    #+#             */
/*   Updated: 2026/08/29 19:05:32 by efresnil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_ops
{
	int	total;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_ops;

typedef struct s_stack
{
	int		*A;
	int		*B;
	int		size_a;
	int		size_b;
	t_ops	*ops;
}	t_stack;

typedef struct s_info
{
	int		sorted;
	int		size;
	char	*complexity;
	char	*stg;
	double	disordr;
}	t_info;

void	sa(int *A, int *size_a, t_ops *ops);
void	sb(int *B, int *size_b, t_ops *ops);
void	pb(t_stack *stack);
void	pa(t_stack *stack);
void	ra(int *A, int *size_a, t_ops *ops);
void	rra(int *A, int *size_a, t_ops *ops);
void	rb(int *B, int *size_b, t_ops *ops);
void	rrb(int *B, int *size_b, t_ops *ops);
void	ss(t_stack *stack);
void	rr(t_stack *stack);
void	rrr(t_stack *stack);

void	sort_three(int *A, int *size_a, t_ops *ops);
void	sort_four(t_stack *stack);
void	simple_sort(t_stack *stack);
void	linear_sort(t_stack *stack);
int		medium_sort(t_stack *stack);
int		complex_sort(t_stack *stack, int size);
int		adaptive(t_stack *stack, int size);
void	free_stack(t_stack *stack);

int		find_min_index(int *A, int size_a);
int		find_max_index(int *B, int *size_b);
void	move_min_to_top(int *A, int *size_a, t_ops *ops);
void	move_max_to_top(int *B, int *size_b, t_ops *ops);
int		is_sorted(int *A, int *size_a);
void	process_rank(int *A, int *B, int *size_a, int i);
int		*ranking(int *A, int *size_a);
int		chunk_size(int *size_a);
void	process_chunk(t_stack *stack, int start, int end, int *i);
void	chunking_a_b(t_stack *stack);
void	b_to_a(t_stack *stack);
int		max_bits(int size);
int		is_valid_numbers(int ac, char **av, int start);
int		check_stg(int ac, char **av);
int		dup_check(int *A, int size);

int		counting(int *A, int *size_a);
double	disorder(int *A, int *size_a);
char	*get_stg(double disorder);
char	*get_complexity(double disorder);
int		get_bench_strategy(int ac, char **av);
int		check_plain_numbers(int ac, char **av);
int		get_strategy(int ac, char **av);
int		there_is_bench(int ac, char **av);
void	bench(int ac, char **av, double disorder, char *strategy,
			char *complexity, t_ops *ops);

int		get_start(int ac, char **av, int strategy);
void	get_error(int *A, int *B);
void	get_s_c(int strategy, char **stg, char **complexity, double disordr);
int		helper(t_stack *stack, int strategy, int size);
int		sort_size(t_stack *stack, int strategy, int size);

void	ft_putdouble_fd(double n, int fd);
int		ft_strcmp(const char *s1, const char *s2);
int		atoi_plus(char *str, int *error);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
