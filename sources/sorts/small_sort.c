/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:17:04 by cproesch          #+#    #+#             */
/*   Updated: 2021/10/05 15:56:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_set *set)
{
	int	x;
	int	y;
	int	z;

	x = set->stack_a->nb;
	y = set->stack_a->next->nb;
	z = set->stack_a->next->next->nb;
	if ((x < y) && (y < z))
		return ;
	if ((x > y) && (x > z))
	{
		rotate_a(set);
		if (y > z)
			swap_a(set);
	}
	else if ((x < y) && (x < z))
	{
		reverse_rotate_a(set);
		swap_a(set);
	}
	else if (y < z)
		swap_a(set);
	else
		reverse_rotate_a(set);
}

void	sort_4_min_on_top(t_set *set)
{
	push_b(set);
	sort_3(set);
	push_a(set);
}

void	sort_4(t_set *set)
{
	int	min;
	int	min_index;

	min = determine_min(set->stack_a);
	min_index = locate_nb(set->stack_a, min);
	if (min_index == 4)
		reverse_rotate_a(set);
	else
	{
		while ((min_index--) != 1)
			rotate_a(set);
	}
	sort_4_min_on_top(set);
}

void	sort_5(t_set *set)
{
	int	min;
	int	min_index;

	min = determine_min(set->stack_a);
	min_index = locate_nb(set->stack_a, min);
	if (min_index > 3)
	{
		while ((min_index++) != 6)
			reverse_rotate_a(set);
	}
	else
	{
		while ((min_index--) != 1)
			rotate_a(set);
	}
	push_b(set);
	sort_4(set);
	push_a(set);
}

void	small_sort(int argc, t_set *set)
{
	if (argc == 3)
		swap_a(set);
	else if (argc == 4)
		sort_3(set);
	else if (argc == 5)
		sort_4(set);
	else if (argc == 6)
		sort_5(set);
}
