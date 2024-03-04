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
	else
	{
		ft_key_zoom_and_color(keycode, data);
		ft_key_diagonal_translation(keycode, data);
		ft_key_translation(keycode, data);
	}
	//printf("keycpode = %d\n", keycode);
	return (0);
}

int	draw_image(t_data *data)
{
	fill_isometric_point(data->map, data->map->line, data);
	draw_x_line(data->map->line, data->map, data);
	draw_y_line(data->map->line, data->map, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}

int	ft_key_zoom_and_color(int keycode, t_data *data)
{
	ft_bzero(data->addr, WIDTH*HEIGH*data->bits_per_pixel / 8);
	if (keycode == XK_KP_Add)
		data->zoom *= 1.1;
	if (keycode == XK_KP_Subtract)
		data->zoom *= 0.9;
	if (keycode == XK_KP_Divide)
		data->z_heigh *= 0.9;
	if (keycode == XK_KP_Multiply)
		data->z_heigh *= 1.1;

	if (keycode == XK_c)
	{
	//	printf("actual color = %d\n", data->actual_color);
		if (data->actual_color < 9)
			data->actual_color++;
		else
			data->actual_color = 0;
	}
	return (0);
}

int	ft_key_translation(int keycode, t_data *data)
{
	if (keycode == XK_Up || keycode == 65431) //8
		data->offset_py -= 10;
	if (keycode == XK_Down || keycode == 65433) //2
		data->offset_py += 10;
	if (keycode == XK_Right || keycode == 65432) //6
		data->offset_px += 10;
	if (keycode == XK_Left || keycode == 65430) //4
		data->offset_px -= 10;
	return (0);
}

int	ft_key_diagonal_translation(int keycode, t_data *data)
{
	if (keycode == 65435) //3
	{
		data->offset_px += 10;
		data->offset_py += 10;
	}
	if (keycode == 65436) //1
	{
		data->offset_px -= 10;
		data->offset_py += 10;
	}
	if (keycode == 65434) //9
	{
		data->offset_px += 10;
		data->offset_py -= 10;
	}
	if (keycode == 65429) //7
	{
		data->offset_px -= 10;
		data->offset_py -= 10;
	}
	return (0);
}

int	ft_mouse_zoom(int button, int x1, int y1, t_data *data)
{
	(void) x1;
	(void) y1;

	ft_bzero(data->addr, WIDTH*HEIGH*data->bits_per_pixel / 8);
	if (button == 4)
		data->zoom *= 1.1;
	if (button == 5)
		data->zoom *= 0.9;
	return (0);
}
