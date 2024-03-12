/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_algo_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:39:54 by glions            #+#    #+#             */
/*   Updated: 2024/03/12 10:28:43 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

// void	print_list(t_list *list)
// {
// 	t_list	*e;
// 	t_coord	*data;

// 	e = list;
// 	while (e)
// 	{
// 		data = e->content;
// 		printf("[%d;%d]\n", data->y, data->x);
// 		e = e->next;
// 	}
// }

// void	print_items(t_list *items)
// {
// 	t_list		*item;
// 	t_item_algo	*data;

// 	item = items;
// 	printf("Liste de mes items :\n");
// 	while (item)
// 	{
// 		data = item->content;
// 		printf("ID->%d\n", data->id);
// 		printf("OPEN :\n");
// 		print_list(data->open);
// 		printf("CLOSE :\n");
// 		print_list(data->close);
// 		printf("TRASH\n");
// 		print_list(data->trash);
// 		item = item->next;
// 		printf("\n");
// 	}
// }

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
