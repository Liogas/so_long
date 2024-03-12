/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:16:47 by glions            #+#    #+#             */
/*   Updated: 2024/02/19 16:39:29 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/validator_map.h"

static int	verif_border(char *line, int y, int height, int width)
{
	int	i;
	int	constr;
	
	constr = ft_constr(line, '\n');
	width--;
	if (line[0] != '1' || ((constr && line[width] != '1')
		|| (!constr && line[width] != '1')))
		return (ft_printf("Erreur ici1\n"), 0);
	i = 1;
	while (line[i] && line[i] != '\n')
	{
		if ((y == 0 && line[i] != '1') || (y == height - 1 && line[i] != '1'))
			return (ft_printf("Erreur ici2\n"), 0);
		i++;
	}
	return (1);
}

static int	verif_items(t_list *items)
{
	int			ce;
	int			co;
	int			cp;
	t_list		*item;

	ce = 0;
	co = 0;
	cp = 0;
	item = items;
	while (item)
	{
		if (((t_item_data *)item->content)->type == 5)
			cp++;
		else if (((t_item_data *)item->content)->type == 4)
			ce++;
		else if (((t_item_data *)item->content)->type == 3)
			co++;
		item = item->next;
	}
	ft_printf("ce->%d;co->%d;cp->%d\n", ce, co, cp);
	if (ce != 1 || co <= 0 || cp != 1)
		return (0);
	return (1);
}

// static int	update_data(t_validator_map *v, char *line, int l, int i)
// {
// 	t_list			*n_item;
// 	t_item_data		*n_item_data;
// 	t_pos_grid2D	*pos;
// 	t_pos_data		*data;
	
// 	n_item_data = new_item_data(ft_lstsize(v->items), line[i], l, i);
// 	if (!n_item_data)
// 		return (0);
// 	n_item = ft_lstnew(n_item_data);
// 	if (!n_item)
// 		return (free(n_item_data), (0));
// 	pos = get_pos_grid2D(v->pos, l, i);
// 	if (!pos)
// 		return (free(n_item_data), (0));
// 	data = pos->data;
// 	data->can_go = ft_lstnew(ft_itoa(n_item_data->id));
// 	if (!data->can_go)
// 		return (free(n_item_data), ft_printf("Erreur aloc \n"), (0));
// 	ft_lstadd_back(&v->items, n_item);
// 	return (1);
// }

static int	verif_content_line(t_validator_map *v, char *line, int l)
{
	int			i;
	int			strlen;
	int			nl;
	t_pos_grid2D	*top;
	t_pos_grid2D	*left;
	t_pos_grid2D	*new;
	t_coord			*coord;

	nl = ft_constr(line, '\n');
	strlen = (int)ft_strlen(line);
	i = 0;
	if ((!nl && strlen != v->map_h) ||
		(nl && strlen - 1 != v->map_w))
		return (ft_printf("La grille n'est pas un rectangle\n"), (0));
	if (!verif_border(line, l, v->map_h, v->map_w))
		return (ft_printf("Erreur bordure\n"), (0));
	top = v->pos;
	left = NULL;
	i = 1;
	while (i++ < l)
		top = top->bottom;
	while (line[i] != '\n' && line[i])
	{
		coord = malloc(sizeof(t_coord));
		if (!coord)
			return (0);
		new = new_pos_grid2D(top, left, new_pos_data(ft_itoa((l * v->map_w) + i), line[i], coord));
		if (!new)
			return (0);
		i++;
	}
	return (1);
}

int	first_verif(t_validator_map *v)
{
	int		l;
	t_list	*line;

	l = 0;
	line = v->file_map->lines;
	while (line)
	{
		if (!verif_content_line(v, line->content, l))
			return (0);
		line = line->next;
		l++;
	}
	if (!verif_items(v->items))
		return (0);
	return (1);
}
