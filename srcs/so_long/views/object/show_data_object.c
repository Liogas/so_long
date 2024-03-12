/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_data_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:07:42 by glions            #+#    #+#             */
/*   Updated: 2024/01/04 10:05:51 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	show_data_objects(t_object	*objects)
{
	ft_printf("OBJECTS :\n");
	while (objects)
	{
		show_data_object(objects);
		objects = objects->next;
	}
}

void	show_data_object(t_object *object)
{
	ft_printf("id->%d;id_player->%d;y->%d;x->%d\n",
		object->id, object->id_player, object->y, object->x);
}
