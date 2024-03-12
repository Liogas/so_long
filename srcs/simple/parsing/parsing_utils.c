/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:37:33 by glions            #+#    #+#             */
/*   Updated: 2024/03/12 10:29:20 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	free_parsing(t_parsing	*p)
{
	if (p->file)
		free_file42(p->file);
	if (p->map)
		free_map(p->map);
	if (p->error_msg)
		free(p->error_msg);
	free(p);
}

t_parsing	*new_parsing(char *path_file)
{
	t_parsing	*new;

	new = malloc(sizeof(t_parsing));
	new->error = 0;
	new->map = NULL;
	new->algo = NULL;
	if (!new)
		return (write(2, "ERROR\n", 6), NULL);
	new->error_msg = ft_strdup("ERROR\n");
	if (!new->error_msg)
		return (write(2, "ERROR\nMalloc error_msg\n", 23), new);
	new->file = new_file42(path_file, O_RDONLY);
	if (!new->file)
		return (add_error_msg(new, "Erreur ouverture fichier\n"), new);
	read_all_file42(new->file);
	if (!new->file->lines)
		return (add_error_msg(new, "Contenu du fichier vide\n"), new);
	new->map = new_map(new);
	if (!new->map)
		return (new);
	return (new);
}
