/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintf_show.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:06:15 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:50:48 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_show_value(char *value, char t, int *strlen)
{
	int	i;

	i = 0;
	while (value[i] != '\0')
	{
		if (value[i] == '%' && t == '*')
		{
			*strlen = -1;
			i++;
		}
		else if (value[i] != -1)
		{
			ft_putchar_fd(value[i], 1);
			i++;
			if (*strlen != -1)
				*strlen += 1;
		}
		else
		{
			ft_putchar_fd(0, 1);
			if (*strlen != -1)
				*strlen += 1;
			i++;
		}
	}
}

int	ft_lstprintf_show(t_lstprintf *l)
{
	int	strlen;

	strlen = 0;
	while (l)
	{
		if (!l->value)
			strlen = -1;
		ft_show_value(l->value, l->type, &strlen);
		l = l->next;
	}
	return (strlen);
}
