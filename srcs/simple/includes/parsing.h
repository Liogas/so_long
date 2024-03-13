/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:28:27 by glions            #+#    #+#             */
/*   Updated: 2024/03/13 15:43:13 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../../file42/includes/file42.h"
# include "../../libft/includes/libft.h"

typedef struct s_image42
{
	void		*ptr;
	int			width;
	int			height;
	int			posx;
	int			posy;
	void		*mlx;
	char		*addr;
	int			bpp;
	int			endian;
	int			line_len;
}				t_image42;

typedef struct s_coord
{
	int				x;
	int				y;
}   t_coord;

typedef struct s_map_pos
{
	t_coord			*coord;
	int				value;
	t_image42		*img_ptr;
}					t_map_pos;

typedef struct s_map
{
	t_map_pos		**grid;
	int				width;
	int				height;
	int				width_g;
	int				height_g;
}					t_map;

typedef struct s_pos_algo
{
	int				*mem;
}					t_pos_algo;

typedef struct s_item_algo
{
	int				id;
	t_list			*open;
	t_list			*close;
	t_list			*trash;
}					t_item_algo;

typedef struct s_algo_verif
{
	t_pos_algo		**grid;
	t_list			*items;
}					t_algo_verif;

typedef struct s_parsing
{
	t_file42		*file;
	t_map			*map;
	t_algo_verif	*algo;
	char			*error_msg;
	int				error;
}					t_parsing;

t_parsing			*parsing(char *path_file);
t_parsing			*new_parsing(char *path_file);
void				free_parsing(t_parsing *p);

t_map				*new_map(t_parsing *p);
void				free_map(t_map *m);
t_map_pos			new_map_pos(char c, int y, int x);

t_map_pos			**init_grid(t_parsing *p, t_map **m);
void				free_grid(t_map_pos **g, t_map *m);
int					verif_border(t_parsing *p, t_map *m);
int					count_nb_items(t_parsing *p, t_map *m);

void				add_error_msg(t_parsing *p, char *msg);
void				print_error_msg(char *msg);

int					verif_winnable(t_parsing *p);
t_algo_verif		*set_up_algo(t_parsing *p);
t_list				*set_up_items(t_parsing *p);
t_pos_algo			**set_up_grid(t_parsing *p, t_list *items);

int					add_item_algo(t_coord *c, t_list **items);
int					size_items(t_list *items);
void				free_items(t_list *items);

int					search_id(t_list *items, t_coord *c);
int					set_up_line_grid(t_pos_algo **line, t_list *items, int i,
						t_parsing *p);
void				free_grid_algo(t_pos_algo **grid, t_parsing *p);

t_coord				*new_coord(int y, int x);
void				mv_coord(t_list **src, t_list **dst, t_list *e);
int					already_in(t_list *list, int y, int x);
void				add_coord(t_list **list, t_list *new);

int					next_step(t_algo_verif *algo, t_parsing *p);
void				update_mem(int **mem, int id);
int					verif_mems(t_pos_algo **grid, t_map *m, int size);
void				set_mem(int **mem, int id, int size);

void				moove_right(t_list *o, t_parsing *p, t_list **item,
						t_algo_verif *algo);
void				moove_left(t_list *o, t_parsing *p, t_list **item,
						t_algo_verif *algo);
void				moove_top(t_list *o, t_parsing *p, t_list **item,
						t_algo_verif *algo);
void				moove_bot(t_list *o, t_parsing *p, t_list **item,
						t_algo_verif *algo);
void				next_moove_item(t_list *o, t_list **i, t_algo_verif *a,
						t_parsing *p);

#endif