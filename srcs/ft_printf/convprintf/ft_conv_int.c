/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:08:24 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:49:15 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_params_i_len(t_params *p, int n, char *s, int *tmp)
{
	int	len;
	int	add;

	len = 0;
	if (p->minlength > (int)ft_strlen(s))
		len = p->minlength;
	else
	{
		if (p->positive || (p->space && n >= 0))
			len++;
		if (n < 0)
			add = 1;
		else
			add = 0;
		while (p->precision > (int)ft_strlen(s) - add--)
			len++;
		len += ft_strlen(s);
	}
	if (n >= 0)
		*tmp = 0;
	else
		*tmp = 1;
	return (len);
}

static void	while_space(t_params *p, int *i, char *s, char **s_p)
{
	while (((p->space && !p->zero) || (!p->space && !p->zero && p->minlength))
		&& ((!p->left && *i + (int)ft_strlen(s) < p->minlength)
			|| (*i < p->minlength && p->left)))
		(*s_p)[(*i)++] = ' ';
}

static int	test_cond_positive(t_params **p, int n, char **s_p, int i)
{
	if ((*p)->positive && n >= 0
		&& !(*p)->space && !(*p)->zero && !(*p)->left && (*p)->minlength)
	{
		if (i == -1)
			(*p)->minlength -= 1;
		else
		{
			(*s_p)[i] = '+';
			i += 1;
		}
	}
	return (i);
}

static char	*ft_getnext_conv_int2(char *s, int n, t_params *p, int i)
{
	char	*s_p;
	int		j;
	int		tmp;

	s_p = ft_calloc(ft_params_i_len(p, n, s, &tmp) + 1, sizeof(char));
	if (!s_p)
		return (NULL);
	j = 0;
	if (p->positive && n >= 0)
		s_p[i++] = '+';
	else if (n < 0 && (p->zero || p->space || p->precision))
		s_p[i++] = s[j++];
	else if (p->space && !p->positive && n >= 0)
		s_p[i++] = ' ';
	while (test_cond_number1(p, s, n, j))
		s_p[i++] = s[j++];
	while ((p->zero && i + (int)ft_strlen(s) - j < p->minlength)
		|| (int)ft_strlen(s) - tmp-- < p->precision)
		s_p[i++] = '0';
	test_cond_positive(&p, n, &s_p, -1);
	while_space(p, &i, s, &s_p);
	i = test_cond_positive(&p, n, &s_p, i);
	while (test_cond_number2(p, s, n, j))
		s_p[i++] = s[j++];
	return (s_p);
}

char	*ft_conv_int(va_list a, t_params *p, int bonus)
{
	char	*s;
	int		nb;
	char	*s_p;
	int		i;

	nb = va_arg(a, int);
	s = ft_itoa(nb);
	i = 0;
	if (!s)
		return (NULL);
	if (p && bonus)
	{
		s_p = ft_getnext_conv_int2(s, nb, p, i);
		free(s);
		return (s_p);
	}
	return (s);
}
