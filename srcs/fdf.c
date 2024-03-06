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

int	main(int argc, char **argv)
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
		check_argv(argv[1]);
		if (create_lines(argv[1], &map) == -1 || \
			create_topo_array(argv[1], &map) == -1)
		{
			perror("Error during parsing");
			return (-1);
		}
		if (launch_window(&data, &map, argv) == -1)
		{
			free_map(&map);
			return (-1);
		}
		loop_and_destroy(&data, &map);
	}
	return (0);
}

int	launch_window(t_data *data, t_map *map, char **argv)
{
	ft_bzero(data, sizeof(t_data));
	init_struct(data);
	data->map = map;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (-1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGH, argv[1]);
	if (data->win_ptr == NULL)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		return (-1);
	}
	data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGH);
	if (data->img == NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		return (-1);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
			&data->line_length, &data->endian);
	launch_event(data);
	return (0);
}

void	launch_event(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, draw_image, data);
	mlx_mouse_hook(data->win_ptr, ft_mouse_zoom, data);
	mlx_hook(data->win_ptr, 02, 1L << 0, ft_key_hook, data);
	mlx_hook(data->win_ptr, 17, 0L, mlx_loop_end, data->mlx_ptr);
}

void	loop_and_destroy(t_data *data, t_map *map)
{
	mlx_loop(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_map(map);
	free(data->mlx_ptr);
}
