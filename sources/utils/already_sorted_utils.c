/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_sorted_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:03:08 by cproesch          #+#    #+#             */
/*   Updated: 2021/10/08 14:05:42 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_sorted(int x, int size_to_sort, t_stack *stack)
{
	int	i;
	int	current_size;

	i = 0;
	current_size = stack_size(stack);
	if (size_to_sort == current_size)
	{
		while (i < size_to_sort)
		{
			if ((stack->nb % 2) != x)
				break ;
			stack = stack->next;
			i++;
		}
	}
	if (i == size_to_sort)
		return (1);
	return (0);
}

int	already_sorted_2(int size_to_sort, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < size_to_sort)
	{
		if ((stack->nb % 2) == 1)
			break ;
		stack = stack->next;
		i++;
	}
	if (i < size_to_sort)
		return (0);
	i = 0;
	while (i < size_to_sort)
	{
		if ((((stack->nb) >> 1) % 2) == 0)
			break ;
		stack = stack->next;
		i++;
	}
	if (i == size_to_sort)
		return (1);
	return (0);
}

int	end_already_sorted(int x, int size_to_sort, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < size_to_sort)
	{
		if ((stack->nb % 2) != x)
			break ;
		stack = stack->next;
		i++;
	}
	if (i == size_to_sort)
		return (1);
	return (0);
}
