/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_free_win_gl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:12:48 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 15:08:50 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

void	mlx_free_win_gl(t_mlx_gl *mlx, t_mlx_window_gl *window)
{
	if (!window || !mlx)
		return ;
	if (window->bckgd)
		mlx_free_img_gl(mlx, window->bckgd);
	if (window->ptr)
		mlx_destroy_window(window->mlx_ptr, window->ptr);
	free(window);
}
