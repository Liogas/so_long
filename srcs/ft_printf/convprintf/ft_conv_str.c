/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:03:12 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:49:27 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_params_str_len(t_params *p, char *s)
{
	if (p->minlength > (int)ft_strlen(s))
		return (p->minlength);
	else
		return (ft_strlen(s));
	return (0);
}

static int	test_cond_space(t_params *p, int i, char *s)
{
	int	tmp;

	tmp = p->precision;
	if (p->precision == -1)
		tmp = 0;
	return (p->minlength && ((!p->left
				&& ((i + (int)ft_strlen(s) < p->minlength)
					|| (p->precision && i + tmp < p->minlength)))
			|| (i < p->minlength && p->left)));
}

static char	*ft_getnext_conv_str2(char *s, t_params *p)
{
	char	*s_p;
	int		j;
	int		i;

	s_p = ft_calloc(ft_params_str_len(p, s) + 1, sizeof(char));
	if (!s_p)
		return (NULL);
	j = 0;
	i = 0;
	while ((p->left && s[j] != '\0' && !p->precision)
		|| (p->left && s[j] != '\0' && p->precision && j < p->precision
			&& ((ft_strncmp(s, "(null)", 6) != 0)
				|| (ft_strncmp(s, "(null)", 6) == 0 && p->precision >= 6))))
		s_p[i++] = s[j++];
	while (test_cond_space(p, i, s))
		s_p[i++] = ' ';
	while ((!p->left && s[j] != '\0' && !p->precision)
		|| (!p->left && s[j] != '\0' && p->precision && j < p->precision
			&& ((ft_strncmp(s, "(null)", 6) != 0)
				|| (ft_strncmp(s, "(null)", 6) == 0 && p->precision >= 6))))
		s_p[i++] = s[j++];
	return (s_p);
}

char	*ft_conv_str(va_list a, t_params *p, int bonus)
{
	char	*s;
	char	*s_p;

	s = va_arg(a, char *);
	if (s == 0)
		s = ft_strdup("(null)");
	else
		s = ft_strdup(s);
	if (!s)
		return (NULL);
	if (p && bonus)
	{
		s_p = ft_getnext_conv_str2(s, p);
		free(s);
		return (s_p);
	}
	return (s);
}
