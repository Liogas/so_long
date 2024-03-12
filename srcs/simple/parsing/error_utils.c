/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:07:37 by glions            #+#    #+#             */
/*   Updated: 2024/03/12 10:29:09 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	add_error_msg(t_parsing *p, char *msg)
{
	char	*tmp;

	tmp = p->error_msg;
	p->error = 1;
	p->error_msg = ft_strjoin(p->error_msg, msg);
	free(tmp);
}

void	print_error_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
}
