/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window42_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:22:05 by glions            #+#    #+#             */
/*   Updated: 2024/03/14 10:38:04 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void    window42_free(t_window42 *win)
{
    if (win->bg)
    {
        mlx_destroy_image(win->mlx, win->bg->ptr);
        free(win->bg);
    }
    if (win->win)
        mlx_destroy_window(win->mlx, win->win);
    
    free(win);
}

t_window42  *window42_new(void *mlx, int sy, int sx)
{
    t_window42  *new;

    new = malloc(sizeof(t_window42));
    if (!new)
        return (printf("erreur malloc window\n"), NULL);
    new->mlx = mlx;
    new->win = mlx_new_window(mlx, sx, sy, "so_long(glions)");
    if (!new->win)
        return (printf("erreur creation window\n"), free(new), NULL);
    new->height = sy;
    new->width = sx;
    new->bg = NULL;
    return (new);
}
