/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:01:57 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:49:12 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_params_char_len(t_params *p, char *s)
{
	if (p->minlength > (int)ft_strlen(s))
		return (p->minlength);
	else
		return (1);
}

static int	test_cond_space(t_params *p, int i, char *s)
{
	return (((p->space && !p->zero) || (!p->space && !p->zero && p->minlength))
		&& ((!p->left && i + (int)ft_strlen(s) < p->minlength)
			|| (i < p->minlength && p->left)));
}

static char	*ft_getnext_conv_char2(char *s, t_params *p)
{
	char	*s_p;
	int		j;
	int		i;

	s_p = ft_calloc(ft_params_char_len(p, s) + 1, sizeof(char));
	if (!s_p)
		return (NULL);
	j = 0;
	i = 0;
	if (p->space)
		s_p[i++] = ' ';
	while (p->left && s[j] != '\0')
		s_p[i++] = s[j++];
	while (test_cond_space(p, i, s))
		s_p[i++] = ' ';
	while (!p->left && s[j] != '\0')
		s_p[i++] = s[j++];
	return (s_p);
}

char	*ft_conv_char(va_list a, t_params *p, int bonus)
{
	char	*s;
	char	c;
	char	*s_p;

	s = ft_calloc(2, sizeof(char));
	if (!s)
		return (NULL);
	c = (char)va_arg(a, int);
	if (!c)
		c = -1;
	s[0] = c;
	if (s[0] == '\0')
		printf("bien le \\0\n");
	if (p && bonus)
	{
		s_p = ft_getnext_conv_char2(s, p);
		free(s);
		return (s_p);
	}
	return (s);
}
