LIBFT = ./libft/
ADAPT = ./adaptation/
OUT = ./output/

SRC = ./libft/*.c ./libcub/*.c
OBJ = *.o

NAME = cubft.a
HEADER = ./libcub/libcub.h ./libft/libft.h ./libft/get_next_line.h

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)
$(NAME): $(OBJ)
	@ar rc $(NAME) $?
	@ranlib $(NAME)
%.o: %.c $(HEADER)
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:		clean all