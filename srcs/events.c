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
