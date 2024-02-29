/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:52:02 by anfichet          #+#    #+#             */
/*   Updated: 2024/02/27 22:50:10 by anfichet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int main(int argc, char **argv)
{
	t_vars	vars;
	t_data	data;
	t_map	map;
	(void) argc;

	// VERIFIER L'ENTREE DE ARGV 1 POUR LA CARTE
	if (create_lines(argv[1], &map) == -1)
	{
		perror("Error during parsing");
		return (-1);
	}
	if (create_topo_array(argv[1], &map) == -1)
	{
		perror("Error during parsing");
		return (-1);
	}

	fill_isometric_point(&map, map.line);

	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WIDTH, HEIGH, "Hello Ian!");
	data.vars = &vars;
	data.img = mlx_new_image(vars.mlx_ptr, WIDTH, HEIGH);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	draw_x_line(map.line, &map, &data);
	draw_y_line(map.line, &map, &data);

//	print_map(&map);
	//mlx_mouse_hook(vars.win_ptr, ft_mouse_line, &data);
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, data.img, 0, 0);
	mlx_key_hook(vars.win_ptr, ft_key_close, &vars);
	mlx_hook(vars.win_ptr, 17, 0L, mlx_loop_end, vars.mlx_ptr);

	mlx_loop(vars.mlx_ptr);
	mlx_destroy_image(vars.mlx_ptr, data.img);
	mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
	mlx_destroy_display(vars.mlx_ptr);
	free_map(&map);
	free(vars.mlx_ptr);
}





