/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:07:37 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:49:24 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_params_ptr_len(t_params *p, char *s)
{
	if (p->minlength > (int)ft_strlen(s))
		return (p->minlength);
	else
		return (ft_strlen(s));
	return (0);
}

static int	test_cond_space(t_params *p, int i, char *s)
{
	return (p->minlength && ((!p->left && i + (int)ft_strlen(s) < p->minlength)
			|| (i < p->minlength && p->left)));
}

static char	*ft_getnext_conv_ptr2(char *s, t_params *p)
{
	char	*s_p;
	int		j;
	int		i;

	s_p = ft_calloc(ft_params_ptr_len(p, s) + 1, sizeof(char));
	if (!s_p)
		return (NULL);
	j = 0;
	i = 0;
	while (p->left && s[j] != '\0'
		&& ((p->precision && j < p->precision) || !p->precision))
		s_p[i++] = s[j++];
	while (test_cond_space(p, i, s))
		s_p[i++] = ' ';
	while (!p->left && s[j] != '\0')
		s_p[i++] = s[j++];
	return (s_p);
}

char	*ft_conv_ptr(va_list a, t_params *p, int bonus)
{
	char		*s;
	long long	nb;
	char		*s_p;

	nb = va_arg(a, long long);
	if (!nb)
		s = ft_strdup("(nil)");
	else
		s = ft_ptoa(nb);
	if (!s)
		return (NULL);
	if (p && bonus)
	{
		s_p = ft_getnext_conv_ptr2(s, p);
		free(s);
		return (s_p);
	}
	return (s);
}
