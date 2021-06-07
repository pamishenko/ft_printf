# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pavel <pavel@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/02 09:37:51 by pavel             #+#    #+#              #
#    Updated: 2021/05/06 17:17:45 by pavel            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c\
		ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
		ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c\
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c\
		\
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
		ft_itoa.c ft_strmapi.c ft_putchar_fd.c\
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BSRC	=	$(SRC) ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
		ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ = $(SRC:.c=.o)
BOBJ	= $(OBJ) $(BSRC:.c=.o)
HEADER	=	libft.h
CC = gcc
CFLAGS = -Wall -Werror -Wextra
ARRC = ar rc
REMOVE = rm -f
RANLIB = ranlib

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(ARRC) $(NAME) $(OBJ)
	$(RANLIB) $(NAME)

bonus:	$(NAME) $(BOBJ)
	$(ARRC) $(NAME) $(BOBJ)
	$(RANLIB) $(NAME)

.c.o:	$(SRC) $(BSRC)
	$(CC) -c $(CFLAGS) -I $(HEADER) $< -o ${<:.c=.o}

clean:
	$(REMOVE) $(OBJ) $(BOBJ)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: clean fclean all re