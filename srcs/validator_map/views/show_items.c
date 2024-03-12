/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_items.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:53:20 by glions            #+#    #+#             */
/*   Updated: 2024/02/13 13:01:14 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/validator_map.h"

static void	show_lst(void *content)
{
	show_data_pos_grid(content);
}

void	show_items(t_list	*items)
{
	t_list		*tmp;
	t_item_data	*content;

	tmp = items;
	while (tmp)
	{
		content = tmp->content;
		ft_printf("id->%d\n", content->id);
		ft_printf("y->%d\n", content->coord->y);
		ft_printf("x->%d\n", content->coord->x);
		ft_printf("can_go :\n");
		if (content->can_go)
			ft_lstiter(content->can_go, &show_can_go);
		ft_printf("open :\n");
		if (content->open)
			ft_lstiter(content->open, &show_lst);
		ft_printf("close :\n");
		if (content->close)
			ft_lstiter(content->close, &show_lst);
		tmp = tmp->next;
	}
}
