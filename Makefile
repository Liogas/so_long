INCLUDES		=	-I./srcs/includes/ -I./libft/includes/ -I./libft/gl_mlx/minilibx/

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra -g3
LIB				=	./lib/libft.a

PATH_GAME		=	srcs/
SRCS_GAME		=	srcs/main.c
OBJS_GAME		=	$(SRCS_GAME:.c=.o)
NAME			=	so_long
MINILIBX		=	./libft/gl_mlx/minilibx/libmlx_Linux.a

all : $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $^ $(INCLUDES)

$(NAME): $(LIB) $(MINILIBX) $(OBJS_GAME)
	@clear
	@echo "MINILIBX ✅"
	@echo "LIBFT    ✅"
	@echo "SO_LONG  ❌"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS_GAME) $(LIB) $(MINILIBX) $(INCLUDES) -lXext -lX11 -lm
	@clear
	@echo "MINILIBX ✅"
	@echo "LIBFT    ✅"
	@echo "SO_LONG  ✅"
	@echo "👌👌👌👌👌👌👌👌👌👌👌👌👌👌👌👌👌👌👌👌👌"

$(LIB):
	@make -C libft

$(MINILIBX):
	@make -C ./libft/gl_mlx/minilibx/
	@clear
	@echo "MINILIBX ✅"
	@echo "LIBFT    ✅"

push:
	@make fclean
	@git add .
	@git commit -m "Utilisation de push : ptetre plus d'infos dans le README"
	@git push

clean:
	@make -C libft clean
	@rm -f $(OBJS_GAME)

fclean: clean
	rm -f $(LIB) $(NAME)
	rm -drf lib

re: fclean $(NAME)

.phony: all re clean fclean push