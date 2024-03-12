/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainC.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:52:32 by glions            #+#    #+#             */
/*   Updated: 2024/01/04 13:50:46 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	int	fd_map;

	if (argc != 2)
		return (ft_printf("ERROR ARG\n"), (1));
	fd_map = open_map(argv[1]);
	if (fd_map < 0)
		return (perror("ERROR OPEN"), (1));
	return (game(fd_map, argv[1]));
}
