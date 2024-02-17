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

int	ft_key_close(int keycode, t_vars *vars, t_data *data)
{
	if (keycode == XK_Escape || keycode == XK_space)
	{
		mlx_loop_end(vars->mlx_ptr);
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	}
	return (0);
}

int	ft_mouse_close(t_vars *vars)
{
	mlx_loop_end(vars->mlx_ptr);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	return (0);
}

//int ft_mousedown(int button, int 600, int 600, t_vars *vars)
//{
//	if (button == 1)
//	{
//		mlx_loop_end(vars->mlx_ptr);
//		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
//	}
//}