/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintf_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:36:49 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:50:31 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*getnext_str(const char *f)
{
	int		i;

	if (!f || !f[0])
		return (NULL);
	if (f[0] == '%' && ft_veriflimit(f[1]))
		return (ft_strndup((char *)f, 2));
	else if (f[0] == '%' && !ft_veriflimit(f[1]))
		return (ft_strndup("%", 1));
	i = 0;
	while (f[i] != '\0' && f[i] != '%')
		i++;
	return (ft_strndup((char *)f, i));
}

int	ft_lstprintf_init(t_lstprintf **l, const char *f)
{
	char		*new_str;
	char		type;
	t_lstprintf	*new;
	int			i;

	new_str = getnext_str((char *)f);
	i = 0;
	while (new_str)
	{
		if (new_str[0] == '%' && new_str[1])
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
