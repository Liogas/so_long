/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_hex_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:30:27 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:47:05 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putptr_hex_fd(unsigned long long ptr, int fd)
{
	ft_putstr_fd("0x", fd);
	if (ptr == 0)
		ft_putchar_fd('0', fd);
	else
		ft_putnbr_hex_fd(ptr, fd, 0);
}
