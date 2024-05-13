/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_element_gl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 01:09:02 by glions            #+#    #+#             */
/*   Updated: 2024/05/13 14:27:36 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl_list.h"

t_list_gl	*new_element_gl(void *content)
{
	t_list_gl	*new;

	if (!content)
		return (NULL);
	new = malloc(sizeof(t_list_gl));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
