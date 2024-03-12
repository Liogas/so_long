/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window42_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:22:05 by glions            #+#    #+#             */
/*   Updated: 2024/03/12 18:10:03 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void    window42_free(t_window42 *win)
{
    if (win->img_bckg)
    {
        mlx_destroy_image(win->mlx, win->img_bckg->ptr);
        free(win->img_bckg);
    }
    if (win->win)
        mlx_destroy_window(win->mlx, win->win);
    
    free(win);
}

t_window42  *window42_new(void *mlx, int sy, int sx)
{
    t_window42  *new;
    char        *path;

    new = malloc(sizeof(t_window42));
    if (!new)
        return (printf("erreur malloc window\n"), NULL);
    new->mlx = mlx;
    new->win = mlx_new_window(mlx, sx, sy, "so_long(glions)");
    if (!new->win)
        return (printf("erreur creation window\n"), free(new), NULL);
    new->height = sy;
    new->width = sx;
    path = "./srcs/simple/imgs/bckg.xpm";
    new->img_bckg = image42_new(new->height, new->width, path, mlx);
    if (!new->img_bckg)
        return (printf("Erreur image de fond\n"), window42_free(new), NULL);
    // mlx_put_image_to_window(mlx, new->win, new->img_bckg->ptr, 0, 0);
    return (new);
}
