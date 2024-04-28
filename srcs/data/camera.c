/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:54:49 by glions            #+#    #+#             */
/*   Updated: 2024/04/27 20:26:53 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_camera(t_camera *camera)
{
	if (!camera)
		return ;
	free(camera);
}

static void	set_value(int tab[2])
{
	tab[0] = -1;
	tab[1] = -1;
}

t_camera	*new_camera()
{
	t_camera	*new;

	new = malloc(sizeof(t_camera));
	if (!new)
		return (NULL);
	set_value(new->end);
	set_value(new->start);
	new->mode_y = 0;
	new->mode_x = 0;
	return (new);
}
