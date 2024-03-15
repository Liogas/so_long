/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:41:13 by glions            #+#    #+#             */
/*   Updated: 2024/03/15 12:22:19 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

// void	calc_pos(t_coord *c, int *y, int *x, t_game *g)
// {
// 	*x = ((g->win->width - 300) + (40 * c->y)) - (40 * c->x);
// 	*y = ((g->map->height_g / g->map->height) + (30 * c->y) + (40 * c->x));
// }

// int	draw_player(t_game *game)
// {
// 	int 		posx;
// 	int 		posy;
// 	t_image42	*img;

// 	calc_pos(game->player->pos, &posy, &posx, game);
// 	img = image42_file_new(64, 64, "./srcs/simple/imgs/w_down.xpm", game->mlx);
// 	if (!img)
// 		return (0);
// 	img->posx = posx;
// 	img->posy = posy;
// 	put_img_to_img(game->win->bg, img, posx, posy - 10);
// }

// int	init_img(int value, t_game *game, int i, int j)
// {
// 	int			posx;
// 	int			posy;
// 	t_image42	*img;
// 	t_image42	*tmp;

// 	posx = ((game->win->width - 300) + (40 * i)) - (40 * j);
// 	posy = ((game->map->height_g / game->map->height) + (30 * i) + (40 * j));
// 	img = image42_file_new(64, 64, "./srcs/simple/imgs/floor.xpm", game->mlx);
// 	if (!img)
// 		return (printf("Erreur image init_img\n"), 0);
// 	if (value == 2)
// 	{
// 		tmp = image42_file_new(64, 64, "./srcs/simple/imgs/s_1.xpm", game->mlx);
// 		if (!tmp)
// 			return (printf("Erreur chargement image cerf\n"), 0);
// 		put_img_to_img(img, tmp, posx + 16, posy);
// 	}
// 	else if (value == 4 || value == 5)
// 		put_img_to_img(img, game->player->img, posx, posy - 10);
// 	img->posx = posx;
// 	img->posy = posy;
// 	game->map->grid[i][j].img_ptr = img;
// 	return (1);
// }

// int	init_imgs(t_game *game)
// {
// 	int	i;
// 	int	j;
// 	int	value;

// 	i = 0;
// 	while (i < game->map->height)
// 	{
// 		j = 0;
// 		while (j < game->map->width)
// 		{
// 			value = game->map->grid[i][j].value;
// 			if (value != 1)
// 				init_img(value, game, i, j);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }
// void	set_size_map(t_game *game)
// {
// 	game->map->width_g = (64 * game->map->width) - (24 * (game->map->width
// 				- 1));
// 	game->map->height_g = (64 * game->map->height) - (20 * (game->map->height
// 				- 1));
// }

// void	draw_map(t_game *game)
// {
// 	int			i;
// 	int			j;
// 	int			value;
// 	t_image42	*img;
// 	t_image42	*tmp;

// 	i = -1;
// 	while (++i < game->map->height)
// 	{
// 		j = game->map->width;
// 		while (--j >= 0)
// 		{
// 			value = game->map->grid[i][j].value;
// 			if (value != 1)
// 			{
// 				img = game->map->grid[i][j].img_ptr;
// 				put_img_to_img(game->win->bg, img, img->posx, img->posy);
// 				if (value == 2)
// 				{
// 					tmp = image42_file_new(64, 64, "./srcs/simple/imgs/s_1.xpm",
// 							game->mlx);
// 					if (!tmp)
// 						return ;
// 					put_img_to_img(img, tmp, img->posx + 16, img->posy);
				// }
				// else if (value == 3)
				// {
				// 	tmp = image42_file_new(64, 64, "./srcs/simple/imgs/s_1.xpm",
				// 			game->mlx);
				// 	if (!tmp)
				// 		return (printf("Erreur chargement image cerf\n"), 0);
				// 	put_img_to_img(img, tmp, img->posx + 16, img->posy);
				// }
	// 		}
	// 	}
	// }
	// // int	startx;
	// // int	starty;
	// // int	value;
	// // starty = game->map->height_g / game->map->height;
	// // i = 0;
	// // while (i < game->map->height)
	// // {
	// // 	startx = (game->win->width - 300) + (40 * i);
	// // 	j = game->map->width - 1;
	// // 	printf("j->%d\n", j);
	// // 	while (j >= 0)
	// // 	{
	// // 		if (game->map->grid[i][j].img_ptr)
	// // 		{
	// // 			value = game->map->grid[i][j].value;
	// // 			put_img_to_img(game->win->bg, game->map->grid[i][j].img_ptr,
	// 				startx, starty);
	// 				// 			if (value == 2)
	// 				// 				put_img_to_img(game->win->bg,
	// 					image42_file_new(64,64,"./srcs/simple/imgs/s_1.xpm",
	// 						game->mlx), startx + 16, starty);
	// 					// 			else if (value == 4)
	// 					// 				put_img_to_img(game->win->bg,
	// 					image42_file_new(64,64,"./srcs/simple/imgs/w_down.xpm",
	// 						game->mlx), startx, starty - 10);
	// 					// 			else if (value == 1)
	// 					// 				put_img_to_img(game->win->bg,
	// 					image42_file_new(64,64,"./srcs/simple/imgs/water.xpm",
	// 						game->mlx), startx, starty - 10);
	// 					// 		}
	// 					// 		startx -= 40;
	// 					// 		starty += 20;
	// 					// 		j--;
	// 					// 	}
	// 					// 	starty = (game->map->height_g / game->map->height)
	// 					+(30 * i);
	// 					// 	i++;
	// 					// }
// }

int	show_map(t_game *game)
{
	(void)game;
// 	set_size_map(game);
// 	if (!init_imgs(game))
// 		return (printf("Erreur init_img\n"), 0);
// 	draw_map(game);
// 	mlx_put_image_to_window(game->mlx, game->win->win, game->win->bg->ptr, 0,
// 		0);
	return (1);
}