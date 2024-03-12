/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:49:58 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:49:48 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_params_getnbr(char *f, int *i)
{
	int	end;

	end = 0;
	while (f[end] != '\0' && ft_isdigit(f[end]))
	{
		end++;
		*i += 1;
	}
	*i -= 1;
	return (ft_atoin(f, end));
}

static int	test_cond(char *f, int i, char t, int m)
{
	if (m == 0)
		return (t == 'd' || t == 'i' || t == 'x' || t == 'X'
			|| t == 'u' || t == 's' || t == 'c' || t == 'p');
	else
		return (f[i] == '.' && (t == 's' || t == 'd'
				|| t == 'i' || t == 'u' || t == 'x' || t == 'X'));
}

static int	test_cond_space(char *f, int i, char t, t_params *p)
{
	if (f[i] == ' ' && !p->zero
		&& (t == 's' || t == 'd' || t == 'i'))
		return (1);
	return (0);
}

static void	ft_params_setup(t_params **p, char *f, char t, int i)
{
	if (test_cond(f, i, t, 0))
	{
		while (f[i] != '\0')
		{
			if (f[i] == '-')
				(*p)->left = 1;
			else if (f[i] == '+' && (t == 'd' || t == 'i'))
				(*p)->positive = 1;
			else if (f[i] == '0')
				(*p)->zero = 1;
			else if (test_cond_space(f, i, t, *p))
				(*p)->space = 1;
			else if (f[i] == '#' && (t == 'u' || t == 'x' || t == 'X'))
				(*p)->prefixe = 1;
			else if (ft_isdigit(f[i]))
				(*p)->minlength = ft_params_getnbr(f + i, &i);
			else if (test_cond(f, i, t, 2))
			{
				(*p)->precision = ft_params_getnbr(f + (++i), &i);
				if (!(*p)->precision)
					(*p)->precision = -1;
			}
			i++;
		}
	}
}

t_params	*ft_params_new(char *f, char t)
{
	t_params	*new;
	int			i;

	new = malloc(sizeof(t_params));
	if (!new)
		return (NULL);
	new->left = 0;
	new->positive = 0;
	new->zero = 0;
	new->space = 0;
	new->prefixe = 0;
	new->minlength = 0;
	new->precision = 0;
	i = 0;
	ft_params_setup(&new, f, t, i);
	return (new);
}
