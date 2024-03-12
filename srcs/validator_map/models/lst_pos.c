/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 21:57:16 by glions            #+#    #+#             */
/*   Updated: 2024/02/13 12:50:46 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/validator_map.h"

static int	already_in(t_coord *c, t_list *lst)
{
	t_list	*l;

	if (!lst)
		return (0);
	l = lst;
	while (((t_coord *)(l->content))->x != c->x
		&& ((t_coord *)(l->content))->y != c->y
		&& l)
		l = l->next;
	if (l)
		return (1);
	return (0);
}

int	add_in(t_coord *pos, t_list **lst)
{
	t_list	*new;

	if (!pos)
		ft_printf("pos null\n");
	if (!*lst)
		ft_printf("lst null\n");
	if (!already_in(pos, *lst))
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return (ft_printf("Error alloc add_in()"), (0));
		new->content = pos;
		ft_lstadd_back(lst, new);
		return (1);
	}
	return (2);
}

t_list	*rm_from(t_list *e, t_list *l)
{
	t_list	*tmp;
	t_list	*previous;

	if (l == NULL)
		return (l);
	previous = l;
	if (((t_coord *)(l->content))->x != ((t_coord *)(e->content))->x
		&& ((t_coord *)(l->content))->y != ((t_coord *)(e->content))->y)
	{
		l = previous->next;
		free(previous);
		return (l);
	}
	tmp = previous->next;
	while (tmp != NULL)
	{
		if (((t_coord *)(l->content))->x != ((t_coord *)(e->content))->x
		&& ((t_coord *)(l->content))->y != ((t_coord *)(e->content))->y)
		{
			previous->next = tmp->next;
			free(tmp);
			return (l);
		}
		previous = tmp;
		tmp = tmp->next;
	}
	return (l);
}

int	mv_from_to(t_list *e, t_list **from, t_list **to)
{
	t_list			*tmp;
	t_list			*previous;
	t_coord			*pos;

	ft_lstadd_back(to, e);
	previous = *from;
	pos = previous->content;
	if (pos->x == ((t_coord *)(e->content))->x
		&& pos->y == ((t_coord *)(e->content))->y)
	{
		*from = (*from)->next;
		return (1);
	}
	tmp = previous->next;
	while (tmp)
	{
		pos = tmp->content;
		if (pos->x == ((t_coord *)(e->content))->x
			&& pos->y == ((t_coord *)(e->content))->y)
			{
				previous->next = tmp->next;
				return (1);
			}
		previous = tmp;
		tmp = tmp->next;
	}
	return (0);
}
