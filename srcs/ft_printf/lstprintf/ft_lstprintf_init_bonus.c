/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintf_init_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:37:58 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:50:29 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*getnext_str(const char *f)
{
	int		i;

	i = 0;
	while (f[i] != '\0'
		&& ((f[0] == '%' && (i == 0 || !ft_veriflimit(f[i])))
			|| (f[0] != '%' && f[i] != '%')))
	{
		if (f[0] == '%' && i != 0 && f[i] == '%')
			break ;
		i++;
	}
	if (i > 0)
	{
		if (f[0] == '%')
			return (ft_strndup((char *)f, i + 1));
		return (ft_strndup((char *)f, i));
	}
	return (NULL);
}

int	ft_lstprintf_init_bonus(t_lstprintf **l, const char *f)
{
	char		*new_str;
	char		type;
	t_lstprintf	*new;
	int			i;

	new_str = getnext_str((char *)f);
	i = 0;
	while (new_str)
	{
		if (new_str[0] == '%')
			type = new_str[ft_strlen(new_str) - 1];
		else
			type = '*';
		new = ft_lstprintf_new(new_str, type);
		if (!new)
		{
			ft_lstprintf_free(l);
			return (0);
		}
		ft_lstprintfadd_back(l, new);
		i += ft_strlen(new->str);
		new_str = getnext_str((char *)f + i);
	}
	return (1);
}
