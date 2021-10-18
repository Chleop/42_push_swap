/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:19:46 by cproesch          #+#    #+#             */
/*   Updated: 2021/09/30 18:16:59 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last_elmt;

	last_elmt = last_element(*stack);
	last_elmt->next = *stack;
	(*stack)->previous = last_elmt;
	last_elmt->previous->next = NULL;
	last_elmt->previous = NULL;
	*stack = (*stack)->previous;
}

void	reverse_rotate_a(t_set *set)
{
	reverse_rotate(&(set->stack_a));
	ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_set *set)
{
	reverse_rotate(&(set->stack_b));
	ft_putstr_fd("rrb\n", 1);
}

void	reverse_rotate_ab(t_set *set)
{
	reverse_rotate(&(set->stack_a));
	reverse_rotate(&(set->stack_b));
	ft_putstr_fd("rrr\n", 1);
}
