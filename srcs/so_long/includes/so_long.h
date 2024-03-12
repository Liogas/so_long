/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:53:02 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:40:31 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

# ifndef BONUS
#  define BONUS 0
# endif

typedef struct s_mob
{
	int				id;
	int				x;
	int				y;
	struct s_mob	*next;
}	t_mob;

typedef struct s_object
{
	int				id;
	int				id_player;
	int				x;
	int				y;
	struct s_object	*next;
}	t_object;

typedef struct s_player
{
	int	id;
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	char		*path_file;
	int			fd;
	int			width;
	int			height;
	int			**grid;
}	t_map;

typedef struct s_game
{
	int			state;
	int			turn;
	t_map		*map;
	t_mob		*mobs;
	t_object	*objects;
	t_player	*player;
}	t_game;

typedef struct s_file
{
	char	*path_file;
	int		fd;
}	t_file;
typedef struct s_validator_map
{
	
}	t_validator_map;

// GAME
// controller/game
/**
 * game
 * @param fd_map file descriptor of the map
 * @param path_file path of the file containing the map's data
 * @return 1 (KO) / 0 (OK)
*/
int			game(int fd_map, char *path_file);
/**
 * new_turn
 * @param game pointer on the game's memory block
 * @return -1(ko) or 0(ok) 1(ok, game finish)
*/
int			new_turn(t_game **game);

t_game		*new_game(int fd, char *path_file);
/**
 * free_game
 * @param game memory block to free
*/
void		free_game(t_game *game);
/**
 * set_data_from_map
 * @param game pointer on the game's memory block
 * @return 1(ko) or 0(ok)
*/
int			set_data_from_map(t_game **game);
int			validator_solong(t_game *game);

// MAP
// controller/file
/**
 * open_map
 * @param path_file path of the file containing the map's data
 * @return file descripteur of the map
*/
int			open_map(char *path_file);
/**
 * read_map
 * @param map map's memory block
 * @return lines on file
*/
char		**read_map(t_map **map);
// model/game
/**
 * new_game
 * @param fd file descriptor of the map
 * @param path_file path of the file containing the map's data
 * @return game's block memory or NULL
*/
// model/map
/**
 * new_map
 * @param path_file path of the file containing the map's data
 * @param fd file descriptor of the map
 * @return map's memory block or NULL
*/
t_map		*new_map(char *path_file, int fd);
/**
 * free_map
 * @param map map's memory block to free
*/
void		free_map(t_map *map);
/**
 * free_lines
 * @param lines lines to free
*/
void		free_lines(char **lines);
/**
 * load_map :
 * generates the grid using the data read in the map's file
 * @param map map's memory block
 * @return 0 (ko) or 1 (ok)
*/
int			load_map(t_map	**map);
/**
 * update_grid
 * @param grid pointer on the grid to update
 * @param direction direction of the player
 * @param player player"s memory block
*/
void		update_grid(int ***grid, char direction, t_player *player);
int			verif_map(char **map, int width, int height);

// view/map
/**
 * show_data_map
 * @param map map's memory block to print on terminal
*/
void		show_data_map(t_map *map);
/**
 * show_grid_map
 * @param map map's memory block containing the grid to print on terminal
*/
void		show_grid_map(t_map *map);

// PLAYER
// model/player
void		set_start_player(int y, int x, t_player *player);
/**
 * free_player
 * @param player player's memory block
*/
void		free_player(t_player *player);

t_player	*new_player(void);
/**
 * can_right_player
 * @param map map's memory block
 * @param player pointer on the player's memory block
 * @return 0(ko) or 1(ok)
*/
int			can_right_player(t_map *map, t_player **player);
/**
 * can_left_player
 * @param map map's memory block
 * @param player pointer on the player's memory block
 * @return 0(ko) or 1(ok)
*/
int			can_left_player(t_map *map, t_player **player);
/**
 * can_down_player
 * @param map map's memory block
 * @param player pointer on the player's memory block
 * @return 0(ko) or 1(ok)
*/
int			can_down_player(t_map *map, t_player **player);
/**
 * can_up_player
 * @param map map's memory block
 * @param player pointer on the player's memory block
 * @return 0(ko) or 1(ok)
*/
int			can_up_player(t_map *map, t_player **player);
/**
 * move_player
 * @param direction direction of the player
 * @param player pointer on the player's memory block
*/
void		move_player(char direction, t_player **player);
// view/player
/**
 * show_data_player
 * @param player player's memory block to print on terminal
*/
void		show_data_player(t_player *player);

// OBJECT
// model/object
/**
 * size_objects
 * @param object first element of the list
 * @return size of the list
*/
int			size_objects(t_object *object);
/**
 * new_object
 * @param id
 * @param y position y on the grid
 * @param x position x on the grid
 * @return object's memory block or NULL
*/
t_object	*new_object(int id, int y, int x);
/**
 * add_object
 * @param objects pointer on the first element of the list
 * @param y position y on the grid
 * @param x position x on the grid
 * @return 1(ko) or 0(ok)
*/
int			add_object(t_object **objects, int y, int x);
/**
 * free_object
 * @param l first element of the list
*/
void		free_objects(t_object *l);
/**
 * verif_object
 * @param objects pointer on the first element of the list
 * @param player player's memory block
*/
void		verif_object(t_object **objects, t_player *player);

/**
 * set_start_player
 * @param y position y on the grid
 * @param x position x on the grid
 * @param player player's memory block
*/
// view/object
/**
 * show_data_objects
 * @param map first element of the list to print on terminal
*/
void		show_data_objects(t_object	*objects);
/**
 * show_data_object
 * @param map object's memory block to print on terminal
*/
void		show_data_object(t_object *object);

#endif