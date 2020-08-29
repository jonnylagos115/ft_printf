# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlagos <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/30 16:53:27 by jlagos            #+#    #+#              #
#    Updated: 2019/05/30 16:53:30 by jlagos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

DIR_S = srcs

OBJS_1 = $(patsubst %.c,%.o,$(wildcard ./srcs/*.c))
OBJS_2 = $(patsubst %.c,%.o,$(wildcard ./srcs/handle_datatypes/*.c))
OBJS_3 = $(patsubst %.c,%.o,$(wildcard ./srcs/bonus_/*.c));

silent:
	@make all -s

all: $(NAME)

$(NAME): $(OBJS_1) $(OBJS_2)
	$(MAKE) all -C libft_1
	@cp libft_1/libft.a ./$(NAME)
	@ar -rcs $(NAME) $(OBJS_1) $(OBJS_2)
	@ranlib $(NAME)

clean:
	@make clean -C libft_1 -s
	@rm -f $(OBJS_1) $(OBJS_2)

fclean: clean
	-@rm -f $(NAME)
	-@make fclean -C libft_1 -s

re: fclean all
