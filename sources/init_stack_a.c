/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:35:03 by cproesch          #+#    #+#             */
/*   Updated: 2021/10/18 14:53:05 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_argv_into_tab(t_set *set, int argc)
{
	int	nb;
	int	i;

	i = 0;
	set->int_tab = (int *)malloc(sizeof(int) * argc);
	if (!set->int_tab)
		error_message(&set);
	while (i < (argc - 1))
	{
		nb = ft_atoi_ps(set, set->char_tab[i + 1]);
		set->int_tab[i] = nb;
		i++;
	}
}

void	put_tab_in_order(int argc, int *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < (argc - 2))
	{
		j = 0;
		while (j < (argc - 2))
		{
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}

int	replace_argv_by_index(t_set *set, int argc, char *str, int *tab)
{
	int		nb;
	int		j;

	j = 0;
	while (j < (argc - 1))
	{
		if (ft_atoi_ps(set, str) == tab[j])
			nb = j + 1;
		j++;
	}
	return (nb);
}

t_stack	*init_stack_a(t_set *set, int argc)
{
	t_stack	*stack_a;
	t_stack	*new;
	int		nb;
	int		i;

	i = 1;
	stack_a = NULL;
	copy_argv_into_tab(set, argc);
	check_order(set, set->int_tab, argc);
	put_tab_in_order(argc, set->int_tab);
	check_duplicates(set, argc);
	while (i < argc)
	{
		nb = replace_argv_by_index(set, argc, (set->char_tab)[i], set->int_tab);
		new = new_element(set, nb, (set->char_tab)[i]);
		add_back_element(&stack_a, new);
		i++;
	}
	free (set->int_tab);
	set->int_tab = NULL;
	return (stack_a);
}
