/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 01:02:31 by glions            #+#    #+#             */
/*   Updated: 2024/04/21 19:21:25 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

#include <stdlib.h>
#include "gl_utils.h"

typedef struct	s_list_gl
{
	void				*content;
	struct s_list_gl	*next;
}	t_list_gl;

// INIT
t_list_gl	*new_element_gl(void *content);

// FREE
void	free_list_gl(t_list_gl **list, void (*del)(void *));
void	free_element_gl(t_list_gl **list, void (*del)(void *), t_list_gl *element);

// ADD ELEMENT ON LIST
int	addback_list_gl(t_list_gl **list, t_list_gl *element);
int	addfront_list_gl(t_list_gl **list, t_list_gl *element);
int	addafter_list_gl(t_list_gl **before, t_list_gl *element);
int	addbefore_list_gl(t_list_gl **list, t_list_gl *after, t_list_gl *element);

#endif