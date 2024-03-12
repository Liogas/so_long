/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_canwin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:31:48 by glions            #+#    #+#             */
/*   Updated: 2024/02/13 14:23:56 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/validator_map.h"

static int	already_in(char *id, t_list *lst)
{
	t_list	*l;

	ft_printf("Entrée dans already_in\n");
	ft_printf("id->%s\n", id);
	l = lst;
	while (l && ft_strcmp(id, l->content) != 0)
	{
		ft_printf("l->content->%s\n", l->content);
		l = l->next;
	}
	if (l)
		return (1);
	return (0);
}

int		reachable_top(t_list **open, t_item_data **item, t_pos_grid2D **pos)
{
	int				i;
	char			*id;
	t_pos_grid2D	*pos_start;
	t_pos_grid2D	*tmp;
	t_pos_data		*data;

	ft_printf("Entrée dans reachable_top\n");
	if (!*open)
		ft_printf("open null\n");
	if (!*item)
		ft_printf("item null");
	if (!*pos)
		ft_printf("grid null\n");
	i = 0;
	pos_start = get_pos_grid2D(*pos, ((t_coord *)(*open)->content)->y, ((t_coord *)(*open)->content)->x);
	if (!pos_start)
		return (0);
	data = pos_start->data;
	tmp = pos_start;
	while (data->coord->y - i >= 0 && ((t_pos_data *)(pos_start->top->data))->value != 1)
	{
		tmp = tmp->top;
		if (((t_pos_data *)(tmp->data))->coord->y == 0)
		{	
			ft_printf("Je suis ici\n");
			if(!add_in(((t_pos_data *)(tmp->data))->coord, &(*item)->open))
				return (0);
		} else
		{	
			ft_printf("Je suis ici 2\n");
			if(!add_in(((t_pos_data *)(tmp->data))->coord, &(*item)->close))
				return (0);
		}
		id = ft_itoa((*item)->id);
		if (!id)
			return (0);
		if (!already_in(id, ((t_pos_data *)(tmp->data))->can_go))
			ft_lstadd_back(&((t_pos_data *)(tmp->data))->can_go, ft_lstnew(id));
		i++;
	}
	return (1);
}

int	add_pos_reachable(t_list **open, t_item_data **item, t_pos_grid2D **pos)
{
	// DEPLACEMENT HAUT
	ft_printf("Entrée dans add_pos_reachable\n");
	if (!reachable_top(open, item, pos))
		return (0);
	// DEPLACEMENT BAS
	// DEPLACEMENT DROITE
	// DEPLACEMENT GAUCHE
	*open = rm_from((*open)->content, *open);
	if (!*open)
		return (0);
	return (1);
}

int	next_step_item(t_list *item, t_pos_grid2D **pos)
{
	t_item_data	*data;

	data = item->content;
	show_items(item);
	ft_printf("Entrée dans next_step_item\n");
	if (!data->open && !data->close)
		return (1);
	if (data->open)
		if (!add_pos_reachable(&data->open, &data, pos))
			return (-1);
	return (0);
}

int	algo_canwin(t_validator_map *v)
{
	t_list	*item;
	int		tmp;
	// int		state_while;

	ft_printf("Entrée dans algo_canwin\n");
	if (!v)
		return (ft_printf("Aucune map à tester\n"), (0));
	item = v->items;	
	tmp = next_step_item(item, &v->pos);
	// state_while = 0;
	// while (!state_while)
	// {
	// 	item = map->items;
	// 	while (item)
	// 	{
	// 		tmp = next_step_item(item, &map->grid_test->grid);
	// 		if (tmp == -1)
	// 			return (0);
	// 		state_while += tmp;
	// 		item = item->next;
	// 	}
	// 	// if (state_while < ft_lstsize(map->items))
	// 		// state_while = 0;
	// 	state_while = 1;
	// }
	return (1);
}
