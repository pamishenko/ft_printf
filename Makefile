# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttanja <pamishenko@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/23 15:33:45 by pavel             #+#    #+#              #
#    Updated: 2021/06/08 17:21:34 by ttanja           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PRINTF_PATH = src/
FT_PRINTF_SRC = ft_printf.c \
				ft_convert_base.c ft_count_razryad.c ft_flag_init.c \
				ft_pointer_format.c ft_print_savesymbol.c \
				ft_putchar_format.c ft_putnumber_format.c \
				ft_putstring_format.c ft_unsigned_format.c \
				ft_xdigit_format.c ft_putpercent_format.c
LIBFT_PATH = libft/
LIBFT_SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
			ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c\
			ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
			ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c\
			ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
			ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c\
			\
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
			ft_itoa.c ft_strmapi.c ft_putchar_fd.c\
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJ += $(addprefix $(PRINTF_PATH),$(FT_PRINTF_SRC:.c=.o))
OBJ += $(addprefix $(LIBFT_PATH),$(LIBFT_SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\nCreating $@"


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

t: $(NAME)
	$(CC) $(CFLAGS) -I $(HEADER) main.c $(NAME) -o test

.PHONY: all clean fclean re
