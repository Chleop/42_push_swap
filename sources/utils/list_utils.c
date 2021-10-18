/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:07:30 by cproesch          #+#    #+#             */
/*   Updated: 2021/10/14 18:32:24 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_element(t_set *set, int nb, char *str)
{
	t_stack	*new_element;

	new_element = (t_stack *)malloc(sizeof(t_stack));
	if (!new_element)
		error_message(&set);
	new_element->nb = nb;
	new_element->original = ft_atoi_ps(set, str);
	new_element->previous = NULL;
	new_element->next = NULL;
	return (new_element);
}

t_stack	*last_element(t_stack *lst)
{
	t_stack	*next_element;

	if (!lst)
		return (0);
	if (!lst->next)
		return (lst);
	next_element = lst->next;
	while (next_element->next)
		next_element = next_element->next;
	return (next_element);
}

void	add_back_element(t_stack **stack, t_stack *new)
{
	if (!*stack)
		*stack = new;
	else
	{
		new->previous = last_element(*stack);
		last_element(*stack)->next = new;
	}
}

int	stack_size(t_stack *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

int	locate_nb(t_stack *stack, int nb)
{
	int	i;

	i = 1;
	while (stack->nb != nb)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
