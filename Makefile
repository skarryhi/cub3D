NAME = cub3d
HEADERS = ./libcub/libcub.h
CFLAGS = -Wall -Werror -Wextra

SRC = ./libcub/read_map.c ./libcub/errors.c ./libcub/f_to_stuct.c\
	./libcub/f_to_stuct2.c ./libcub/colour.c ./libcub/hooks.c \
	./libcub/raycast.c main.c ./libcub/texture_on_wall.c \
	./libcub/colour2.c

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft all
	$(MAKE) -C minilibx
	gcc $(OBJ) ./libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean:	clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re