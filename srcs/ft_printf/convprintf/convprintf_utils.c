/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convprintf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:10:40 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:49:08 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	test_cond_number1(t_params *p, char *s, int n, int j)
{
	return (p->left && s[j] != '\0'
		&& ((p->precision > 0 || n != 0) || !p->precision));
}

int	test_cond_number2(t_params *p, char *s, int n, int j)
{
	return (!p->left && s[j] != '\0'
		&& ((p->precision > 0 || n != 0) || !p->precision));
}
