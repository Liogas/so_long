/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_42.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:27:12 by glions            #+#    #+#             */
/*   Updated: 2024/03/12 10:54:07 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WINDOW_42_H
# define WINDOW_42_H

# include "../srcs/minilibx/mlx.h"
# include "../srcs/minilibx/mlx_int.h"
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>

typedef struct s_sprite
{
	int				id;
	char			*path;
	struct s_sprite	*next;
}	t_sprite;

typedef struct	s_image
{
	void		*img_ptr;
	int			width;
	int			height;
	int			posx;
	int			posy;
	t_sprite	*walks;
}   t_image;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
	char	*win_title;
	int		img_width;
	int		img_height;
	t_image	*img;
}	t_data;

#endif