/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:28:05 by glions            #+#    #+#             */
/*   Updated: 2024/03/12 10:51:20 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

t_coord	*new_coord(int y, int x)
{
	t_coord	*new;

	new = malloc(sizeof(t_coord));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	return (new);
}
