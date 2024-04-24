/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_print_sprite_data_gl.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:44:25 by glions            #+#    #+#             */
/*   Updated: 2024/04/21 21:31:41 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

void	mlx_print_sprite_data_gl(t_mlx_sprite_gl *sprite)
{
	printf("\n\n- SPRITE -\n\n");
	printf("NAME			= \"%s\"\n", sprite->name);
	printf("HEIGHT_FRAME		= %d\n", sprite->height_frame);
	printf("WIDTH_FRAME		= %d\n", sprite->width_frame);
	printf("POS_Y			= %d\n", sprite->pos_y);
	printf("NB_FRAMES		= %d\n", sprite->nb_frames);
	printf("\n\n----------\n\n");
}