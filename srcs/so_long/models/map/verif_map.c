/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:38:03 by glions            #+#    #+#             */
/*   Updated: 2024/01/05 10:48:56 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	verif_border_tb(char **map, int width, int height)
{
	int	i;
	int	j;
	int	c;

	j = 0;
	i = 0;
	c = 0;
	ft_printf("height->%d", height);
	while (j < width && map[i][j++] == '1')
		c++;
	i = height - 1;
	j = 0;
	while (j < width && map[i][j++] == '1')
		c++;
	ft_printf("Valeur de c->%d\n", c);
	if (c != width * 2)
		return (0);
	return (1);
}

int	verif_border_lr(char **map, int width, int height)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (i < height && map[i++][j] == '1')
		c++;
	i = 0;
	j = width - 1;
	while (i < height && map[i++][j] == '1')
		c++;
	ft_printf("Valeur de c->%d\n", c);
	if (c != height * 2)
		return (0);
	return (1);
}

int	verif_border_map(char **map, int width, int height)
{
	return (verif_border_lr(map, width, height) +
		verif_border_tb(map, width, height));
}

int	verif_items_map(char **map, int width, int height)
{
	int cpe;
	int co;
	int	i;
	int	j;

	cpe = 0;
	co = 0;
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			if (map[i][j] == 'P')
				cpe++;
			else if (map[i][j] == 'E')
				cpe++;
			else if (map[i][j] == 'C')
				co++;
		}
	}
	if (cpe != 2 || co <= 0)
		return (0);
	return (1);
}

int	verif_map(char **map, int width, int height)
{
	if (verif_border_map(map, width, height) != 2)
		return (ft_printf("Erreur bordure\n"), (0));
	if (!verif_items_map(map, width, height))
		return (ft_printf("Erreur items\n"), (0));
	return (1);
}