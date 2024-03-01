/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:05:29 by anfichet          #+#    #+#             */
/*   Updated: 2024/03/01 17:52:10 by anfichet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape || keycode == XK_space)
		mlx_loop_end(data->mlx_ptr);
	printf("keycode = %d\n", keycode);
	ft_key_zoom(keycode, data);
	return (0);
}

int	ft_key_zoom(int keycode, t_data *data)
{
	ft_bzero(data->addr, WIDTH*HEIGH*data->bits_per_pixel / 8);
	if (keycode == 65451)
	{
		data->zoom *= 1.1;
		fill_isometric_point(data->map, data->map->line, data);
		draw_x_line(data->map->line, data->map, data);
		draw_y_line(data->map->line, data->map, data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	}
	if (keycode == 65453)
	{
		data->zoom *= 0.9;
		fill_isometric_point(data->map, data->map->line, data);
		draw_x_line(data->map->line, data->map, data);
		draw_y_line(data->map->line, data->map, data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	}
	return (0);
}

int	ft_mouse_zoom(int button, int x1, int y1, t_data *data)
{
	(void) x1;
	(void) y1;

	ft_bzero(data->addr, WIDTH*HEIGH*data->bits_per_pixel / 8);
	if (button == 4)
	{
		data->zoom *= 1.1;
		fill_isometric_point(data->map, data->map->line, data);
		draw_x_line(data->map->line, data->map, data);
		draw_y_line(data->map->line, data->map, data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	}
	if (button == 5)
	{
		data->zoom *= 0.9;
		fill_isometric_point(data->map, data->map->line, data);
		draw_x_line(data->map->line, data->map, data);
		draw_y_line(data->map->line, data->map, data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	}
	return (0);
}
