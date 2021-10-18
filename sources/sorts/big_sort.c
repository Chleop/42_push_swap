/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:16:59 by cproesch          #+#    #+#             */
/*   Updated: 2021/10/05 12:26:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort_a(t_set *set)
{
	int	i;
	int	size_a;

	i = 0;
	size_a = stack_size(set->stack_a);
	while (i < size_a)
	{
		if (!already_sorted(1, (size_a - i), set->stack_a))
		{
			if (!already_sorted_2((size_a - i), set->stack_a))
			{
				if ((set->stack_a->nb % 2) == 1)
					rotate_a(set);
				else
					push_b(set);
				i++;
			}
			else
				return ;
		}
		else
			return ;
	}	
}

void	radix_sort_a_end(t_set *set)
{
	int	i;
	int	size_a;

	i = 0;
	size_a = stack_size(set->stack_a);
	while (i < size_a)
	{
		if (!end_already_sorted(0, (size_a - i), set->stack_a))
		{
			if ((set->stack_a->nb % 2) == 1)
				rotate_a(set);
			else
				push_b(set);
			i++;
		}
		else
			return ;
	}	
}

void	radix_sort_b(t_set *set)
{
	int	i;
	int	size_b;

	i = 0;
	size_b = stack_size(set->stack_b);
	while (i < size_b)
	{
		if (!already_sorted(0, (size_b - i), set->stack_b))
		{
			if ((set->stack_b->nb % 2) == 0)
				rotate_b(set);
			else
				push_a(set);
			i++;
		}
		else
			return ;
	}
}

void	big_sort(t_set *set)
{
	int	size_b;
	int	i;
	int	nb;

	nb = nb_shifts(set);
	while (nb - 1)
	{
		radix_sort_a(set);
		shift_right(set);
		nb--;
		radix_sort_b(set);
	}
	radix_sort_a_end(set);
	shift_right(set);
	radix_sort_b(set);
	size_b = stack_size(set->stack_b);
	i = 0;
	while (i < size_b)
	{
		push_a(set);
		i++;
	}
}
