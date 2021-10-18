/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:32:23 by cproesch          #+#    #+#             */
/*   Updated: 2021/10/08 13:44:37 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*last_elmt;

	last_elmt = last_element(*stack);
	(*stack)->previous = last_elmt;
	last_elmt->next = *stack;
	(*stack)->next->previous = NULL;
	*stack = (*stack)->next;
	last_elmt->next->next = NULL;
}

void	rotate_a(t_set *set)
{
	rotate(&(set->stack_a));
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_set *set)
{
	rotate(&(set->stack_b));
	ft_putstr_fd("rb\n", 1);
}

void	rotate_ab(t_set *set)
{
	rotate(&(set->stack_a));
	rotate(&(set->stack_b));
	ft_putstr_fd("rr\n", 1);
}
