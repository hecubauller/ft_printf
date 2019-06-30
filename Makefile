# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shunt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/20 20:45:39 by shunt             #+#    #+#              #
#    Updated: 2019/05/29 17:35:44 by shunt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDE = ft_printf.h

FT_PRINTF_SRCS = ft_printf.c bfpr.c ft_s.c ft_d.c ft_c.c

LIBFT_SRCS = libft/ft_putstr.c libft/ft_putchar.c libft/ft_putnbr.c libft/ft_itoa.c libft/ft_strlen.c

OBJS += $(FT_PRINTF_SRCS:.c=.o)

OBJS += ft_putstr.o ft_putchar.o ft_putnbr.o ft_itoa.o ft_strlen.o

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c -I $(INCLUDE) -I libft/libft.h $(FT_PRINTF_SRCS) $(LIBFT_SRCS)
	@ar rc $(NAME) $(OBJS)

clean:
	@/bin/rm -rf *.o
	@make -C libft clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
