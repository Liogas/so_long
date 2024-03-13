/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:41:13 by glions            #+#    #+#             */
/*   Updated: 2024/03/13 16:46:38 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	init_img(t_game *game)
{
	int	i;
	int	j;
	int	value;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			value = game->map->grid[i][j].value;
			if (value == 0 || value == 2 || value == 3 || value == 4)
			{
				game->map->grid[i][j].img_ptr = image42_file_new(64, 64, "./srcs/simple/imgs/floor.xpm", game->mlx);
				if (!game->map->grid[i][j].img_ptr)
					return (printf("Erreur chargement image du sol\n"), 0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
void	set_size_map(t_game *game)
{
	game->map->width_g = (64 * game->map->width) - (24 * (game->map->width - 1));
	game->map->height_g = (64 * game->map->height) - (20 * (game->map->height - 1));
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;
	int	startx;
	int	starty;
	int	value;

	starty = game->map->height_g / game->map->height;
	i = 0;
	while (i < game->map->height)
	{
		startx = (game->win->width - 300) + (40 * i);
		j = game->map->width - 1;
		printf("j->%d\n", j);
		while (j >= 0)
		{
			if (game->map->grid[i][j].img_ptr)
			{
				value = game->map->grid[i][j].value;
				put_img_to_img(game->win->bg, game->map->grid[i][j].img_ptr, startx, starty);
				if (value == 2)
					put_img_to_img(game->win->bg, image42_file_new(64,64,"./srcs/simple/imgs/s_1.xpm", game->mlx), startx + 16, starty);
				else if (value == 4)
					put_img_to_img(game->win->bg, image42_file_new(64,64,"./srcs/simple/imgs/w_down.xpm", game->mlx), startx, starty - 10);
			}
			startx -= 40;
			starty += 20;
			j--;
		}
		starty = (game->map->height_g / game->map->height) + (30 * i);
		i++;
	}
}

int	show_map(t_game *game)
{
	if (!init_img(game))
		return (printf("Erreur init_img\n"), 0);
	set_size_map(game);
	draw_map(game);
	mlx_put_image_to_window(game->mlx, game->win->win, game->win->bg->ptr, 0, 0);
	// t_image42	*test1;
	// t_image42	*test2;
	// t_image42	*test3;
	// t_image42	*test4;
	// t_image42	*test5;
	// t_image42	*test6;
	// t_image42	*test7;
	// t_image42	*test8;

	// test1 = image42_file_new(64,64,"./srcs/simple/imgs/floor.xpm", game->mlx);
	// if (!test1)
	// 	return (printf("Erreur test1\n"), 0);
	// test2 = image42_file_new(64,64,"./srcs/simple/imgs/floor.xpm", game->mlx);
	// if (!test2)
	// 	return (printf("Erreur test2\n"), 0);
	// test5 = image42_file_new(64,64,"./srcs/simple/imgs/floor.xpm", game->mlx);
	// if (!test5)
	// 	return (printf("Erreur test5\n"), 0);
	// test6 = image42_file_new(64,64,"./srcs/simple/imgs/floor.xpm", game->mlx);
	// if (!test6)
	// 	return (printf("Erreur test6\n"), 0);
	// test7 = image42_file_new(64,64,"./srcs/simple/imgs/floor.xpm", game->mlx);
	// if (!test7)
	// 	return (printf("Erreur test\n"), 0);
	// test8 = image42_file_new(64,64,"./srcs/simple/imgs/floor.xpm", game->mlx);
	// if (!test8)
	// 	return (printf("Erreur test8\n"), 0);
	// test3 = image42_file_new(64, 64, "./srcs/simple/imgs/s_1.xpm", game->mlx);
	// if (!test3)
	// 	return (printf("Erreur test3\n"), 0);
	// test4 = image42_file_new(64, 64, "./srcs/simple/imgs/w_top.xpm", game->mlx);
	// if (!test4)
	// 	return (printf("Erreur test3\n"), 0);
	// put_img_to_img(game->win->bg, test6, 180, 60);
	// put_img_to_img(game->win->bg, test5, 140, 80);
	// put_img_to_img(game->win->bg, test1, 100, 100);
	// put_img_to_img(game->win->bg, test7, 62, 120);
	// put_img_to_img(game->win->bg, test3, 116, 100);
	// put_img_to_img(game->win->bg, test2, 135, 120);
	// put_img_to_img(game->win->bg, test8, 97, 140);
	// put_img_to_img(game->win->bg, test4, 135, 110);
	// mlx_put_image_to_window(game->mlx, game->win->win, game->win->bg->ptr, 0, 0);
	return (1);
}