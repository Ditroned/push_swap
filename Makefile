# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 21:55:42 by ppizzo            #+#    #+#              #
#    Updated: 2021/10/01 11:35:45 by ppizzo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= push_swap.c push_swap_action.c push_swap_action1.c push_swap_action2.c push_swap_action3.c push_swap_action4.c push_swap_action5.c push_swap_action6.c push_swap_action7.c push_swap_action8.c push_swap_action9.c ft_split.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc -o

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

NAME	=	push_swap

all		:	$(NAME)


$(NAME)	:	$(OBJS)
			@$(MAKE) -C libft
			cp libft/libft.a $(NAME)
			$(CC) $(NAME) $(OBJS) -I. 

clean :
						$(RM) $(OBJS) 

fclean	:			clean
						$(RM) $(NAME) | (cd Libft/;make fclean)

re	:				fclean $(NAME)

.PHONY:				all clean fclean re
