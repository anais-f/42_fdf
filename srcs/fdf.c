/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:52:02 by anfichet          #+#    #+#             */
/*   Updated: 2024/02/15 14:02:27 by anfichet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > WIDTH || y > HEIGH || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));

	*(u_int32_t *)dst = color;
}


int main(int argc, char **argv)
{
	t_vars	vars;
	t_data	data;
	t_point	point;
	int		*file;

	file = get_next_line(0);
	while (file)
	{
		free(file);
		file = get_next_line(0);
	}


	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WIDTH, HEIGH, "Hello Ian!");
	data.vars = &vars;
	data.img = mlx_new_image(vars.mlx_ptr, WIDTH, HEIGH);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);


//
//	point.x0 = 50;
//	point.x1 = 50;
//	point.y0 = 200;
//	point.y1 = 20;
//
//	plot_line(point.x0, point.y0, point.x1, point.y1, &data);

	mlx_mouse_hook(vars.win_ptr, ft_mouse_line, &data);
	//mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, data.img, 0, 0);


	mlx_key_hook(vars.win_ptr, ft_key_close, &vars);

	mlx_hook(vars.win_ptr, 17, 0L, mlx_loop_end, vars.mlx_ptr);



	mlx_loop(vars.mlx_ptr);
	mlx_destroy_image(vars.mlx_ptr, data.img);
	mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
	mlx_destroy_display(vars.mlx_ptr);
	free(vars.mlx_ptr);
}






