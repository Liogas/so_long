/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:41:13 by glions            #+#    #+#             */
/*   Updated: 2024/03/12 21:13:44 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"



int	show_map(t_game *game)
{
	t_image42	*test1;
	t_image42	*test2;
	t_image42	*test3;

	test1 = image42_new(64,64,"./srcs/simple/imgs/floor.xpm", game->mlx);
	if (!test1)
		return (printf("Erreur test1\n"), 0);
	test2 = image42_new(64,64,"./srcs/simple/imgs/floor.xpm", game->mlx);
	if (!test2)
		return (printf("Erreur test2\n"), 0);
	test3 = image42_new(64, 64, "./srcs/simple/imgs/s_1.xpm", game->mlx);
	if (!test3)
		return (printf("Erreur test3\n"), 0);
	mlx_put_image_to_window(game->mlx, game->win->win, test1->ptr, 100, 100);
	mlx_put_image_to_window(game->mlx, game->win->win, test2->ptr, 174, 100);
	mlx_put_image_to_window(game->mlx, game->win->win, test3->ptr, 100, 100);
	return (1);
}