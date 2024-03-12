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

PATH_SRCS			=	srcs/so_long
SRCS				=	$(PATH_SRCS)/controller/*.c \
						$(PATH_SRCS)/model/*/*.c \
						$(PATH_SRCS)/view/*/*.c \

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

TEST_GRAPH			= 	test_g
SRCS_TEST			= 	test/*.c

SRCS_MANDATORY		= 	srcs/simple/*.c \
						srcs/simple/*/*.c \
						srcs/simple/*/*/*.c
MANDATORY			= 	mandatory

all: $(NAME)

$(LIBFT):
	@make -C srcs/libft/

$(MINILIBX):
	@make -C srcs/minilibx/

$(NAME): $(LIBFT) $(MINILIBX)
	@$(CC) -g3 -o $(NAME) $(CFLAGS) $(SRCS_VALIDATOR_MAP) $(SRCS_FILE42) $(SRCS_GNL) $(SRCS_PRINTF) -L./srcs/libs -lft -L./srcs/minilibx -lmlx_Linux -lXext -lX11 -lm

$(TEST_GRAPH):
	$(CC) $(CFLAGS) -g3 -o $(TEST_GRAPH) $(SRCS_TEST) -L./srcs/minilibx -lmlx -lXext -lX11 -lm

$(MANDATORY): $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) -g3 -o $(MANDATORY) $(SRCS_MANDATORY) $(SRCS_FILE42) $(SRCS_GNL) $(SRCS_PRINTF) -L./srcs/libs -lft -L./srcs/minilibx -lmlx -lXext -lX11 -lm
	
clean:
	rm -f srcs/*/*.o srcs/*/*/*.o srcs/*/*/*/*.o

fclean: clean
	rm -f srcs/libs/*.a *.out $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean test_s test_v test_graph re
