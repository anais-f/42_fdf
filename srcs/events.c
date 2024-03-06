/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:05:29 by anfichet          #+#    #+#             */
/*   Updated: 2024/03/05 12:04:56 by anfichet         ###   ########.fr       */
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
	return (0);
}

int	ft_key_zoom_and_color(int keycode, t_data *data)
{
	if (keycode == XK_KP_Add)
		data->zoom *= 1.1;
	if (keycode == XK_KP_Subtract)
		data->zoom *= 0.9;
	if (keycode == XK_KP_Divide)
		data->z_heigh -= 0.05;
	if (keycode == XK_KP_Multiply)
		data->z_heigh += 0.05;
	if (keycode == XK_c)
	{
		if (data->actual_color < 9)
			data->actual_color++;
		else
			data->actual_color = 0;
	}
	return (0);
}

int	ft_key_translation(int keycode, t_data *data)
{
	if (keycode == XK_Down || keycode == TWO)
		data->offset_py += 10;
	if (keycode == XK_Left || keycode == FOUR)
		data->offset_px -= 10;
	if (keycode == XK_Right || keycode == SIX)
		data->offset_px += 10;
	if (keycode == XK_Up || keycode == HEIGHT)
		data->offset_py -= 10;
	return (0);
}

int	ft_key_diagonal_translation(int keycode, t_data *data)
{
	if (keycode == ONE)
	{
		data->offset_px -= 10;
		data->offset_py += 10;
	}
	if (keycode == THREE)
	{
		data->offset_px += 10;
		data->offset_py += 10;
	}
	if (keycode == SEVEN)
	{
		data->offset_px -= 10;
		data->offset_py -= 10;
	}
	if (keycode == NINE)
	{
		data->offset_px += 10;
		data->offset_py -= 10;
	}
	return (0);
}

int	ft_mouse_zoom(int button, int x1, int y1, t_data *data)
{
	(void) x1;
	(void) y1;
	if (button == 4)
		data->zoom *= 1.1;
	if (button == 5)
		data->zoom *= 0.9;
	return (0);
}
