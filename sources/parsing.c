/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:00:29 by cproesch          #+#    #+#             */
/*   Updated: 2021/10/15 12:38:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*concatenate(int argc, char **argv)
{
	int		i;
	size_t	a;

	argv[0] = ft_memcpy(argv[0], "ps", 3);
	i = 0;
	while (i < (argc - 1))
	{
		a = ft_strlen(argv[0]) + ft_strlen(argv[i + 1]) + 2;
		ft_strlcat(argv[0], " ", ft_strlen(argv[0]) + 2);
		ft_strlcat(argv[0], argv[i + 1], a);
		i++;
	}
	return (argv[0]);
}

char	**parse(int argc, char **argv)
{
	int		i;
	char	*temp;
	char	**tab;

	i = 0;
	temp = concatenate(argc, argv);
	tab = ft_split(temp, ' ');
	if (!tab)
		error_message(NULL);
	while (tab[i])
		i++;
	tab[i] = NULL;
	return (tab);
}
