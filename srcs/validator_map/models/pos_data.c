/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:35:57 by glions            #+#    #+#             */
/*   Updated: 2024/02/13 11:12:21 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/validator_map.h"

void	free_data_pos(t_pos_data *data)
{
	ft_lstclear(&data->can_go, &free);
	free(data);
}

static int	set_value(char c)
{
	if (c == '1')
		return (1);
	if (c == 'P')
		return (5);
	if (c == 'E')
		return (4);
	if (c == '0')
		return (0);
	if (c == 'C')
		return (3);
	return (-1);
}

t_pos_data	*new_pos_data(char *id, char value, t_coord *coord)
{
	t_pos_data	*new;
	int			new_value;

	new = malloc(sizeof(t_pos_data));
	if (!new)
		return (NULL);
	if (id)
	{
		new->can_go = ft_lstnew(id);
		if (!new->can_go)
			return (free(new), (NULL));
	}
	else
		new->can_go = NULL;
	new_value = set_value(value);
	if (new_value < 1 || new_value > 5)
		return (free(new), (NULL));
	new->value = new_value;
	new->coord = coord;
	return (new);
}