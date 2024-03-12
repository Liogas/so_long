/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:37:50 by glions            #+#    #+#             */
/*   Updated: 2024/03/12 16:51:26 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/game.h"

int	main(int ac, char **av)
{
	t_parsing	*p;
	t_game		*g;

	if (ac != 2)
		return (1);
	p = parsing(av[1]);
	if (!p)
		return (1);
	g = game_new(p);
	if (!g)
		return (printf("Erreur creation de la game\n"), free_parsing(p), 1);
	if (!game_start(g))
		return (write(1, "Fait chier !\n", 13), game_free(g), free_parsing(p), 1);
	game_free(g);
	free_parsing(p);
	return (0);
}
