/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:40:49 by glions            #+#    #+#             */
/*   Updated: 2024/02/09 15:02:18 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/validator_map.h"

void	free_validator_map(t_validator_map *validator)
{
	free_items(validator->items);
	free_file42(validator->file_map);
	free_all_pos_grid2D(validator->pos);
	free(validator);
}

t_validator_map	*new_validator_map(t_file42 *file)
{
	t_validator_map	*new;

	new = malloc(sizeof(t_validator_map));
	if (!new)
		return (NULL);
	new->file_map = file;
	new->items = NULL;
	new->map_h = 0;
	new->map_w = 0;
	new->pos = NULL;
	return (new);
}
