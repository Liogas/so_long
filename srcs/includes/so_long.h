/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:43:25 by glions            #+#    #+#             */
/*   Updated: 2024/05/10 09:37:54 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"

typedef struct s_camera
{
	int			start[2];
	int			end[2];
	int			mode_y;
	int			mode_x;
}				t_camera;

typedef struct s_map
{
	int			height;
	int			width;
	int			**tab;
	int			player_y;
	int			player_x;
}				t_map;

typedef struct s_player
{
	int			pos_x;
	int			pos_y;
	int			pos_pixel_x;
	int			pos_pixel_y;
	int			target_x;
	int			target_y;
	int			direction;
}				t_player;

typedef struct s_game
{
	t_mlx_gl	*graph_data;
	t_map		*map;
	t_player	*player;
	t_camera	*camera;
	int			win;
	int			turns;
	int			sheeps;
	int			minimap;
}				t_game;

// CAMERA
t_camera		*new_camera(void);
void			free_camera(t_camera *camera);

// MAP
t_map			*new_map(int height, int width);
void			free_map(t_map *map);

// PLAYER
t_player		*new_player(int y, int x);
void			free_player(t_player *player);
void			update_pos_player(t_player *player, int pos_y, int pos_x,
					t_mlx_object_gl *obj);

// GAME
t_game			*new_game(t_map *map);
void			free_game(t_game *game);

// PARSING
t_map			*parsing(t_map *map, t_file_gl *file);
int				c_is_valid(char c);
int				can_go(int c);
void			fill(int **tab, int size[2], int cur[2]);
void			set_start_player(t_map *map);

// GRAPH
int				graph_setup(t_game *game);
int				graph_addborder(t_game *game);
int				graph_addplayer(t_game *game);
int				graph_addwall(t_game *game);
int				graph_addexit(t_game *game);
int				graph_addcollect(t_game *game);
int				graph_addbackgmap(t_game *game);
int				graph_drawplayer(int pos[2], t_game *game, t_mlx_image_gl *dst);
int				graph_drawwall(int y, int x, t_game *game, t_mlx_image_gl *dst);
int				graph_drawexit(int y, int x, t_game *game, t_mlx_image_gl *dst);
int				graph_draw_exit_player(int y, int x, t_game *game,
					t_mlx_image_gl *dst);
int				graph_drawcollect(int y, int x, t_game *game,
					t_mlx_image_gl *dst);
int				graph_drawfloor(int y, int x, t_game *game,
					t_mlx_image_gl *dst);
int				graph_setup_cam(t_game *game, t_mlx_camera_gl *camera);
int				graph_draw_world(t_game *game, t_mlx_camera_gl *camera);
int				graph_update_animations(t_game *game);
int				graph_show_map(t_game *game);
int				graph_draw_map_border(t_game *game, int h, int w,
					int size_tile[2]);

// GAME
int				game_moove_right(t_game *game);
int				game_moove_left(t_game *game);
int				game_moove_down(t_game *game);
int				game_moove_up(t_game *game);

#endif