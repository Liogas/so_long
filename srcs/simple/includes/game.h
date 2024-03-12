/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:37:20 by glions            #+#    #+#             */
/*   Updated: 2024/03/12 19:50:40 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "./parsing.h"
# include "../../minilibx/mlx.h"
# include "../../minilibx/mlx_int.h"
# include <X11/keysym.h>

typedef struct	s_image42
{
	void	*ptr;
	int		width;
	int		height;
	int		posx;
	int		posy;
	void	*mlx;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_image42;

typedef struct	s_window42
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_image42	*img_bckg;
}	t_window42;

typedef struct s_game
{
	void		*mlx;
	t_window42	*win;
	t_map	*map;
	
}	t_game;

t_window42  *window42_new(void *mlx, int sy, int sx);
void    	window42_free(t_window42 *win);

t_image42	*image42_new(int h, int w, char *path, void *mlx);
void	image42_free(t_image42 *image);

t_game	*game_new(t_parsing *p);
void	game_free(t_game *game);
int	game_start(t_game *g);

int	show_map(t_game *game);

#endif