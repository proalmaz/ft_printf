# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vping <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 13:17:22 by vping             #+#    #+#              #
#    Updated: 2020/12/27 17:28:59 by vping            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	base/ft_printf.c \
		processor/ft_char.c \
		processor/ft_width_output.c \
		processor/ft_int.c \
		processor/ft_percent.c \
		processor/ft_string.c \
		processor/ft_pointer.c \
		processor/ft_hex.c \
		processor/ft_unsigned_int.c \
		parser/ft_flag_definition.c \
		parser/ft_parser.c \
		libft/ft_isdigit.c \
		libft/ft_bzero.c \
		libft/ft_unsigned_itoa.c \
		libft/ft_str_tolower.c \
		libft/ft_string_output_prec.c \
		libft/ft_strnew.c \
		libft/ft_itoa.c \
		libft/ft_putchar.c \
		libft/ft_strdup.c \
		libft/ft_strlen.c \
		libft/ft_tolower.c \
		libft/ft_converter.c \

INCLUDES = includes/ft_printf.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS = ${SRC:.c=.o}

all: ${NAME}

${NAME}:${OBJS}
	ar rcs ${NAME} ${OBJS}

%.o: %.c
	$(CC) $(CFLAGS) -c -g $< -o $@

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all