/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_42.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:27:09 by glions            #+#    #+#             */
/*   Updated: 2024/03/12 18:29:13 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_42.h"

void	destroy_img(t_data *data, t_image *image)
{
	t_sprite	*tmp;
	if (image)
	{
		if (image->img_ptr)
			mlx_destroy_image(data->mlx_ptr, image->img_ptr);
		tmp = image->walks;
		while (image->walks)
		{
			image->walks = image->walks->next;
			free(tmp);
		}
		free(image);
	}
}

void	destroy_data(t_data *data)
{
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->img)
		destroy_img(data, data->img->img_ptr);
	free(data);
}

void	test_animation(t_data *data)
{
	int			tmp;
	t_sprite	*img;

	tmp = data->img->posx;
	img = data->img->walks;
	while (data->img->posx != tmp + 200)
	{
		data->img->posx += 5;
		mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
		if (!img->next)
			img = data->img->walks;
		else
			img = img->next;
		data->img->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, img->path, &data->img_width, &data->img_height);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, data->img_width, data->img_height);
	}
}

int	key_listener(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_loop_end(data->mlx_ptr);
	}
	else if (keycode == XK_D || keycode == XK_d)
		test_animation(data);
	return (0);
}

t_sprite	*new_sprite(char *path)
{
	t_sprite	*new;

	new = malloc(sizeof(t_sprite));
	if (!new)
		return (NULL);
	new->path = path;
	new->next = NULL;
	return (new);
}

void	add_sprite(t_sprite *new, t_sprite **lst)
{
	t_sprite	*tmp;

	if (!(*lst) || !new)
		return ;
	if (!(*lst)->next)
		(*lst)->next = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	load_walks(t_sprite **walks)
{
	(*walks)->next = new_sprite("./test/walks/walk2.xpm");
	add_sprite(new_sprite("./test/walks/walk3.xpm"), walks);
	add_sprite(new_sprite("./test/walks/walk4.xpm"), walks);
	add_sprite(new_sprite("./test/walks/walk5.xpm"), walks);
	add_sprite(new_sprite("./test/walks/walk6.xpm"), walks);
}

int	main(void)
{
	t_data		*data;
	char	*relative_path = "./test/Owlet_Monster.xpm";
	void	*test1;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);

	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img_height = 128;
	data->img_width = 128;
	data->win_height = 500;
	data->win_width = 500;
	data->win_title = "Test graphique";

	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (free(data), printf("Erreur mlx\n"), 1);

	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width, data->win_height, data->win_title);
	if (!data->win_ptr)
		return (destroy_data(data), printf("Erreur new window"), (1));

	data->img = malloc(sizeof(t_image));
	if (!data->img)
		return (destroy_data(data), printf("Erreur malloc img"), 1);
	data->img->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, relative_path, &data->img_width, &data->img_height);
	data->img->posx = 5;
	data->img->posy = 5;
	if (!data->img->img_ptr)
		return (destroy_data(data), printf("Erreur chargement image"), 1);
	test1 = mlx_xpm_file_to_image(data->mlx_ptr, relative_path, &data->img_width, &data->img_height);
	if (!test1)
		return (printf("Erreur test1\n"), 0);
	data->img->walks = new_sprite("./test/walks/walk1.xpm");
	if (!data->img->walks)
		return (destroy_data(data), 1);
	load_walks(&data->img->walks);

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, data->img->posx, data->img->posy);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, test1, data->img->posx + 10, data->img->posy + 10);
	mlx_key_hook(data->win_ptr, key_listener, data);
	mlx_loop(data->mlx_ptr);

	destroy_data(data);
	return (0);
}
