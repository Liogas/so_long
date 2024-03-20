/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:55:38 by glions            #+#    #+#             */
/*   Updated: 2024/03/20 12:16:29 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	start_algo(t_algo_verif *algo, t_parsing *p)
{
	int	while_state;

	while_state = 1;
	while (while_state)
		while_state = next_step(algo, p);
	if (verif_mems(algo->grid, p->map, size_items(algo->items)))
		return (1);
	return (0);
}

t_list	*set_up_items(t_parsing *p)
{
	int		i;
	int		j;
	int		a;
	t_list	*list;

	i = -1;
	j = 0;
	list = NULL;
	while (++i < p->map->height)
	{
		j = -1;
		while (++j < p->map->width)
		{
			a = p->map->grid[i][j].value;
			if (a >= 2 && a <= 4)
				if (!add_item_algo(p->map->grid[i][j].coord, &list))
					return (free_items(list), NULL);
		}
	}
	return (list);
}

t_algo_verif	*set_up_algo(t_parsing *p)
{
	t_algo_verif	*algo;

	algo = malloc(sizeof(t_algo_verif));
	if (!algo)
		return (NULL);
	algo->items = set_up_items(p);
	if (!algo->items)
		return (free(algo), NULL);
	algo->grid = set_up_grid(p, algo->items);
	if (!algo->grid)
		return (NULL);
	return (algo);
}

void	free_algo(t_algo_verif *algo, t_parsing *p)
{
	free_grid_algo(algo->grid, p);
	if (algo->items)
		free_items(algo->items);
	free(algo);
}

int	verif_winnable(t_parsing *p)
{
	t_algo_verif	*algo;

	algo = set_up_algo(p);
	if (!algo)
		return (0);
	if (!start_algo(algo, p))
		return (free_algo(algo, p), 0);
	return (free_algo(algo, p), 1);
}
