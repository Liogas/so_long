/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_solong.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:28:50 by glions            #+#    #+#             */
/*   Updated: 2024/02/13 14:27:50 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/validator_map.h"

int	main(int argc, char **argv)
{
	t_file42		*file;
	t_validator_map	*validator;

	if (argc != 2)
		return (ft_printf("ERROR ARGUMENT"), (1));
	file = new_file42(argv[1], O_RDONLY);
	if (!file || file->fd < 0)
		return (ft_printf("ERROR NEW FILE"), (1));
	read_all_file42(file);
	show_data_file42(file, "TEST AFFICHAGE DATA");
	validator = new_validator_map(file);
	if (!validator)
		return (free_file42(file), (1));
	if (!first_verif(validator))
		return (ft_printf("Erreur verification\n"),
			free_validator_map(validator), (1));
	if (!algo_canwin(validator))
		return (ft_printf("ALGO_CAN WIN 0\n"), free_validator_map(validator),
			free_file42(file), (1));
	free_validator_map(validator);
	free_file42(file);
	return (0);
}
