/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:37:50 by glions            #+#    #+#             */
/*   Updated: 2024/03/18 11:05:18 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/game.h"

int	main(int ac, char **av)
{
	t_parsing	*p;
	t_game		*g;

	if (ac != 2)
		return (write(2, "ERROR\nONLY ONE ARG REQUIRED\n", 28), 1);
	p = parsing(av[1]);
	if (!p)
		return (1);
	g = game_new(p);
	if (!g)
		return (free_parsing(p, 0), 1);
	free_parsing(p, 0);
	if (!game_start(g))
		return (game_free(g), free_parsing(p, 0), 1);
	game_free(g);
	return (0);
}
