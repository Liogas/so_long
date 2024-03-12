/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintf_setup_value.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:44:14 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:50:43 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_lstprintf_setup_value(t_lstprintf **l, va_list a, int bonus)
{
	t_lstprintf	*first;

	first = *l;
	while (*l)
	{
		if ((*l)->type == 'c')
			(*l)->value = ft_conv_char(a, (*l)->params, bonus);
		else if ((*l)->type == 's')
			(*l)->value = ft_conv_str(a, (*l)->params, bonus);
		else if ((*l)->type == 'd' || (*l)->type == 'i')
			(*l)->value = ft_conv_int(a, (*l)->params, bonus);
		else if ((*l)->type == 'x' || (*l)->type == 'X')
			(*l)->value = ft_conv_inthex(a, (*l)->params, (*l)->type, bonus);
		else if ((*l)->type == 'u')
			(*l)->value = ft_conv_ui(a, (*l)->params, bonus);
		else if ((*l)->type == 'p')
			(*l)->value = ft_conv_ptr(a, (*l)->params, bonus);
		else if ((*l)->type == '%')
			(*l)->value = ft_strdup("%");
		else
			(*l)->value = ft_strdup((*l)->str);
		*l = (*l)->next;
	}
	*l = first;
}
