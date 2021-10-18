/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:11:36 by cproesch          #+#    #+#             */
/*   Updated: 2021/10/14 18:35:29 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				nb;
	int				original;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

typedef struct s_set
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*int_tab;
	char	**char_tab;
}	t_set;

t_stack	*new_element(t_set *set, int nb, char *str);
t_stack	*last_element(t_stack *lst);
void	add_back_element(t_stack **stack, t_stack *new);
int		stack_size(t_stack *lst);
void	ft_del_element(t_stack *stack);
void	ft_del_list(t_stack **stack);
void	error_message(t_set **set);
t_stack	*init_stack_a(t_set *set, int argc);
void	check_order(t_set *set, int *tab, int argc);
void	check_duplicates(t_set *set, int argc);
void	ft_swap(int *a, int *b);
int		*convert_nb(int argc, char **argv);
void	swap_a(t_set *set);
void	swap_b(t_set *set);
void	swap_ab(t_set *set);
void	rotate_a(t_set *set);
void	rotate_b(t_set *set);
void	rotate_ab(t_set *set);
void	reverse_rotate_a(t_set *set);
void	reverse_rotate_b(t_set *set);
void	reverse_rotate_ab(t_set *set);
void	push_a(t_set *set);
void	push_b(t_set *set);
void	small_sort(int argc, t_set *set);
int		determine_min(t_stack *stack);
int		determine_max(t_stack *stack);
int		locate_nb(t_stack *stack, int nb);
void	big_sort(t_set *set);
void	shift_one_stack(t_stack *stack);
void	shift_right(t_set *set);
int		already_sorted(int x, int size_to_sort, t_stack *stack);
int		already_sorted_2(int size_to_sort, t_stack *stack);
int		end_already_sorted(int x, int size_to_sort, t_stack *stack);
int		nb_shifts(t_set *set);
int		ft_atoi_ps(t_set *set, const char *str);
void	ft_exit(t_set **set, int exit_code);
void	print_list(t_stack *stack);
void	print_tab(int *tab, int argc);
void	print_both_stacks(t_set *set);
char	**parse(int argc, char **argv);

#endif
