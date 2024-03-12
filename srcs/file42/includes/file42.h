/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file42.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:29:11 by glions            #+#    #+#             */
/*   Updated: 2024/02/09 10:56:23 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FILE42_H
# define	FILE42_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../../libft/includes/libft.h"
# include "../../ft_printf/includes/ft_printf.h"
# include "../../gnl/includes/get_next_line.h"

typedef struct s_file42
{
	char	*pathfile;
	int		fd;
	t_list	*lines;
	int		nblines;
}	t_file42;

t_file42	*new_file42(char *pathfile, int __oflag);
void		free_file42(t_file42 *file);
void		show_data_file42(t_file42 *file, char *title);
int			read_nextline_file42(t_file42 *file);
void		read_all_file42(t_file42 *file);

#endif