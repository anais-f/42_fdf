/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:52:02 by anfichet          #+#    #+#             */
/*   Updated: 2024/03/01 17:53:38 by anfichet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	if (argc != 2)
	{
		ft_printf("Invalid parameter\n");
		return (-1);
	}
	else
	{
		check_map(argv[1]);
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
		ft_bzero(&data, sizeof(t_data));
		init_struct(&data);
		data.map = &map;
		data.mlx_ptr = mlx_init();
		data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGH, "Fdf");
		data.img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGH);
		data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
		fill_isometric_point(&map, map.line, &data);
		draw_x_line(map.line, &map, &data);
		draw_y_line(map.line, &map, &data);

		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 0);

		mlx_mouse_hook(data.win_ptr, ft_mouse_zoom, &data);
		mlx_key_hook(data.win_ptr, ft_key_hook, &data);
		mlx_hook(data.win_ptr, 17, 0L, mlx_loop_end, data.mlx_ptr);
	}

	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free_map(&map);
	free(data.mlx_ptr);
	return (0);
}



int	check_map(char *str)
{
	int i;
	const char str_check[] = ".fdf";

	i = 0;
	if (ft_strlen(str) <= 5)
	{
		ft_printf("Invalid parameter\n");
		exit (1);
	}
	while (str[i] != '.')
		i++;
	if (ft_strncmp(str_check, &str[i], 5) != 0)
	{
		ft_printf("Invalid file\n");
		exit (1);
	}
	return (0);
}
