/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efresnil <efresnil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 19:07:26 by efresnil          #+#    #+#             */
/*   Updated: 2026/09/02 19:36:32 by efresnil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_circular_sorted(int *a, int size)
{
	int	i;
	int	drops;

	i = 0;
	drops = 0;
	while (i < size)
	{
		if (a[i] > a[(i + 1) % size])
			drops++;
		i++;
	}
	return (drops <= 1);
}

static int	get_target_pos(int *a, int size, int val)
{
	int	i;
	int	min_idx;

	min_idx = find_min_index(a, size);
	i = 0;
	while (i < size)
	{
		if (i == size - 1)
		{
			if (val > a[i] && val < a[0])
				return (0);
		}
		else if (val > a[i] && val < a[i + 1])
			return (i + 1);
		i++;
	}
	return (min_idx);
}

static void	insert_back_to_a(t_stack *stack)
{
	int	pos;

	while (stack->size_b > 0)
	{
		pos = get_target_pos(stack->a, stack->size_a, stack->b[0]);
		if (pos <= stack->size_a / 2)
		{
			while (pos-- > 0)
				ra(stack->a, &stack->size_a, stack->ops);
		}
		else
		{
			pos = stack->size_a - pos;
			while (pos-- > 0)
				rra(stack->a, &stack->size_a, stack->ops);
		}
		pa(stack);
	}
	move_min_to_top(stack->a, &stack->size_a, stack->ops);
}

void	linear_sort(t_stack *stack)
{
	int	n;
	int	curr_max;

	if (is_sorted(stack->a, &stack->size_a))
		return ;
	if (is_circular_sorted(stack->a, stack->size_a))
	{
		move_min_to_top(stack->a, &stack->size_a, stack->ops);
		return ;
	}
	move_min_to_top(stack->a, &stack->size_a, stack->ops);
	curr_max = stack->a[0];
	ra(stack->a, &stack->size_a, stack->ops);
	n = stack->size_a;
	while (--n > 0)
	{
		if (stack->a[0] >= curr_max)
		{
			curr_max = stack->a[0];
			ra(stack->a, &stack->size_a, stack->ops);
		}
		else
			pb(stack);
	}
	insert_back_to_a(stack);
}
