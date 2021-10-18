/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:23:53 by cproesch          #+#    #+#             */
/*   Updated: 2021/10/15 12:09:08 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_argc(char **str)
{
	int		nb;

	nb = 0;
	while (str[nb])
		nb++;
	return (nb);
}

int	main(int argc, char **argv)
{
	t_set	*set;

	if (argc == 1)
		return (0);
	if (argc > (INT_MAX - 1))
		error_message(NULL);
	set = (t_set *)ft_calloc(1, sizeof(t_set));
	if (!set)
		error_message(NULL);
	set->stack_a = NULL;
	set->stack_b = NULL;
	set->int_tab = NULL;
	set->char_tab = NULL;
	set->char_tab = parse(argc, argv);
	argc = count_argc(set->char_tab);
	set->stack_a = init_stack_a(set, argc);
	if (argc <= 6)
		small_sort(argc, set);
	else
		big_sort(set);
	ft_exit(&set, 1);
	return (0);
}
