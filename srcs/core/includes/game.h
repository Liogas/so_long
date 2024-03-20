/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:37:20 by glions            #+#    #+#             */
/*   Updated: 2024/03/20 12:13:16 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../../minilibx/mlx.h"
# include "../../minilibx/mlx_int.h"
# include "./parsing.h"
# include <X11/keysym.h>

typedef struct s_player
{
	t_coord		*pos;
	int			nb_object;
}				t_player;

typedef struct s_window42
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_image42	*bg;
}				t_window42;

typedef struct s_draw
{
	t_image42	**img_wolf;
	t_image42	**img_object;
	t_image42	*img_floor;
	t_image42	*img_exit;
	t_image42	*img_exit_player;
	t_image42	*img_food;
	t_image42	**imgs_number;
	int			nb_obj;
	int			d_wolf;
}				t_draw;

typedef struct s_game
{
	void		*mlx;
	t_window42	*win;
	t_map		*map;
	t_player	*player;
	t_draw		*data_draw;
	int			nb_dep;
	int			winner;
}				t_game;

t_window42		*window42_new(void *mlx, int sy, int sx);
void			window42_free(t_window42 *win);

t_image42		*image42_file_new(int h, int w, char *path, void *mlx);
void			image42_free(t_image42 *image);
void			imgs_free(t_image42 **imgs, int size);
void			put_img_to_img(t_image42 *dst, t_image42 *src, int x, int y);
t_image42		*image42_new(int w, int h, void *mlx);

t_game			*game_new(t_parsing *p);
void			game_free(t_game *game);
int				game_start(t_game *g);
void			verif_win(t_game *g);

int				show_map(t_game *game);
int				draw_img(t_game *g);
void			draw_score(t_game *game);
void			draw_map(t_game *game, int pos[2]);
void			draw_obj(t_game *g, int y, int x, t_draw *data);

t_player		*new_player(t_game *game);

void			moove(t_game *g, int dir);

t_draw			*draw_new(void);
void			draw_free(t_draw *draw);
void			set_size_map(t_game *game);

int				load_imgs(t_game *game);
int				load_imgs_wolf(t_game *game);
int				load_imgs_object(t_game *game);

#endif