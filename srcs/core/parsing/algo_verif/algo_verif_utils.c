/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_verif_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:46:18 by glions            #+#    #+#             */
/*   Updated: 2024/03/12 10:28:12 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	next_item(t_list **item, t_algo_verif *algo, t_parsing *p)
{
	t_list		*open;
	t_item_algo	*data;

	open = ((t_item_algo *)(*item)->content)->open;
	if (!open)
	{
		if (!((t_item_algo *)(*item)->content)->close)
			return (0);
		mv_coord(&((t_item_algo *)(*item)->content)->close,
			&((t_item_algo *)(*item)->content)->open,
			((t_item_algo *)(*item)->content)->close);
		open = ((t_item_algo *)(*item)->content)->open;
	}
	while (open)
	{
		next_moove_item(open, item, algo, p);
		data = (*item)->content;
		mv_coord(&data->open, &data->trash, open);
		open = open->next;
	}
	if (verif_mems(algo->grid, p->map, size_items(algo->items)))
		return (0);
	return (1);
}

int	next_step(t_algo_verif *algo, t_parsing *p)
{
	t_list	*item;

	item = algo->items;
	while (item)
	{
		if (next_item(&item, algo, p))
		{
			if (item->next)
				item = item->next;
			else
				item = algo->items;
		}
		else
			item = NULL;
	}
	return (0);
}
