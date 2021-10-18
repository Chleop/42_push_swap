/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:11:25 by cproesch          #+#    #+#             */
/*   Updated: 2021/10/08 14:13:24 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *stack)
{
	int	i;
	int	size;

	i = 0;
	size = stack_size(stack);
	while (i < size)
	{
		printf("Elem%d --- [origin = %d] / [nb = %d] / prev = %p / next = %p\n",
			i, stack->original, stack->nb, stack->previous, stack->next);
		stack = stack->next;
		i++;
	}
}

void	print_tab(int *tab, int argc)
{
	int	i;

	i = 0;
	while (i < (argc - 1))
	{
		printf("tab[i] = %d\n", tab[i]);
		i++;
	}
	printf("STOP\n");
}

void	print_both_stacks(t_set *set)
{
	printf("STACK A\n");
	print_list(set->stack_a);
	printf("STACK B\n");
	print_list(set->stack_b);
}
