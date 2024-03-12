/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_data_pos_grid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:54:50 by glions            #+#    #+#             */
/*   Updated: 2024/02/13 12:59:45 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/validator_map.h"

void	show_data_pos_grid(t_pos_grid2D *pos)
{
	t_list		*can_go;
	t_pos_data	*data;

	if (pos)
	{
		data = pos->data;
		ft_printf("y->%d\n", data->coord->y);
		ft_printf("x->%d\n", data->coord->x);
		ft_printf("value->%d\n", data->value);
		can_go = data->can_go;
		while (can_go)
		{
			if (can_go->content)
				ft_printf("id->%s\n", can_go->content);
			can_go = can_go->next;
		}
	}
}
