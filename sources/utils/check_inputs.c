/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:13:22 by cproesch          #+#    #+#             */
/*   Updated: 2021/10/18 15:22:25 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_order(t_set *set, int *tab, int argc)
{
	int	i;

	i = 0;
	while ((i < (argc - 2)) && (tab[i + 1]))
	{
		if (tab[i] == tab[i + 1])
			error_message(&set);
		if (tab[i] > tab[i + 1])
			return ;
		i++;
	}
	ft_exit(&set, 1);
}

void	check_duplicates(t_set *set, int argc)
{
	int	i;

	i = 0;
	while (i < (argc - 2))
	{
		if ((set->int_tab)[i] == (set->int_tab)[i + 1])
			error_message(&set);
		i++;
	}
	return ;
}
