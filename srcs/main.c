/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:41:10 by glions            #+#    #+#             */
/*   Updated: 2024/04/30 15:29:28 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	refresh_animations(t_game *game)
{
	if (!graph_update_animations(game))
	{
		ft_putstr_fd("ERROR : update_animation\n", 2);
		mlx_loop_end(game->graph_data->ptr);
	}
	graph_draw_world(game, game->graph_data->cameras->content);
	return (0);
}

int	key_listener(int key, t_game *game)
{
	int	e;

	if (key == XK_Escape)
		mlx_loop_end(game->graph_data->ptr);
	else if (key == XK_m || key == XK_M)
		game->minimap *= -1;
	else if (!game->win)
	{
		e = 1;
		if (key == XK_z || key == XK_Z || key == XK_W || key == XK_w)
			e = game_moove_up(game);
		else if (key == XK_q || key == XK_Q || key == XK_a || key == XK_A)
			e = game_moove_left(game);
		else if (key == XK_d || key == XK_D)
			e = game_moove_right(game);
		else if (key == XK_s || key == XK_S)
			e = game_moove_down(game);
		if (!e)
			mlx_loop_end(game->graph_data->ptr);
		if (game->win)
			(ft_putstr_fd("Well done ! number of tantatives : ", 1),
				ft_putnbr_fd(game->turns, 1), ft_putchar_fd('\n', 1));
	}
	return (0);
}

static int	init_game(t_map *map, t_game **game)
{
	if (!map)
		return (0);
	*game = new_game(map);
	if (!*game)
		return (ft_putstr_fd("ERROR : new_game\n", 2), free_map(map), 0);
	if (!graph_setup(*game))
		return (0);
	return (1);
}

static int	start_game(t_game *game)
{
	if (!graph_draw_world(game, mlx_get_camera_by_name_gl(game->graph_data,
				"camera_0")))
		return (ft_putstr_fd("ERROR: draw_map\n", 2), 0);
	mlx_key_hook(game->graph_data->window->ptr, &key_listener, game);
	mlx_loop_hook(game->graph_data->ptr, &refresh_animations, game);
	mlx_loop(game->graph_data->ptr);
	return (1);
}

int	main(int ac, char **av)
{
	t_map		*map;
	t_file_gl	*file;
	t_game		*game;

	if (ac != 2)
		return (ft_putstr_fd("ERROR : try ./so_long [map_name]\n", 2), 1);
	if (!verif_extension(av[1], ".ber"))
		return (ft_putstr_fd("ERROR : Extension not valid. try ?.ber\n", 2), 1);
	file = new_file_gl(av[1], O_RDONLY);
	if (!file)
		return (ft_putstr_fd("ERROR : file doesn't exist\n", 2), 0);
	read_all_file_gl(file);
	if (!file->lines)
		return (ft_putstr_fd("ERROR : file empty\n", 2), free_file_gl(file), 1);
	map = new_map(file->nblines, ft_strlen_stop_c((char *)file->lines->content,
				'\n'));
	if (!map)
		return (ft_putstr_fd("ERROR : new_map\n", 2), free_file_gl(file), 1);
	if (!init_game(parsing(map, file), &game))
		return (free_game(game), 1);
	if (!start_game(game))
		return (printf("ERROR start_game\n"), free_game(game), 1);
	free_game(game);
	return (0);
}
