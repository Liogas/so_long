/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:22:09 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:49:55 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int				strlen;
	t_lstprintf		*lst;
	va_list			args;

	lst = NULL;
	va_start(args, format);
	if (!ft_lstprintf_init_bonus(&lst, format))
		return (ft_lstprintf_free(&lst), (-1));
	if (!ft_lstprintf_setup(&lst))
		return (ft_lstprintf_free(&lst), (-1));
	ft_lstprintf_setup_value(&lst, args, 1);
	strlen = ft_lstprintf_show(lst);
	ft_lstprintf_free(&lst);
	va_end(args);
	return (strlen);
}
// int	main(void)
// {
// 	int	a;
// 	int	b;

// 	// a = printf("%d", 5);
// 	// printf("\n");
// 	// b = ft_printf("%d", 5);
// 	// printf("\nprintf->%d|ft_print->%d\n", a, b);
// 	// a = printf("%s", "Je suis un test");
// 	// printf("\n");
// 	// b = ft_printf("%s", "Je suis un test");
// 	// printf("\nprintf->%d|ft_print->%d\n", a, b);
// 	// a = printf("%d", 5);
// 	// printf("\n");
// 	// b = ft_printf("%d", 5);
// 	// printf("\nprintf->%d|ft_print->%d\n", a, b);
// 	// a = printf("%x", 5484);
// 	// printf("\n");
// 	// b = ft_printf("%x", 5484);
// 	// printf("\nprintf->%d|ft_print->%d\n", a, b);
// 	// a = printf("%X", 5484);
// 	// printf("\n");
// 	// b = ft_printf("%X", 5484);
// 	// printf("\nprintf->%d|ft_print->%d\n", a, b);
// 	// a = printf("%u", 5484);
// 	// printf("\n");
// 	// b = ft_printf("%u", 5484);
// 	// printf("\nprintf->%d|ft_print->%d\n", a, b);
// 	// a = printf("%c", 'd');
// 	// printf("\n");
// 	// b = ft_printf("%c", 'd');
// 	// printf("\nprintf->%d|ft_print->%d\n", a, b);
// 	// a = printf("%i", '5');
// 	// printf("\n");
// 	// b = ft_printf("%i", '5');
// 	// printf("\nprintf->%d|ft_print->%d\n", a, b);
// 	a = ft_printf("%1c", 'a');
// 	printf("\n");
// 	b = printf("%1c", 'a');
// 	printf("\nprintf->%d|ft_print->%d\n", a, b);
// 	return (0);
// }