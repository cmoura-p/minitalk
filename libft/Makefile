# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/30 19:08:08 by cmoura-p          #+#    #+#              #
#    Updated: 2024/04/05 20:46:04 by cmoura-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	ft_atoi.c ft_putnbr.c ft_strlen.c ft_bzero.c ft_calloc.c ft_memset.c ft_strjoin.c
OBJS	= $(SRCS:.c=.o)

RM	= rm -f
AR	= ar -rcs

all: $(NAME)

$(NAME): $(OBJS)
	 $(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus