# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 13:58:56 by cproesch          #+#    #+#              #
#    Updated: 2021/10/14 16:01:45 by cproesch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	sources/main.c \
				sources/init_stack_a.c \
				sources/parsing.c \
				sources/operations/swap.c \
				sources/operations/rotate.c \
				sources/operations/reverse_rotate.c \
				sources/operations/push.c \
				sources/sorts/small_sort.c \
				sources/sorts/big_sort.c \
				sources/utils/big_sort_utils.c \
				sources/utils/list_utils.c \
				sources/utils/check_inputs.c \
				sources/utils/del_exit_utils.c \
				sources/utils/other_utils.c \
				sources/utils/already_sorted_utils.c \
				sources/utils/tests_utils.c

OBJS		=	$(SRCS:.c=.o)

NAME		=	push_swap

CC			=	gcc  

IFLAGS		=	-I. -Ilibft

CFLAGS		=	-Wall -Wextra -Werror $(IFLAGS) 

LFLAGS		=	-Llibft -lft

RM			=	rm -rf

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJS)
				make -C libft
				$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

all:			$(NAME)

clean:	
				make -C libft -f Makefile clean
				$(RM) $(OBJS) $(OBJS_B)

fclean:			clean
				make -C libft -f Makefile fclean
				$(RM) $(NAME)

re:				fclean all

bonus:			$(OBJS_B)
				make -C libft
				$(CC) $(OBJS_B) $(LFLAGS) -o push_swap_bonus

.PHONY:			all clean fclean re
