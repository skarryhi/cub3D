NAME = cub3d
HEADERS = ./cub/libcub.h
CFLAGS = -Wall -Werror -Wextra

SRC = ./cub/read_map.c ./cub/errors.c ./cub/parser1.c\
	./cub/parser2.c ./cub/colour.c ./cub/hooks.c \
	./cub/raycast.c main.c ./cub/texture_on_wall.c \
	./cub/colour2.c ./cub/parser3.c ./cub/parser4.c \
	./cub/colour3.c ./cub/sprite.c ./cub/sprite2.c

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft all
	$(MAKE) -C minilibx
	gcc $(OBJ) ./libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(CFLAGS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean:	clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re:		fclean all

bonus: all

norm: 
	norminette ./cub/*.c ./libft/*.c main.c

cubnorm:
	norminette ./cub/*.c

.PHONY: all clean fclean re bonus norm cubnorm