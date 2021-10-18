/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:09:47 by cproesch          #+#    #+#             */
/*   Updated: 2021/10/08 14:07:42 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *b;
	*b = *a;
	*a = c;
}

void	swap_a(t_set *set)
{
	ft_swap(&(set->stack_a->nb), &(set->stack_a->next->nb));
	ft_swap(&(set->stack_a->original), &(set->stack_a->next->original));
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_set *set)
{
	ft_swap(&(set->stack_b->nb), &(set->stack_b->next->nb));
	ft_swap(&(set->stack_b->original), &(set->stack_b->next->original));
	ft_putstr_fd("sb\n", 1);
}

void	swap_ab(t_set *set)
{
	ft_swap(&(set->stack_a->nb), &(set->stack_a->next->nb));
	ft_swap(&(set->stack_a->original), &(set->stack_a->next->original));
	ft_swap(&(set->stack_b->nb), &(set->stack_b->next->nb));
	ft_swap(&(set->stack_b->original), &(set->stack_b->next->original));
	ft_putstr_fd("ss\n", 1);
}
