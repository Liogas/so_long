/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:48:10 by glions            #+#    #+#             */
/*   Updated: 2024/03/20 12:17:12 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	rm_coord(t_list **list, t_list *e, int mode)
{
	t_list	*tmp;
	t_list	*before;
	t_coord	*c;
	t_coord	*c2;

	tmp = *list;
	before = NULL;
	c2 = e->content;
	while (tmp)
	{
		c = tmp->content;
		if (c->x == c2->x && c->y == c2->y)
		{
			if (before)
				before->next = tmp->next;
			else
				*list = (*list)->next;
			if (!mode)
				free(tmp);
			break ;
		}
		before = tmp;
		tmp = tmp->next;
	}
}

void	add_coord(t_list **list, t_list *new)
{
	t_list	*l;

	new->next = NULL;
	if (!*list)
		*list = new;
	else
	{
		l = *list;
		while (l->next)
			l = l->next;
		l->next = new;
	}
}

void	mv_coord(t_list **src, t_list **dst, t_list *e)
{
	rm_coord(src, e, 1);
	add_coord(dst, e);
}

int	already_in(t_list *list, int y, int x)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (((t_coord *)tmp->content)->y == y
			&& ((t_coord *)tmp->content)->x == x)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
