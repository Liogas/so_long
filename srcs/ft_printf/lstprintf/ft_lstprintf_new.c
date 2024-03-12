/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintf_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:08:59 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:50:40 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_lstprintf	*ft_lstprintf_new(char *str, char type)
{
	t_lstprintf	*new;

	new = malloc(sizeof(t_lstprintf));
	if (!new)
		return (NULL);
	new->str = str;
	new->type = type;
	new->next = NULL;
	new->params = NULL;
	new->value = NULL;
	return (new);
}
