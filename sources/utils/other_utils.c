/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:53:21 by cproesch          #+#    #+#             */
/*   Updated: 2021/10/18 15:13:59 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_non_num(t_set *set, int i, const char *str)
{
	int	j;

	j = 0;
	if (!str[j + i])
		error_message(&set);
	while (str[j + i])
	{
		if ((str[j + i] < '0') || (str[j + i] > '9'))
			error_message(&set);
		j++;
	}
	return ;
}

int	pass_spaces(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ') || ((str[i] >= '\t') && (str[i] <= '\r')))
		i++;
	return (i);
}

int	ft_atoi_ps(t_set *set, const char *str)
{
	size_t	i;
	long	nbr;
	int		n;

	i = pass_spaces(str);
	nbr = 0;
	n = 1;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			n = -n;
		i++;
	}
	check_non_num(set, i, str);
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
		if (((n * nbr) > 2147483647) || ((n * nbr) < -2147483648))
			error_message(&set);
	}
	if (str[i] && (str[i] != '\\'))
		error_message(&set);
	return (n * (int)nbr);
}

int	determine_min(t_stack *stack)
{
	int	nb_min;
	int	size;
	int	i;

	nb_min = stack->nb;
	size = stack_size(stack);
	i = 0;
	while (i < (size - 1))
	{
		if (nb_min > (stack->next->nb))
			nb_min = stack->next->nb;
		stack = stack->next;
		i++;
	}
	return (nb_min);
}

int	determine_max(t_stack *stack)
{
	int	nb_max;
	int	size;
	int	i;

	nb_max = stack->nb;
	size = stack_size(stack);
	i = 0;
	while (i < (size - 1))
	{
		if (nb_max < (stack->next->nb))
			nb_max = stack->next->nb;
		stack = stack->next;
		i++;
	}
	return (nb_max);
}
