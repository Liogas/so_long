/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_algo_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:39:54 by glions            #+#    #+#             */
/*   Updated: 2024/03/20 12:16:40 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	free_list(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

void	free_items(t_list *items)
{
	t_list	*item;

	while (items)
	{
		item = items;
		items = items->next;
		if (item->content)
		{
			if (((t_item_algo *)item->content)->open)
				free_list(((t_item_algo *)item->content)->open);
			if (((t_item_algo *)item->content)->close)
				free_list(((t_item_algo *)item->content)->close);
			if (((t_item_algo *)item->content)->trash)
				free_list(((t_item_algo *)item->content)->trash);
			free(item->content);
		}
		free(item);
	}
}

int	size_items(t_list *items)
{
	int		i;
	t_list	*item;

	if (!items)
		return (0);
	i = 1;
	item = items;
	while (item->next)
	{
		item = item->next;
		i++;
	}
	return (i);
}

int	add_item_algo(t_coord *c, t_list **items)
{
	t_list		*new;
	t_item_algo	*data;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->next = NULL;
	data = malloc(sizeof(t_item_algo));
	if (!data)
		return (free(new), 0);
	data->id = size_items(*items);
	data->open = NULL;
	ft_lstadd_back(&data->open, ft_lstnew(c));
	if (!data->open)
		return (free(new), free(data), 0);
	data->close = NULL;
	data->trash = NULL;
	new->content = data;
	ft_lstadd_back(items, new);
	return (1);
}
