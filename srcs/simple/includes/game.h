/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:37:20 by glions            #+#    #+#             */
/*   Updated: 2024/03/13 15:42:20 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../../minilibx/mlx.h"
# include "../../minilibx/mlx_int.h"
# include "./parsing.h"
# include <X11/keysym.h>

typedef struct s_window42
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_image42	*bg;
}				t_window42;

typedef struct s_game
{
	void		*mlx;
	t_window42	*win;
	t_map		*map;
}				t_game;

t_window42		*window42_new(void *mlx, int sy, int sx);
void			window42_free(t_window42 *win);

t_image42		*image42_file_new(int h, int w, char *path, void *mlx);
void			image42_free(t_image42 *image);
void			put_img_to_img(t_image42 *dst, t_image42 *src, int x, int y);
void			put_pixel_img(t_image42 *img, int x, int y, int color);
unsigned int	get_pixel_img(t_image42 *img, int x, int y);
t_image42		*image42_new(int w, int h, void	*mlx);

t_game			*game_new(t_parsing *p);
void			game_free(t_game *game);
int				game_start(t_game *g);

int				show_map(t_game *game);

#endif