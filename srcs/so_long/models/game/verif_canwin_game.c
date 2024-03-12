/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_canwin_game.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:32:59 by glions            #+#    #+#             */
/*   Updated: 2024/01/11 12:26:23 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_mem_pos(t_items_test *item)
{
	t_mem_pos	*mem;
	t_mem_pos	*next;

	mem = item->mem_pos;
	while (mem)
	{
		next = mem->next;
		free(mem);
		mem = next;
	}
}

void	free_items_gt(t_items_test *items)
{
	t_items_test	*next;
	
	while (items)
	{
		free_mem_pos(items);
		next = items->next;
		free(items);
		items = next;
	}
}

void	free_grid_gt(t_pos_grid **grid, t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->map->height)
	{
		j = -1;
		while (++j < g->map->width)
		{
			if (grid[i][j].can_go)
				free(grid[i][j].can_go);
		}
		if (grid[i])
			free(grid[i]);
	}
	free(grid);	
}

void	free_game_test(t_game_test *gt, t_game *g)
{
	free_items_gt(gt->items);
	free_grid_gt(gt->grid, g);
	free(gt);
}

int	size_items(t_items_test *items)
{
	t_items_test	*item;
	int				i;

	i = 0;
	item = items;
	while (item)
	{
		item = item->next;
		i++;
	}
	return (i);
}

void	add_can_go(int **can_go, t_items_test *item, t_items_test *items)
{
	int				i;
	int				items_size;

	items_size = size_items(items);
	i = 0;
	while (item && i < items_size && (*can_go)[i] != -1)
	{
		ft_printf("Je suis dans la boucle\n");
		if ((*can_go)[i] == item->id)
			return ;
		i++;
	}
	(*can_go)[i] = item->id;
}

int	new_pos_grid(t_pos_grid *pos, int coord[2], int value, t_items_test *items)
{
	int				i;
	int				j;
	t_items_test	*item;

	i = size_items(items);
	(*pos).can_go = malloc(i * sizeof(int));
	if (!(*pos).can_go)
		return (0);
	j = -1;
	while (++j < i)
		(*pos).can_go[j] = -1;
	item = items;
	while (item)
	{
		if (item->y == coord[0] && item->x == coord[1])
			add_can_go(&(*pos).can_go, item, items);
		item = item->next;
	}
	if (value != 1)
		(*pos).value = 0;
	else
		(*pos).value = value;
	return (1);
}

int	add_items_gt(t_items_test **items, int i, int j)
{
	t_items_test	*new;
	int				items_size;

	new = *items;
	new = malloc(sizeof(t_items_test));
	if (!new)
		return (0);
	new->y = i;
	new->x = j;
	new->mem_pos = NULL;
	items_size = size_items(*items);
	new->id = items_size;
	new->next = *items;
	*items = new;
	return (1);
}

int	set_items_test(t_game_test **gt, t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->map->height)
	{
		j = -1;
		while (++j < g->map->width)
			if (g->map->grid[i][j] >= 3 && g->map->grid[i][j] <= 5)
				if (!add_items_gt(&(*gt)->items, i, j))
					return (0);
	}
	return (1);
}

int	set_can_go(t_game_test **gt, t_game *g)
{
	int	i;
	int	j;
	int	a;
	int	coord[2];
	
	(*gt)->grid = malloc(g->map->height * sizeof(t_pos_grid *));
	if (!(*gt)->grid)
		return (0);
	i = -1;
	while (++i < g->map->height)
	{
		(*gt)->grid[i] = malloc(g->map->width * sizeof(t_pos_grid));
		if (!(*gt)->grid[i])
			return (0);
		j = -1;
		while (++j < g->map->width)
		{
			coord[0] = i;
			coord[1] = j;
			a = g->map->grid[i][j];
			if (!new_pos_grid(&(*gt)->grid[i][j], coord, a, (*gt)->items))
				return (0);
		}
	}
	return (1);
}

int	set_game_test(t_game_test **gt, t_game *g)
{
	if (!set_items_test(gt, g))
		return (0);
	if (!set_can_go(gt, g))
		return (0);
	return (1);
}

void	show_data_can_go(t_pos_grid pos, t_items_test *items)
{
	int				i;
	int				j;
	t_items_test	*item;

	item = items;
	i = size_items(items);
	j = -1;
	while (++j < i)
		ft_printf("%d;", pos.can_go[j]);
}

void	show_data_gt(t_game_test *gt, t_game *g)
{
	int				i;
	int				j;
	t_items_test	*item;
	t_mem_pos		*mem_pos;

	ft_printf("DATA DE GAME_TEST\nGRID :\n");
	if (gt->grid)
	{
		i = -1;
		while (++i < g->map->height)
		{
			j  = -1;
			while (j++ < g->map->width - 1)
				ft_printf("%d", gt->grid[i][j].value);
			ft_printf("\n");
		}
		i = -1;
		while (++i < g->map->height)
		{
			ft_printf("grid[%d] :\n", i);
			j = -1;
			while (++j < g->map->width - 1)
			{
				show_data_can_go(gt->grid[i][j], gt->items);
				ft_printf("\n");
			}
			ft_printf("\n");
		}
	}
	item = gt->items;
	while (item)
	{
		ft_printf("posx->%d;posy->%d;id->%d\n", item->x, item->y, item->id);
		mem_pos = item->mem_pos;
		if (!mem_pos)
			ft_printf("Aucune position en memoire\n");
		else
			ft_printf("Mem_pos :\n");
		while (mem_pos)
		{
			ft_printf("y->%d;x->%d\n", mem_pos->y, mem_pos->x);
			mem_pos = mem_pos->next;
		}
		item = item->next;
	}
}

int	all_can_go(int size, t_pos_grid **pos, t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			k = 0;
			while (k < size && pos[i][j].can_go[k] != -1)
				k++;
			if (k == size)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_mem_pos	*rm_mem_pos(t_items_test *item, t_mem_pos *mem_pos)
{
	t_mem_pos	*tmp;
	t_mem_pos	*previous;

	if (item->mem_pos == NULL)
		return (item->mem_pos);
	previous = item->mem_pos;
	if (previous->x == mem_pos->x && previous->y == mem_pos->y)
	{
		item->mem_pos = previous->next;
		free(previous);
		return (item->mem_pos);
	}
	tmp = previous->next;
	while (tmp != NULL)
	{
		if (previous->x == mem_pos->x && previous->y == mem_pos->y)
		{
			previous->next = tmp->next;
			free(tmp);
			return (item->mem_pos);
		}
		previous = tmp;
		tmp = tmp->next;
	}
	return (item->mem_pos); 
}

int	new_mem_pos(t_items_test *item, int x, int y)
{
	t_mem_pos	*new;

	new = malloc(sizeof(t_mem_pos));
	if (!new)
		return (0);
	new->x = x;
	new->y = y;
	new->next = item->mem_pos;
	item->mem_pos = new;
	return (1);
}

int	update_y_items(t_items_test *item, t_game_test **gt, int y, int x)
{
	int	k;
	
	k = 0;
	while ((*gt)->grid[y - (++k)][x].value != 1)
	{
		ft_printf("Entree dans boucle haut\n");
		item->y -= k;
		add_can_go(&(*gt)->grid[y - k][x].can_go, item, (*gt)->items);
		item->y = y;
	}
	ft_printf("item->y->%d;i->%d;k->%d\n", item->y, x, k);
	if (item->y != y - k + 1)
	{
		ft_printf("Ajout mem_pos vers le haut\n");
		if (!new_mem_pos(item, item->x, y - k + 1))
			return (ft_printf("Erreur verification vers le haut\n"), 0);
	}
	// BAS
	k = 0;
	while ((*gt)->grid[y + (++k)][x].value != 1)
	{
		ft_printf("Entree dans boucle bas\n");
		item->y += k;
		add_can_go(&(*gt)->grid[y + k][x].can_go, item, (*gt)->items);
		item->y = y;
	}
	if (item->y != y + k - 1)
	{
		ft_printf("Ajout mem_pos vers le bas\n");
		if (!new_mem_pos(item, item->x, y + k - 1))
			return (ft_printf("Erreur verification vers le bas\n"), 0);
	}
}

int	update_x_items(t_items_test *item, t_game_test **gt, int y, int x)
{
	int	k;

	k = 0;
	while ((*gt)->grid[y][x + (++k)].value != 1)
	{
		ft_printf("Entree dans boucle droite\n");
		item->x += k;
		add_can_go(&(*gt)->grid[y][x + k].can_go, item, (*gt)->items);
		item->x = x;
		k++;
	}
	if (item->x != x + k - 1)
	{
		ft_printf("Ajout mem_pos vers la droite\n");
		if (!new_mem_pos(item, x + k - 1, item->y))
			return (ft_printf("Erreur verification vers la droite\n"), 0);
	}
	// GAUCHE
	k = 0;
	while ((*gt)->grid[y][x - (++k)].value != 1)
	{
		ft_printf("Entree dans boucle gauche\n");
		item->x -= k;
		add_can_go(&(*gt)->grid[y][x - k].can_go, item, (*gt)->items);
		item->x = x;
		k++;
	}
	if (item->x != x - k + 1)
	{
		ft_printf("Ajout mem_pos vers la gauche\n");
		if (!new_mem_pos(item, x - k + 1, item->y))
			return (ft_printf("Erreur verification vers la gauche\n"), 0);
	}
}

void	search_next_pos(t_items_test *item, int *i, int *j, t_game_test *gt)
{
	*i = item->y;
	*j = item->x;

	if (gt->grid[*i][*j])
}

int	update_can_go_items(t_items_test *item, t_game_test **gt)
{
	int			i;
	int			j;
	int			k;
	t_mem_pos	*mem_pos;

	if (item->mem_pos)
	{
		mem_pos = item->mem_pos;
		while (mem_pos)
		{
			i = mem_pos->y;
			j = mem_pos->x;
		}
	}
	else
	{
		search_next_pos(item, &i, &j, *gt);
		i = item->y;
		j = item->x;
	}
	
	
	return (1);
}

int	start_verif_map(t_game_test *gt, t_game *g)
{
	int				items_size;
	t_items_test	*item;

	items_size = size_items(gt->items);
	if (!all_can_go(items_size, gt->grid, g->map))
	{
		item = gt->items;
		while (item)
		{
			if (!update_can_go_items(item, &gt))
				return (ft_printf("Erreur update_items\n"), 0);
			item = item->next;
		}
		ft_printf("Apres modification\n");
		show_data_gt(gt, g);
	}
	return (1);
}

int verif_canwin_game(t_game *game)
{
	t_game_test	*game_test;

	game_test = malloc(sizeof(t_game_test));
	if (!game_test)
		return (ft_printf("Erreur malloc game_test\n"), (0));
	game_test->items = NULL;
	game_test->grid = NULL;
	if (!set_game_test(&game_test, game))
		return (free_game_test(game_test, game), (0));
	ft_printf("Mes donnees avant lancement de la verification :\n");
	show_data_gt(game_test, game);
	ft_printf("\nVERIFICATION POSSIBLE DE GAGNER OU NON\n");
	if (!start_verif_map(game_test, game))
		return(free_game_test(game_test, game), (0));
	free_game_test(game_test, game);
	return (1);
}
