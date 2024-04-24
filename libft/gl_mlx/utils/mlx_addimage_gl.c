/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_addimage_gl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:36:32 by glions            #+#    #+#             */
/*   Updated: 2024/04/22 10:01:58 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

int	mlx_addimage_gl(t_mlx_gl *mlx, t_mlx_image_gl *image)
{
	if (!mlx || !image)
		return (0);
	if (!addback_list_gl(&mlx->images, new_element_gl(image)))
		return (mlx_free_img_gl(mlx, image), 0);
	return (1);
}
