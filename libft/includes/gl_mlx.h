/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 00:40:22 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 14:43:28 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_MLX_H
# define GL_MLX_H

# include "gl_libft.h"
# include "gl_list.h"
# include "gnl.h"
# include "mlx.h"
# include "mlx_int.h"
# include <X11/keysym.h>

typedef struct s_mlx_sprite_gl
{
	char			*name;
	int				height_frame;
	int				width_frame;
	int				nb_frames;
	int				pos_y;
}					t_mlx_sprite_gl;

typedef struct s_mlx_image_gl
{
	char			*name;
	void			*ptr;
	void			*mlx_ptr;
	int				height;
	int				width;
	int				bpp;
	int				endian;
	int				line_len;
	char			*addr;
	t_list_gl		*sprites;
}					t_mlx_image_gl;

typedef struct s_mlx_animation_gl
{
	char			*sprite_name;
	t_mlx_image_gl	*img;
	int				cur_f;
	int				time;
	int				time_d;
}					t_mlx_animation_gl;

typedef struct s_mlx_object_gl
{
	char			*name;
	int				pos_x;
	int				pos_y;
	char			*curr_anim;
	t_list_gl		*animations;
	void			*data;
}					t_mlx_object_gl;

typedef struct s_mlx_camera_gl
{
	char			*name;
	int				pos_x;
	int				pos_y;
	int				width;
	int				height;
	t_mlx_image_gl	*bckgd;
	t_mlx_object_gl	*target;
	void			*more_data;
}					t_mlx_camera_gl;

typedef struct s_mlx_window_gl
{
	void			*mlx_ptr;
	void			*ptr;
	int				width;
	int				height;
	t_mlx_image_gl	*bckgd;
}					t_mlx_window_gl;

typedef struct s_mlx_gl
{
	void			*ptr;
	t_mlx_window_gl	*window;
	t_list_gl		*images;
	t_list_gl		*objects;
	t_list_gl		*cameras;
}					t_mlx_gl;

// MLX
t_mlx_gl			*mlx_init_gl(void);
t_mlx_gl			*mlx_init_with_window_gl(int width_window,
						int height_window, char *title_window);
void				mlx_free_gl(t_mlx_gl *mlx);
int					mlx_addobject_gl(t_mlx_gl *mlx, t_mlx_object_gl *object);
int					mlx_addimage_gl(t_mlx_gl *mlx, t_mlx_image_gl *image);
int					mlx_addsprite_gl(t_mlx_gl *mlx, char *img_name,
						t_mlx_sprite_gl *sprite);
int					mlx_addanimation_gl(t_mlx_gl *mlx, char *object_name,
						char *name, t_mlx_animation_gl *animation);
int					mlx_addcamera_gl(t_mlx_gl *mlx, t_mlx_camera_gl *camera);
t_mlx_camera_gl		*mlx_get_camera_by_name_gl(t_mlx_gl *mlx,
						char *camera_name);
t_mlx_image_gl		*mlx_get_image_by_name_gl(t_mlx_gl *mlx, char *name);
t_mlx_object_gl		*mlx_get_object_by_name_gl(t_mlx_gl *mlx, char *name);
t_mlx_animation_gl	*mlx_get_animation_by_name_gl(t_mlx_gl *mlx,
						char *object_name, char *animation_name);
void				mlx_animation_put_to_img_gl(t_mlx_gl *mlx,
						t_mlx_object_gl *object, t_mlx_animation_gl *animation,
						t_mlx_image_gl *dst);

// WINDOW
t_mlx_window_gl		*mlx_create_win_gl(t_mlx_gl *mlx, int width, int height,
						char *title);
void				mlx_free_win_gl(t_mlx_gl *mlx, t_mlx_window_gl *window);
void				mlx_print_window_data_gl(t_mlx_window_gl *window);

// ANIMATION
t_mlx_animation_gl	*mlx_create_animation_gl(t_mlx_image_gl *img, char *name,
						int time_delay);
void				mlx_free_animation_gl(t_mlx_animation_gl *animation);
void				mlx_print_animation_data_gl(t_mlx_animation_gl *animation);

// OBJECT
t_mlx_object_gl		*mlx_create_object_gl(char *name, int pos_x, int pos_y,
						void *data);
void				mlx_free_object_gl(t_mlx_object_gl *object);
void				mlx_print_object_data_gl(t_mlx_object_gl *object);
int					mlx_object_set_curr_animation_gl(t_mlx_gl *mlx,
						char *object_name, char *animation_name);

// IMAGE
t_mlx_image_gl		*mlx_load_img_gl(t_mlx_gl *mlx, char *path, char *name);
t_mlx_image_gl		*mlx_create_img_gl(t_mlx_gl *mlx, int width, int height,
						char *name);
void				mlx_free_img_gl(t_mlx_gl *mlx, t_mlx_image_gl *img);
void				mlx_print_image_data_gl(t_mlx_image_gl *image);
t_mlx_sprite_gl		*mlx_image_get_sprite_by_name_gl(t_mlx_image_gl *image,
						char *sprite_name);
void				mlx_image_put_pixel_gl(t_mlx_image_gl *img, int x, int y,
						int color);
unsigned int		mlx_image_get_pixel_gl(t_mlx_image_gl *img, int x, int y);
void				mlx_image_put_image_gl(t_mlx_image_gl *dst,
						t_mlx_image_gl *src, int x, int y);
void				mlx_image_put_image_limit_gl(t_mlx_image_gl *dst,
						t_mlx_image_gl *src, int pos[2], int limit[2]);
void				mlx_image_put_area_image_gl(t_mlx_image_gl *dst,
						t_mlx_image_gl *src, int pos[2], int size[2]);
void				mlx_image_put_area_image2_gl(t_mlx_image_gl *dst,
						t_mlx_image_gl *src, int pos[2], int size[2]);
// SPRITE
t_mlx_sprite_gl		*mlx_create_sprite_gl(char *name, int pos_y, int nb_frame,
						int size_frame[2]);
void				mlx_free_sprite_gl(t_mlx_sprite_gl *sprite);
void				mlx_print_sprite_data_gl(t_mlx_sprite_gl *sprite);

// CAMERA
void				mlx_camera_free_gl(t_mlx_gl *mlx, t_mlx_camera_gl *camera);
t_mlx_camera_gl		*mlx_camera_create_gl(char *name, t_mlx_object_gl *target,
						int pos[2], int size[2]);
void				mlx_camera_update_pos_gl(t_mlx_camera_gl *camera,
						int new_pos[2]);
void				mlx_camera_set_moredata_gl(void *more_data,
						t_mlx_camera_gl *camera);

#endif