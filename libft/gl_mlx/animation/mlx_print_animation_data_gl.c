/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_print_animation_data_gl.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:51:53 by glions            #+#    #+#             */
/*   Updated: 2024/04/22 15:24:11 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

void	mlx_print_animation_data_gl(t_mlx_animation_gl *animation)
{
	printf("\n\n- ANIMATION -\n\n");
	printf("NAME	= \"%s\"\n", animation->sprite_name);
	printf("CUR_F	= %d\n", animation->cur_f);
	printf("TIME	= %d\n", animation->time);
	printf("TIME_D	= %d\n", animation->time_d);
	if (animation->img)
		mlx_print_image_data_gl(animation->img);
	printf("\n\n-------------\n\n");
}
