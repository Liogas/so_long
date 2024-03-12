/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintf_strlen.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:53:49 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:50:51 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_lstprintf_strlen(t_lstprintf *l)
{
	int	strlen;

	strlen = 0;
	while (l)
	{
		strlen++;
		l = l->next;
	}
	return (strlen);
}
