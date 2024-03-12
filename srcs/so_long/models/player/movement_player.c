/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:00:59 by glions            #+#    #+#             */
/*   Updated: 2024/01/04 10:11:36 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_player(char direction, t_player **player)
{
	if (direction == 'U')
		(*player)->y -= 1;
	else if (direction == 'D')
		(*player)->y += 1;
	else if (direction == 'L')
		(*player)->x -= 1;
	else if (direction == 'R')
		(*player)->x += 1;
}
