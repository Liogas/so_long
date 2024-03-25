/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window42_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:22:05 by glions            #+#    #+#             */
/*   Updated: 2024/03/25 16:44:13 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	close_window(t_game *g)
{
	write(1, "Bah alors on abandonne ?!\n", 26);
	return (mlx_loop_end(g->mlx), 1);
}

void	window42_free(t_window42 *win)
{
	if (win->bg)
	{
		mlx_destroy_image(win->mlx, win->bg->ptr);
		free(win->bg);
	}
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	free(win);
}

t_window42	*window42_new(void *mlx, int sy, int sx)
{
	t_window42	*new;

	new = malloc(sizeof(t_window42));
	if (!new)
		return (NULL);
	new->mlx = mlx;
	new->win = mlx_new_window(mlx, sx, sy + 10, "so_long(glions)");
	if (!new->win)
		return (free(new), NULL);
	new->height = sy + 10;
	new->width = sx;
	new->bg = NULL;
	return (new);
}
