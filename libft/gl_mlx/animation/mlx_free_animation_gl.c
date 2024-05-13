/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_free_animation_gl.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:49:04 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 14:44:11 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

void	mlx_free_animation_gl(t_mlx_animation_gl *animation)
{
	if (animation)
		free(animation);
}
