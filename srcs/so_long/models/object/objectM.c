/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objectM.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:26:56 by glions            #+#    #+#             */
/*   Updated: 2024/01/04 13:52:18 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	verif_object(t_object **objects, t_player *player)
{
	t_object	*obj;

	obj = *objects;
	while (obj)
	{
		if (obj->x == player->x && obj->y == player->y)
		{
			obj->x = -1;
			obj->y = -1;
			obj->id_player = player->id;
			ft_printf("Objet recupere\n");
			return ;
		}
		obj = obj->next;
	}
}

int	size_objects(t_object *object)
{
	int	i;

	if (object)
	{
		i = 1;
		while (object->next)
		{
			i++;
			object = object->next;
		}
		return (i);
	}
	return (0);
}

t_object	*new_object(int id, int y, int x)
{
	t_object	*new_object;

	new_object = malloc(sizeof(t_object));
	if (!new_object)
		return (NULL);
	new_object->id = id;
	new_object->id_player = -1;
	new_object->x = x;
	new_object->y = y;
	new_object->next = NULL;
	return (new_object);
}

int	add_object(t_object **objects, int y, int x)
{
	int			size;
	t_object	*object;

	if (!objects)
		ft_printf("objects null\n");
	size = size_objects(*objects);
	object = new_object(size + 2, y, x);
	if (!object)
		return (1);
	object->next = *objects;
	*objects = object;
	return (0);
}

void	free_objects(t_object *l)
{
	t_object	*next;

	while (l)
	{
		next = l->next;
		free(l);
		l = next;
	}
}
