/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintf_setup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:42:33 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:50:45 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_lstprintf_setup(t_lstprintf **l)
{
	int			i;
	t_lstprintf	*first;

	i = 0;
	while (*l)
	{
		if ((*l)->str[0] == '%' && !ft_veriflimit((*l)->str[1])
			&& (*l)->str[1] != '%')
		{
			(*l)->params = ft_params_new((*l)->str, (*l)->type);
			if (!(*l)->params)
				return (0);
		}
		if (i == 0)
			first = *l;
		*l = (*l)->next;
		i++;
	}
	*l = first;
	return (1);
}
