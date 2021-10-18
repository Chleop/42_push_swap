/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:27:48 by cproesch          #+#    #+#             */
/*   Updated: 2021/10/08 13:44:14 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_x, t_stack **stack_y)
{
	if (!(*stack_y))
	{
		(*stack_y) = (*stack_x);
		(*stack_x) = (*stack_x)->next;
		(*stack_x)->previous = NULL;
		(*stack_y)->next = NULL;
	}
	else if (stack_size(*stack_x) == 1)
	{
		(*stack_x)->next = (*stack_y);
		(*stack_y)->previous = (*stack_x);
		(*stack_y) = (*stack_y)->previous;
		(*stack_x) = NULL;
	}
	else
	{
		(*stack_x) = (*stack_x)->next;
		(*stack_x)->previous->next = (*stack_y);
		(*stack_y)->previous = (*stack_x)->previous;
		(*stack_x)->previous = NULL;
		(*stack_y) = (*stack_y)->previous;
	}
}

void	push_a(t_set *set)
{
	push(&(set->stack_b), &(set->stack_a));
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_set *set)
{
	push(&(set->stack_a), &(set->stack_b));
	ft_putstr_fd("pb\n", 1);
}
