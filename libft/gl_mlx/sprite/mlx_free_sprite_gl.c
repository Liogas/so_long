/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprite_gl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:36:53 by glions            #+#    #+#             */
/*   Updated: 2024/04/20 22:37:23 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

void	mlx_free_sprite_gl(t_mlx_sprite_gl *sprite)
{
	if (sprite)
		free(sprite);
}
