INCLUDES		=	-I./includes/ -I./gl_mlx/minilibx/

PATH_LIBFT		=	./gl_libft/
SRCS_LIBFT		=	$(PATH_LIBFT)ft_char/ft_isalpha.c $(PATH_LIBFT)ft_char/ft_isdigit.c $(PATH_LIBFT)ft_char/ft_isalnum.c $(PATH_LIBFT)ft_char/ft_isascii.c \
					$(PATH_LIBFT)ft_char/ft_isprint.c $(PATH_LIBFT)ft_char/ft_toupper.c $(PATH_LIBFT)ft_char/ft_tolower.c \
\
					$(PATH_LIBFT)ft_mem/ft_memset.c $(PATH_LIBFT)ft_mem/ft_bzero.c $(PATH_LIBFT)ft_mem/ft_memcpy.c $(PATH_LIBFT)ft_mem/ft_memmove.c \
					$(PATH_LIBFT)ft_mem/ft_memchr.c $(PATH_LIBFT)ft_mem/ft_memcmp.c \
\
					$(PATH_LIBFT)ft_str/ft_strlcpy.c $(PATH_LIBFT)ft_str/ft_strlcat.c $(PATH_LIBFT)ft_str/ft_strlen.c $(PATH_LIBFT)ft_str/ft_strchr.c \
					$(PATH_LIBFT)ft_str/ft_strrchr.c $(PATH_LIBFT)ft_str/ft_strncmp.c $(PATH_LIBFT)ft_str/ft_strcmp.c $(PATH_LIBFT)ft_str/ft_strnstr.c \
					$(PATH_LIBFT)ft_str/ft_strupper.c $(PATH_LIBFT)ft_str/ft_strdup.c $(PATH_LIBFT)ft_str/ft_strndup.c $(PATH_LIBFT)ft_str/ft_substr.c \
					$(PATH_LIBFT)ft_str/ft_strjoin.c $(PATH_LIBFT)ft_str/ft_constr.c $(PATH_LIBFT)ft_str/ft_strtrim.c $(PATH_LIBFT)ft_str/ft_split.c \
					$(PATH_LIBFT)ft_str/ft_strmapi.c $(PATH_LIBFT)ft_str/ft_striteri.c \
\
					$(PATH_LIBFT)ft_free/ft_free_tab2D_int_gl.c \
\
					$(PATH_LIBFT)ft_conv/ft_atoi.c $(PATH_LIBFT)ft_conv/ft_itoa.c $(PATH_LIBFT)ft_conv/ft_utoa.c $(PATH_LIBFT)ft_conv/ft_ptoa.c \
					$(PATH_LIBFT)ft_conv/ft_itoa_hex.c \
\
					$(PATH_LIBFT)ft_dup/ft_dup_tab2D_int_gl.c \
\
					$(PATH_LIBFT)ft_put/ft_putchar_fd.c $(PATH_LIBFT)ft_put/ft_putstr_fd.c $(PATH_LIBFT)ft_put/ft_putendl_fd.c $(PATH_LIBFT)ft_put/ft_putnbr_fd.c \
					$(PATH_LIBFT)ft_put/ft_putnbr_u_fd.c $(PATH_LIBFT)ft_put/ft_putnbr_hex_fd.c $(PATH_LIBFT)ft_put/ft_putptr_hex_fd.c $(PATH_LIBFT)ft_put/ft_put_tab2D_int_gl.c\
\
					$(PATH_LIBFT)ft_alloc/ft_calloc.c
OBJS_LIBFT		=	$(SRCS_LIBFT:.c=.o)

PATH_GNL		=	./gl_gnl/
SRCS_GNL		=	$(PATH_GNL)gnl_utils.c $(PATH_GNL)gnl.c
OBJS_GNL		=	$(SRCS_GNL:.c=.o)

PATH_LIST		=	./gl_list/
SRCS_LIST		=	$(PATH_LIST)add_list_gl.c $(PATH_LIST)free_list_gl.c $(PATH_LIST)new_element_gl.c
OBJS_LIST		=	$(SRCS_LIST:.c=.o)

PATH_FILE		=	./gl_file/
SRCS_FILE		=	$(PATH_FILE)gl_file.c
OBJS_FILE		=	$(SRCS_FILE:.c=.o)

PATH_UTILS		=	./gl_utils/
SRCS_UTILS		=	$(PATH_UTILS)verif_extension.c
OBJS_UTILS		=	$(SRCS_UTILS:.c=.o)

PATH_MLX		=	./gl_mlx/
SRCS_MLX		=	$(PATH_MLX)image/mlx_create_img_gl.c $(PATH_MLX)image/mlx_free_img_gl.c \
					$(PATH_MLX)image/mlx_load_img_gl.c  $(PATH_MLX)image/mlx_print_image_data_gl.c \
					$(PATH_MLX)image/utils/mlx_image_put_image_gl.c  $(PATH_MLX)image/utils/mlx_image_get_sprite_by_name_gl.c \
					$(PATH_MLX)image/utils/mlx_image_put_pixel_gl.c  $(PATH_MLX)image/utils/mlx_image_get_pixel_gl.c \
\
					$(PATH_MLX)sprite/mlx_create_sprite_gl.c $(PATH_MLX)sprite/mlx_free_sprite_gl.c \
					$(PATH_MLX)sprite/mlx_print_sprite_data_gl.c \
\
					$(PATH_MLX)window/mlx_create_win_gl.c $(PATH_MLX)window/mlx_free_win_gl.c \
					$(PATH_MLX)window/mlx_print_window_data_gl.c \
\
					$(PATH_MLX)animation/mlx_create_animation_gl.c $(PATH_MLX)animation/mlx_free_animation_gl.c \
					$(PATH_MLX)animation/mlx_print_animation_data_gl.c $(PATH_MLX)animation/utils/mlx_animation_put_to_img_gl.c\
\
					$(PATH_MLX)object/mlx_create_object_gl.c $(PATH_MLX)object/mlx_free_object_gl.c \
					$(PATH_MLX)object/mlx_print_object_data_gl.c \
\
					$(PATH_MLX)mlx_init_gl.c $(PATH_MLX)mlx_free_gl.c \
					$(PATH_MLX)mlx_print_data_gl.c $(PATH_MLX)utils/mlx_addobject_gl.c \
					$(PATH_MLX)utils/mlx_addimage_gl.c $(PATH_MLX)utils/mlx_addsprite_gl.c \
					$(PATH_MLX)utils/mlx_addanimation_gl.c $(PATH_MLX)utils/mlx_get_image_by_name_gl.c \
					$(PATH_MLX)utils/mlx_get_object_by_name_gl.c $(PATH_MLX)utils/mlx_get_animation_by_name_gl.c 
OBJS_MLX		=	$(SRCS_MLX:.c=.o)

OBJS_LIB		=	$(OBJS_LIBFT) $(OBJS_GNL) $(OBJS_LIST) $(OBJS_FILE) $(OBJS_UTILS) $(OBJS_MLX)

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra
AR				=	ar -rcs
LIB				=	../lib/libft.a
MINILIBX		=	./gl_mlx/minilibx/libmlx_Linux.a

all : $(LIB)

%.o: %.c
	@$(CC) $(CFLAGS) -g3 -o $@ -c $^ $(INCLUDES)

$(LIB): $(MINILIBX) $(OBJS_LIB)
	@echo "MINILIBX ✅"
	@echo "LIBFT    ❌"
	@mkdir -p ../lib
	@$(AR) $(LIB) $(OBJS_LIB)
	@clear
	@echo "MINILIBX ✅"
	@echo "LIBFT    ✅"

$(MINILIBX):
	@echo "MINILIBX ❌"
	@echo "LIBFT	 ❌"
	@make -C gl_mlx/minilibx/
	@clear
	@echo "MINILIBX ✅"
	@echo "LIBFT    ❌"

clean:
	@make -C gl_mlx/minilibx/ clean
	@rm -f $(OBJS_LIB)

fclean: clean
	@rm -drf lib
	@rm -f $(LIB)
	clear
	@echo "MINILIBX ❌"
	@echo "LIBFT    ❌"

re: fclean $(LIB)

.phony: all re clean fclean