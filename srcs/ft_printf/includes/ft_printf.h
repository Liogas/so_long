/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:23:32 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:51:42 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../../libft/includes/libft.h"

typedef struct s_params
{
	int			left;
	int			positive;
	int			zero;
	int			space;
	int			prefixe;
	int			precision;
	int			minlength;
}	t_params;

typedef struct s_lstprintf
{
	char				*str;
	char				*value;
	char				type;
	t_params			*params;
	struct s_lstprintf	*next;
}	t_lstprintf;

int				ft_printf(const char *format, ...);

t_lstprintf		*ft_lstprintf_last(t_lstprintf *l);
void			ft_lstprintf_free(t_lstprintf **l);
void			ft_lstprintfadd_back(t_lstprintf **l, t_lstprintf *n);
t_lstprintf		*ft_lstprintf_new(char *str, char type);
int				ft_lstprintf_init(t_lstprintf **l, const char *f);
int				ft_lstprintf_init_bonus(t_lstprintf **l, const char *f);
int				ft_lstprintf_strlen(t_lstprintf *l);
int				ft_lstprintf_setup(t_lstprintf **l);
int				ft_lstprintf_show(t_lstprintf *l);
void			ft_lstprintf_setup_value(t_lstprintf **l, va_list a, int bonus);

int				ft_veriflimit(char c);

char			*ft_conv_char(va_list a, t_params *p, int bonus);
char			*ft_conv_str(va_list a, t_params *p, int bonus);
char			*ft_conv_ui(va_list a, t_params *p, int bonus);
char			*ft_conv_ptr(va_list a, t_params *p, int bonus);
char			*ft_conv_inthex(va_list a, t_params *p, char type, int bonus);
char			*ft_conv_int(va_list a, t_params *p, int bonus);
int				test_cond_number1(t_params *p, char *s, int n, int j);
int				test_cond_number2(t_params *p, char *s, int n, int j);

t_params		*ft_params_new(char *f, char t);
void			ft_params_free(t_params *p);

#endif