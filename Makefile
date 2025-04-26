
NAME = ./minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror

#hadi hi fmac
LDFLAGS = -L/usr/local/opt/readline/lib -I/usr/local/opt/readline/include -lreadline -lhistory

#hadi linux
#LDFLAGS = -lreadline -lhistory

SRC =	src/main.c \
		parsing/signals/siganl.c

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all clean
