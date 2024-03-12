/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:42:25 by glions            #+#    #+#             */
/*   Updated: 2024/03/12 10:46:43 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static int	verif_rectangle(t_file42 *file)
{
	int		w;
	t_list	*line;

	line = file->lines;
	w = ft_strlen(line->content) - 1;
	line = line->next;
	while (line)
	{
		if ((ft_constr(line->content, '\n') && (int)ft_strlen(line->content)
				- 1 != w) || (!ft_constr(line->content, '\n')
				&& (int)ft_strlen(line->content) != w))
			return (0);
		line = line->next;
	}
	return (1);
}

int	verif_border(t_parsing *p, t_map *m)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = -1;
	k = m->height - 1;
	while (++j < m->width)
		if (m->grid[i][j].value != 1 || m->grid[k][j].value != 1)
			return (add_error_msg(p, "La map n'est entouree de murs\n"), 0);
	j = 0;
	k = m->width - 1;
	i = 0;
	while (++i < m->height)
		if (m->grid[i][j].value != 1 || m->grid[i][k].value != 1)
			return (add_error_msg(p, "La map n'est entouree de murs\n"), 0);
	return (1);
}

void	free_map(t_map *m)
{
	if (m->grid)
		free_grid(m->grid, m);
	free(m);
}

int	count_nb_items(t_parsing *p, t_map *m)
{
	int	nb_items[3];
	int	i;
	int	j;

	i = -1;
	nb_items[0] = 0;
	nb_items[1] = 0;
	nb_items[2] = 0;
	while (++i < m->height)
	{
		j = -1;
		while (++j < m->width)
		{
			if (m->grid[i][j].value == 4)
				nb_items[0]++;
			else if (m->grid[i][j].value == 3)
				nb_items[1]++;
			else if (m->grid[i][j].value == 2)
				nb_items[2]++;
		}
	}
	if (nb_items[0] != 1 || nb_items[1] != 1 || nb_items[2] < 1)
		return (add_error_msg(p, "Le nombre d'items n'est pas respecte\n"), 0);
	return (1);
}

t_map	*new_map(t_parsing *p)
{
	t_map	*new;

	new = malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	if (!verif_rectangle(p->file))
		return (add_error_msg(p, "La map n'est pas rectangle"), free(new),
			NULL);
	new->width = ft_strlen(p->file->lines->content) - 1;
	new->height = p->file->nblines;
	new->grid = init_grid(p, &new);
	if (!new->grid)
	{
		add_error_msg(p, "Erreur malloc pour la grille dans new_map");
		return (free_map(new), NULL);
	}
	if (!verif_border(p, new))
		return (free_map(new), NULL);
	if (!count_nb_items(p, new))
		return (free_map(new), NULL);
	return (new);
}
