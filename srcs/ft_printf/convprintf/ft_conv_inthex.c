/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_inthex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:06:19 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:49:17 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_params_inthex_len(t_params *p, unsigned int n, char *s)
{
	int	len;
	int	add;

	len = 0;
	(void)n;
	if (p->minlength > (int)ft_strlen(s))
		len = p->minlength;
	else
	{
		if (p->prefixe)
			len += 2;
		add = 0;
		while (p->precision > (int)ft_strlen(s) - add--)
			len++;
		len += ft_strlen(s);
	}
	return (len);
}

static int	test_cond_space(t_params *p, int i, char *s)
{
	return (((p->space && !p->zero) || (!p->space && !p->zero && p->minlength))
		&& (((!p->left && i + 2 + (int)ft_strlen(s) < p->minlength)
				|| (!p->left && i + (int)ft_strlen(s) < p->minlength
					&& !p->prefixe))
			|| (i < p->minlength && p->left)));
}

static void	ft_addprefixe(char	**s, int *i)
{
	ft_strlcat(*s, "0x", ft_strlen(*s) + 3);
	*i += 2;
}

static char	*ft_getnext_conv_inthex2(char *s, unsigned int n, t_params *p)
{
	char	*s_p;
	int		j;
	int		i;
	int		tmp;

	s_p = ft_calloc(ft_params_inthex_len(p, n, s) + 1, sizeof(char));
	if (!s_p)
		return (NULL);
	i = 0;
	if (p->prefixe && ((p->left && s[0] != '0') || (p->precision)))
		ft_addprefixe(&s_p, &i);
	j = 0;
	while (test_cond_number1(p, s, n, j))
		s_p[i++] = s[j++];
	tmp = 0;
	while ((p->zero && !p->left && i + (int)ft_strlen(s) < p->minlength)
		|| (int)ft_strlen(s) - tmp-- < p->precision)
		s_p[i++] = '0';
	while (test_cond_space(p, i, s))
		s_p[i++] = ' ';
	if (p->prefixe && !p->left && s[0] != '0' && !p->precision)
		ft_addprefixe(&s_p, &i);
	while (test_cond_number2(p, s, n, j))
		s_p[i++] = s[j++];
	return (s_p);
}

char	*ft_conv_inthex(va_list a, t_params *p, char type, int bonus)
{
	char	*s;
	int		nb;
	char	*s_p;

	nb = va_arg(a, unsigned int);
	s = ft_itoa_hex(nb);
	if (!s)
		return (NULL);
	if (p && bonus)
	{
		s_p = ft_getnext_conv_inthex2(s, nb, p);
		free(s);
		if (type == 'X')
			return (ft_strupper(s_p));
		return (s_p);
	}
	if (type == 'X')
		return (ft_strupper(s));
	return (s);
}
