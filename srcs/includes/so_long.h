/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:43:25 by glions            #+#    #+#             */
/*   Updated: 2024/04/24 22:34:29 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"

typedef struct s_map
{
	int	height;
	int	width;
	int	**tab;
}		t_map;

// MAP
t_map	*new_map(int height, int width);
void	free_map(t_map *map);

// PARSING
t_map	*parsing(t_map *map, t_file_gl *file);
int		c_is_valid(char c);

#endif