/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:05:29 by anfichet          #+#    #+#             */
/*   Updated: 2024/02/15 15:05:29 by anfichet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	ft_key_close(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape || keycode == XK_space)
		mlx_loop_end(vars->mlx_ptr);
	printf("keycode = %d\n", keycode);
	if (keycode == XK_KP_Insert)
		printf("Hello from key_hook!\n");
	return (0);
}


int ft_mouse_line(int button, int x1, int y1, t_data *data)
{
	int x0 = WIDTH / 2;
	int y0 = HEIGH / 2;
	if (button == 1)
	{
//		printf("x1 = %d et y1 = %d\n", x1, y1);
//		printf("x0 = %d et y0 = %d\n", x0, y0);
		bresenham_choose_line(x0, y0, x1, y1, data);
		mlx_put_image_to_window(data->vars->mlx_ptr, data->vars->win_ptr, data->img, 0, 0);
	}
	return (0);
}

