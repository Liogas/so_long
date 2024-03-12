/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_dataM.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:08:56 by glions            #+#    #+#             */
/*   Updated: 2024/02/13 14:15:54 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/validator_map.h"

void	free_item_data(void *content)
{
	t_item_data	*mem;

	mem = content;
	if (mem->can_go)
		ft_lstclear(&mem->can_go, &free);
	if (mem->open)
		ft_lstclear(&mem->open, &free);
	if (mem->close)
		ft_lstclear(&mem->close, &free);
	free(mem);
}

void	free_items(t_list	*items)
{
	ft_lstclear(&items, &free_item_data);
}

t_item_data	*new_item_data(int id, char type, int y, int x)
{
	t_item_data	*new;
	t_coord		*coord;

	new = malloc(sizeof(t_item_data));
	if (!new)
		return (NULL);
	new->id = id;
	if (type == 'P')
		new->type = 5;
	else if (type == 'C')
		new->type = 3;
	else if (type == 'E')
		new->type = 4;
	coord = malloc(sizeof(t_coord));
	if (!coord)
		return (free(new), (NULL));
	coord->x = x;
	coord->y = y;
	new->can_go = NULL;
	new->close = NULL;
	new->open = ft_lstnew(coord);
	if (!new->open)
		return (free_item_data(new), NULL);
	return (new);
}
