/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:03:08 by cproesch          #+#    #+#             */
/*   Updated: 2021/10/08 14:05:42 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_one_stack(t_stack *stack)
{
	int		i;
	int		size;
	t_stack	*origin;

	i = 0;
	origin = stack;
	size = stack_size(stack);
	while (i < size)
	{
		stack->nb = (stack->nb >> 1);
		stack = stack->next;
		i++;
	}
	stack = origin;
}

void	shift_right(t_set *set)
{
	shift_one_stack(set->stack_a);
	shift_one_stack(set->stack_b);
}

int	nb_shifts(t_set *set)
{
	int	i;
	int	max;

	i = 1;
	max = determine_max(set->stack_a);
	while ((max >> 1) != 0)
	{
		max = max >> 1;
		i++;
	}
	return (i);
}
