# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 19:42:42 by cmoura-p          #+#    #+#              #
#    Updated: 2024/04/06 21:53:31 by cmoura-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAG = -Wall -Wextra -Werror -I. -g

# sources (libft / server / client / bonus)

LIBFT_DIR = libft

LIB_SOURCE 		= $(wildcard $(LIBFT_DIR)/*.c) 
SER_SOURCE 		= server.c
CLI_SOURCE 		= client.c
SER_SOURCE_B 	= server_bonus.c
CLI_SOURCE_B 	= client_bonus.c

# objects (libft / server / client)

OBJ_DIR = objs

LIB_OBJ 	= $(patsubst %.c, $(OBJ_DIR)/%.o, $(LIB_SOURCE))
SER_OBJ 	= $(patsubst %.c, $(OBJ_DIR)/%.o, $(SER_SOURCE))
CLI_OBJ 	= $(patsubst %.c, $(OBJ_DIR)/%.o, $(CLI_SOURCE))
SER_OBJ_B	= $(patsubst %.c, $(OBJ_DIR)/%.o, $(SER_SOURCE_B))
CLI_OBJ_B 	= $(patsubst %.c, $(OBJ_DIR)/%.o, $(CLI_SOURCE_B))

NAME 	= client server
NAME_B 	= client_bonus server_bonus

vpath %.c $(LIBFT_DIR)

all: $(NAME)

client: $(CLI_OBJ) $(LIB_OBJ)
	$(CC) $(CFLAG) -o $@ $^

server: $(SER_OBJ) $(LIB_OBJ)
	$(CC) $(CFLAG) -o $@ $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAG) -c $< -o $@

bonus: $(NAME_B)

client_bonus: $(CLI_OBJ_B) $(LIB_OBJ)
	$(CC) $(CFLAG) -o $@ $^

server_bonus: $(SER_OBJ_B) $(LIB_OBJ)
	$(CC) $(CFLAG) -o $@ $^

clean:
	$(RM)r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(NAME_B)

re: fclean all

.PHONY: all bonus clean fclean re