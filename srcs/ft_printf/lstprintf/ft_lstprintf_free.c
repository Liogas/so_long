/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintf_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:04:41 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:50:26 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_lstprintf_free(t_lstprintf **l)
{
	t_lstprintf	*tmp;

	while (*l)
	{
		tmp = (*l)->next;
		if ((*l)->params)
			ft_params_free((*l)->params);
		free((*l)->value);
		free((*l)->str);
		free(*l);
		*l = tmp;
	}
}
