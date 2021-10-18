/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_exit_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:47:30 by cproesch          #+#    #+#             */
/*   Updated: 2021/10/15 12:22:58 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_del_element(t_stack *stack)
{
	stack->nb = 0;
	stack->original = 0;
	stack->next = NULL;
	stack->previous = NULL;
	free (stack);
}

void	ft_del_list(t_stack **stack)
{
	t_stack	*next_element;

	if ((!stack) || (!(*stack)))
		return ;
	while (*stack)
	{
		next_element = (*stack)->next;
		ft_del_element(*stack);
		(*stack) = next_element;
	}
}

void	ft_del_stringtab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_exit(t_set **set, int exit_code)
{
	if ((set) && (*set))
	{
		if ((*set)->stack_a)
			ft_del_list(&((*set)->stack_a));
		if ((*set)->stack_b)
			ft_del_list(&((*set)->stack_b));
		if ((*set)->char_tab)
			ft_del_stringtab((*set)->char_tab);
		if ((*set)->int_tab)
			free((*set)->int_tab);
		if (*set)
			free(*set);
	}
	exit (exit_code);
}

void	error_message(t_set **set)
{
	ft_putstr_fd("Error\n", 2);
	ft_exit(set, -1);
}
