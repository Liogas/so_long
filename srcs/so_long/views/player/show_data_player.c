/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_data_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:09:55 by glions            #+#    #+#             */
/*   Updated: 2024/01/04 10:05:36 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	show_data_player(t_player *player)
{
	ft_printf("PLAYER = id->%d;y->%d;x->%d\n",
		player->id, player->y, player->x);
}
