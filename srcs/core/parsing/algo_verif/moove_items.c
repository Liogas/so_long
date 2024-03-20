/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:31:29 by glions            #+#    #+#             */
/*   Updated: 2024/03/20 12:16:56 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	moove_right_algo(t_list *o, t_parsing *p, t_list **item,
		t_algo_verif *algo)
{
	int			i;
	int			j;
	t_item_algo	*data;

	i = ((t_coord *)o->content)->y;
	j = ((t_coord *)o->content)->x + 1;
	data = (*item)->content;
	while (j < p->map->width && p->map->grid[i][j].value != 1)
	{
		if (p->map->grid[i][j + 1].value == 1)
		{
			if (!already_in(data->open, i, j) && !already_in(data->close, i, j)
				&& !already_in(data->trash, i, j))
				add_coord(&data->open, ft_lstnew(p->map->grid[i][j].coord));
		}
		else
		{
			if (!already_in(data->open, i, j) && !already_in(data->close, i, j)
				&& !already_in(data->trash, i, j))
				add_coord(&data->close, ft_lstnew(p->map->grid[i][j].coord));
		}
		update_mem(&algo->grid[i][j].mem, data->id);
		j++;
	}
}

void	moove_left_algo(t_list *o, t_parsing *p, t_list **item,
		t_algo_verif *algo)
{
	int			i;
	int			j;
	t_item_algo	*data;

	i = ((t_coord *)o->content)->y;
	j = ((t_coord *)o->content)->x - 1;
	data = (*item)->content;
	while (j > 0 && p->map->grid[i][j].value != 1)
	{
		if (p->map->grid[i][j - 1].value == 1)
		{
			if (!already_in(data->open, i, j) && !already_in(data->close, i, j)
				&& !already_in(data->trash, i, j))
				add_coord(&data->open, ft_lstnew(p->map->grid[i][j].coord));
		}
		else
		{
			if (!already_in(data->open, i, j) && !already_in(data->close, i, j)
				&& !already_in(data->trash, i, j))
				add_coord(&data->close, ft_lstnew(p->map->grid[i][j].coord));
		}
		update_mem(&algo->grid[i][j].mem, data->id);
		j--;
	}
}

void	moove_top_algo(t_list *o, t_parsing *p, t_list **item,
		t_algo_verif *algo)
{
	int			i;
	int			j;
	t_item_algo	*data;

	i = ((t_coord *)o->content)->y - 1;
	j = ((t_coord *)o->content)->x;
	data = (*item)->content;
	while (i > 0 && p->map->grid[i][j].value != 1)
	{
		if (p->map->grid[i - 1][j].value == 1)
		{
			if (!already_in(data->open, i, j) && !already_in(data->close, i, j)
				&& !already_in(data->trash, i, j))
				add_coord(&data->open, ft_lstnew(p->map->grid[i][j].coord));
		}
		else
		{
			if (!already_in(data->open, i, j) && !already_in(data->close, i, j)
				&& !already_in(data->trash, i, j))
				add_coord(&data->close, ft_lstnew(p->map->grid[i][j].coord));
		}
		update_mem(&algo->grid[i][j].mem, data->id);
		i--;
	}
}

void	moove_bot_algo(t_list *o, t_parsing *p, t_list **item,
		t_algo_verif *algo)
{
	int			i;
	int			j;
	t_item_algo	*data;

	i = ((t_coord *)o->content)->y + 1;
	j = ((t_coord *)o->content)->x;
	data = (*item)->content;
	while (i < p->map->height && p->map->grid[i][j].value != 1)
	{
		if (p->map->grid[i + 1][j].value == 1)
		{
			if (!already_in(data->open, i, j) && !already_in(data->close, i, j)
				&& !already_in(data->trash, i, j))
				add_coord(&data->open, ft_lstnew(p->map->grid[i][j].coord));
		}
		else
		{
			if (!already_in(data->open, i, j) && !already_in(data->close, i, j)
				&& !already_in(data->trash, i, j))
				add_coord(&data->close, ft_lstnew(p->map->grid[i][j].coord));
		}
		update_mem(&algo->grid[i][j].mem, data->id);
		i++;
	}
}

void	next_moove_item(t_list *o, t_list **i, t_algo_verif *a, t_parsing *p)
{
	moove_right_algo(o, p, i, a);
	moove_left_algo(o, p, i, a);
	moove_top_algo(o, p, i, a);
	moove_bot_algo(o, p, i, a);
}
