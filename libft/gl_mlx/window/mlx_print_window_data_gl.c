/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_print_window_data_gl.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:34:16 by glions            #+#    #+#             */
/*   Updated: 2024/04/21 21:23:14 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

void	mlx_print_window_data_gl(t_mlx_window_gl *window)
{
	printf("\n\n--- WIN ---\n\n");
	printf("PTR	= %p\n", window->ptr);
	printf("MLX_PTR	= %p\n", window->mlx_ptr);
	printf("WIDTH	= %d\n", window->width);
	printf("HEIGHT	= %d\n", window->height);
	if (window->bckgd)
		mlx_print_image_data_gl(window->bckgd);
	printf("\n\n-----------\n\n");
}