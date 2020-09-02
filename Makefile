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

INCLUDES = -I./includes

SRCS = srcs/ft_printf.c \
					srcs/parse.c \
					srcs/handle_ag.c \
					srcs/handle_minw_prec.c \
					srcs/formatspecifer.c \
					srcs/print_args.c \
					srcs/handle_flags.c \
					srcs/handle_datatypes/handle_cstr.c \
					srcs/handle_datatypes/handle_hex.c \
					srcs/handle_datatypes/handle_int.c \
					srcs/handle_datatypes/handle_pointer.c \
					srcs/handle_datatypes/handle_uint.c

SRCSSB = bonus_/bonus.c

OBJS = $(SRCS:.c=.o)

OBJSB = $(OBJS) $(SRCSSB:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) all -C libft
	@cp libft/libft.a ./$(NAME)
	@ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	@make clean -C libft -s
	@rm -f $(OBJSB)

fclean: clean
	-@rm -f $(NAME)
	-@make fclean -C libft -s

re: fclean all

bonus: $(OBJSB)
	$(MAKE) all -C libft
	@cp libft/libft.a ./$(NAME)
	@ar -rcs $(NAME) $(OBJSB)
