NAME = client server
CC = clang
CFLAG = -Wall -Wextra -Werror -I. -g
# o que eh -I. -g

# sources (libft / server / client)

LIBFT_DIR = libft

LIB_SOURCE = $(wildcard $(LIBFT_DIR)/*.c) 
SER_SOURCE = server.c
CLI_SOURCE = client.c

# objects (libft / server / client)

OBJ_DIR = objs

LIB_OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(LIB_SOURCE))
SER_OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SER_SOURCE))
CLI_OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(CLI_SOURCE))
# o que eh patsubst

vpath %.c $(LIBFT_DIR)

all: $(NAME)

client: $(CLI_OBJ) $(LIB_OBJ)
	$(CC) $(CFLAG) -o $@ $^

server: $(SER_OBJ) $(LIB_OBJ)
	$(CC) $(CFLAG) -o $@ $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAG) -c $< -o $@
# para que servem os simbolos $@ - $^ - $<

bonus: all

clean:
	@rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re