/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_print_data_gl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:25:14 by glions            #+#    #+#             */
/*   Updated: 2024/04/21 21:21:00 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

void	mlx_print_data_gl(t_mlx_gl *mlx)
{
	t_list_gl	*list;
	printf("------ MLX DATA ------\n");
	printf("\nPTR	= %p\n\n", mlx->ptr);
	if (mlx->window)
		mlx_print_window_data_gl(mlx->window);
	list = mlx->images;
	while (list)
	{
		mlx_print_image_data_gl((t_mlx_image_gl *)list->content);
		list = list->next;
	}
	list = mlx->objects;
	while (list)
	{
		mlx_print_object_data_gl((t_mlx_object_gl *)list->content);
		list = list->next;
	}
	printf("----------------------\n");
}