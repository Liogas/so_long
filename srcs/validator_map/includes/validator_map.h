/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_map.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:25:08 by glions            #+#    #+#             */
/*   Updated: 2024/02/13 14:17:15 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATOR_MAP_H
# define VALIDATOR_MAP_H

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
# include "../../file42/includes/file42.h"

typedef struct	s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct  s_item_data
{
    int		id;
    int		type;
	t_coord	*coord;
    t_list	*open;
    t_list	*close;
    t_list	*can_go;
}   t_item_data;

typedef struct  s_pos_data
{
	t_coord	*coord;
    int		value;
    t_list	*can_go;
}   t_pos_data;

typedef struct  s_pos_grid2D
{
    struct s_pos_grid2D		*top;
    struct s_pos_grid2D		*right;
    struct s_pos_grid2D		*bottom;
    struct s_pos_grid2D		*left;
    void					*data;
}   t_pos_grid2D;

typedef struct  s_validator_map
{
    t_file42		*file_map;
    t_list			*items;
    t_pos_grid2D	*pos;
    int				map_w;
    int				map_h;
}   t_validator_map;

t_item_data 	*new_item_data(int id, char type, int y, int x);
void	     	free_items(t_list *items);
void	     	show_items(t_list *items);

int	        	first_verif(t_validator_map *validator);

int	        	add_in(t_coord *pos, t_list **lst);
t_list	    	*rm_from(t_list *e, t_list *l);
int	        	mv_from_to(t_list *e, t_list **from, t_list **to);

int	        	algo_canwin(t_validator_map *v);

t_pos_data		*new_pos_data(char *id, char value, t_coord *coord);
void			free_data_pos(t_pos_data *data);

void			free_pos_grid2D(t_pos_grid2D *pos);
void			free_all_pos_grid2D(t_pos_grid2D *first);
t_pos_grid2D	*new_pos_grid2D(t_pos_grid2D *top, t_pos_grid2D *left, t_pos_data *data);
t_pos_grid2D	*get_pos_grid2D(t_pos_grid2D *first, int y, int x);

void			free_validator_map(t_validator_map *validator);
t_validator_map	*new_validator_map(t_file42 *file);

void			show_can_go(void *id);
void			show_data_pos_grid(t_pos_grid2D *pos);
void			show_data_grid_test(t_validator_map *v);

#endif