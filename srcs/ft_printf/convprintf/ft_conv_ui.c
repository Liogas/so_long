/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:05:18 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:49:30 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_params_ui_len(t_params *p, char *s)
{
	int	len;
	int	add;

	len = 0;
	if (p->minlength > (int)ft_strlen(s))
		return (p->minlength);
	else
	{
		add = 0;
		while (p->precision > (int)ft_strlen(s) - add--)
			len++;
		len += ft_strlen(s);
	}
	return (len);
}

static int	test_cond_space(t_params *p, int i, char *s)
{
	return ((!p->space && !p->zero && p->minlength)
		&& ((!p->left && i + (int)ft_strlen(s) < p->minlength)
			|| (i < p->minlength && p->left)));
}

static char	*ft_getnext_conv_uint2(char *s, unsigned int n, t_params *p)
{
	char	*s_p;
	int		j;
	int		i;
	int		tmp;

	s_p = ft_calloc(ft_params_ui_len(p, s) + 1, sizeof(char));
	if (!s_p)
		return (NULL);
	j = 0;
	i = 0;
	tmp = 0;
	while (test_cond_number1(p, s, n, j))
		s_p[i++] = s[j++];
	while ((p->zero && i + (int)ft_strlen(s) < p->minlength)
		|| (int)ft_strlen(s) - tmp-- < p->precision)
		s_p[i++] = '0';
	while (test_cond_space(p, i, s))
		s_p[i++] = ' ';
	while (test_cond_number2(p, s, n, j))
		s_p[i++] = s[j++];
	return (s_p);
}

char	*ft_conv_ui(va_list a, t_params *p, int bonus)
{
	char			*s;
	char			*s_p;
	unsigned int	nb;

	nb = va_arg(a, unsigned int);
	s = ft_utoa(nb);
	if (!s)
		return (NULL);
	if (p && bonus)
	{
		s_p = ft_getnext_conv_uint2(s, nb, p);
		free(s);
		return (s_p);
	}
	return (s);
}
