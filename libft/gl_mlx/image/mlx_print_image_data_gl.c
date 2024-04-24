/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_print_image_data_gl.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:38:30 by glions            #+#    #+#             */
/*   Updated: 2024/04/21 21:31:31 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_mlx.h"

void	mlx_print_image_data_gl(t_mlx_image_gl *image)
{
	t_list_gl	*list;

	printf("\n\n-- IMG --\n\n");
	printf("PTR		= %p\n", image->ptr);
	printf("MLX_PTR		= %p\n", image->mlx_ptr);
	printf("NAME		= \"%s\"\n", image->name);
	printf("\nWIDTH		= %d\n", image->width);
	printf("HEIGHT		= %d\n", image->height);
	printf("\nADDR		= \"%s\"\n", image->addr);
	printf("BPP		= %d\n", image->bpp);
	printf("ENDIAN		= %d\n", image->endian);
	printf("LINE_LEN	= %d\n", image->line_len);
	list = image->sprites;
	while (list)
	{
		mlx_print_sprite_data_gl(list->content);
		list = list->next;
	}
	printf("\n\n---------\n\n");
}
