CC					=	cc
CFLAGS				=	-Wall -Werror -Wextra

LIBFT				=	./libs/libft.a
MINILIBX			=	./srcs/minilibx/libmlx.a

PATH_FILE42			=	srcs/file42
SRCS_FILE42			=	$(PATH_FILE42)/models/*.c \
						$(PATH_FILE42)/views/*.c

PATH_VALIDATOR_MAP	=	srcs/validator_map
SRCS_VALIDATOR_MAP	=	$(PATH_VALIDATOR_MAP)/models/*.c \
						$(PATH_VALIDATOR_MAP)/views/*.c \
						$(PATH_VALIDATOR_MAP)/controllers/*.c

PATH_SRCS			=	srcs/core
SRCS				=	$(PATH_SRCS)/*.c \
						$(PATH_SRCS)/game/*.c \
						$(PATH_SRCS)/parsing/*.c \
						$(PATH_SRCS)/parsing/*/*.c \

PATH_GNL			=	srcs/gnl
SRCS_GNL			=	$(PATH_GNL)/*.c \

PATH_PRINTF			=	srcs/ft_printf
SRCS_PRINTF			=	$(PATH_PRINTF)/ft_printf.c \
						$(PATH_PRINTF)/convprintf/*.c \
						$(PATH_PRINTF)/charprintf/*.c \
						$(PATH_PRINTF)/paramsprintf/*.c \
						$(PATH_PRINTF)/lstprintf/*.c

NAME				=	so_long
AR					=	ar -rcsv

MAP_TEST			= 	./srcs/maps/map2.ber

all: $(NAME)

$(LIBFT):
	@make -C srcs/libft/

$(MINILIBX):
	@make -C srcs/minilibx/

$(NAME): $(LIBFT) $(MINILIBX)
	@$(CC) -g3 -o $(NAME) $(CFLAGS) $(SRCS) $(SRCS_FILE42) $(SRCS_GNL) $(SRCS_PRINTF) -L./srcs/libs -lft -L./srcs/minilibx -lmlx_Linux -lXext -lX11 -lm
	
clean:
	rm -f $(PATH_SRCS)/game/*.o $(PATH_SRCS)/parsing/*.o $(PATH_SRCS)/parsing/algo_verif/*.o

fclean: clean
	rm -f srcs/libs/*.a *.out $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean test_s test_v test_graph re
