/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintf_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:07:12 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:50:37 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_lstprintf	*ft_lstprintf_last(t_lstprintf *l)
{
	if (l)
	{
		while (l->next)
			l = l->next;
		return (l);
	}
	return (NULL);
}
