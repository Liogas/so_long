CC					=	cc
CFLAGS				=	-Wall -Werror -Wextra

LIBFT				=	./libs/libft.a
MINILIBX			=	./srcs/minilibx/libmlx.a

PATH_FILE42			=	srcs/file42
SRCS_FILE42			=	$(PATH_FILE42)/models/file42.c

PATH_SRCS			=	srcs/core
SRCS				=	$(PATH_SRCS)/main.c \
						$(PATH_SRCS)/parsing.c \
						$(PATH_SRCS)/game/coord_utils.c \
						$(PATH_SRCS)/game/draw_map.c \
						$(PATH_SRCS)/game/draw_utils.c \
						$(PATH_SRCS)/game/game_utils.c \
						$(PATH_SRCS)/game/grid_utils.c \
						$(PATH_SRCS)/game/image42_utils.c \
						$(PATH_SRCS)/game/load_imgs.c \
						$(PATH_SRCS)/game/load_imgs2.c \
						$(PATH_SRCS)/game/map_utils.c \
						$(PATH_SRCS)/game/moove.c \
						$(PATH_SRCS)/game/player_utils.c \
						$(PATH_SRCS)/game/put_img_to_img.c \
						$(PATH_SRCS)/game/show_map.c \
						$(PATH_SRCS)/game/window42_utils.c \
						$(PATH_SRCS)/parsing/error_utils.c \
						$(PATH_SRCS)/parsing/parsing_utils.c \
						$(PATH_SRCS)/parsing/algo_verif/algo_verif_utils.c \
						$(PATH_SRCS)/parsing/algo_verif/algo_verif.c \
						$(PATH_SRCS)/parsing/algo_verif/items_algo_utils.c \
						$(PATH_SRCS)/parsing/algo_verif/mem_utils.c \
						$(PATH_SRCS)/parsing/algo_verif/moove_items.c \
						$(PATH_SRCS)/parsing/algo_verif/open_close_utils.c \
						$(PATH_SRCS)/parsing/algo_verif/pos_algo_utils.c

PATH_GNL			=	srcs/gnl
SRCS_GNL			=	$(PATH_GNL)/gnl.c \
						$(PATH_GNL)/gnl_utils.c

NAME				=	so_long
AR					=	ar -rcsv

MAP_TEST			= 	./srcs/maps/map2.ber

all: $(NAME)

$(LIBFT):
	make -C srcs/libft/

$(MINILIBX):
	make -C srcs/minilibx/

$(NAME): $(LIBFT) $(MINILIBX)
	$(CC) -g3 -o $(NAME) $(CFLAGS) $(SRCS) $(SRCS_FILE42) $(SRCS_GNL) $(SRCS_PRINTF) -L./srcs/libft -lft -L./srcs/minilibx -lmlx_Linux -lXext -lX11 -lm

bonus:	$(LIBFT) $(MINILIBX)
	$(CC) -g3 -o $(NAME) $(CFLAGS) $(SRCS) $(SRCS_FILE42) $(SRCS_GNL) $(SRCS_PRINTF) -D BONUS=1 -L./srcs/libft -lft -L./srcs/minilibx -lmlx_Linux -lXext -lX11 -lm

clean:
	rm -f $(PATH_SRCS)/game/*.o $(PATH_SRCS)/parsing/*.o $(PATH_SRCS)/parsing/algo_verif/*.o

fclean: clean
	make -C srcs/libft/ fclean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re
