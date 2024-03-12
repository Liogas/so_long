/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintfadd_back.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:08:20 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:50:55 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_lstprintfadd_back(t_lstprintf **l, t_lstprintf *n)
{
	if (l && n)
	{
		if (*l == NULL)
			*l = n;
		else
			ft_lstprintf_last(*l)->next = n;
	}
}
