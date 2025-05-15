
NAME = ./minishell
CC = cc
CFLAGS = #-Wall -Wextra -Werror -g3 #-fsanitize=address -g

#hadi hi fmac
LDFLAGS = -L/usr/local/opt/readline/lib -I/usr/local/opt/readline/include -lreadline -lhistory

#hadi linux
#LDFLAGS = -lreadline -lhistory

SRC =	src/main.c src/garbege_collecter.c\
		parsing/signals/siganl.c \
		parsing/lexer/lexer.c \
		parsing/expander/expand.c \
		helper/helper_1.c helper/helper_linkedlist.c

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all clean
