/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:42:55 by glions            #+#    #+#             */
/*   Updated: 2024/03/20 12:03:10 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	draw_free(t_draw *draw)
{
	if (draw)
	{
		if (draw->img_object)
			imgs_free(draw->img_object, 3);
		if (draw->img_wolf)
			imgs_free(draw->img_wolf, 4);
		if (draw->img_exit)
			image42_free(draw->img_exit);
		if (draw->img_floor)
			image42_free(draw->img_floor);
		if (draw->img_exit_player)
			image42_free(draw->img_exit_player);
		if (draw->img_floor)
			image42_free(draw->img_food);
		free(draw);
	}
}

t_draw	*draw_new(void)
{
	t_draw	*new;

	new = malloc(sizeof(t_draw));
	if (!new)
		return (NULL);
	new->d_wolf = 0;
	new->nb_obj = 0;
	new->img_exit = NULL;
	new->img_exit_player = NULL;
	new->img_floor = NULL;
	new->img_wolf = NULL;
	new->img_object = NULL;
	new->img_food = NULL;
	new->imgs_number = NULL;
	return (new);
}
