/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:53:41 by anfichet          #+#    #+#             */
/*   Updated: 2024/03/05 12:12:39 by anfichet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	fill_isometric_point(t_map *map, t_line *line, t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->nb_line)
	{
		j = 0;
		while (j < line[i].nb_point)
		{
			line[i].topo[j].px = (((sqrt(2.0) / 2) * line[i].topo[j].x \
				* data->zoom) - ((sqrt(2.0) / 2) * line[i].topo[j].y * \
				data->zoom)) + data->offset_px;
			line[i].topo[j].py = ((1 / sqrt(6.0) * line[i].topo[j].x * \
				data->zoom) + (1 / sqrt(6.0) * line[i].topo[j].y * \
				data->zoom) - (sqrt(2.0 / 3.0) * line[i].topo[j].z * \
				data->zoom * data->z_heigh)) + data->offset_py;
			line[i].topo[j].px += WIDTH / 2;
			line[i].topo[j].py += HEIGH / 2;
			j++;
		}
		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > WIDTH || y > HEIGH || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(u_int32_t *)dst = color;
}

void	draw_line(t_line *line, t_map *map, t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->nb_line)
	{
		j = 0;
		while (j < map->line[i].nb_point)
		{
			if (map->line[i].nb_point != 0 && \
				j < map->line[i].nb_point - 1)
			{
				choose_line(line[i].topo[j], \
							line[i].topo[j + 1], data);
			}
			if (map->nb_line != 0 && i < map->nb_line - 1 && \
				map->line[i + 1].nb_point != 0 && map->line[i + 1].nb_point > j)
			{
				choose_line(line[i].topo[j], \
							line[i + 1].topo[j], data);
			}
			j++;
		}
		i++;
	}
}

int	draw_image(t_data *data)
{
	ft_bzero(data->addr, WIDTH * HEIGH * data->bits_per_pixel / 8);
	fill_isometric_point(data->map, data->map->line, data);
	draw_line(data->map->line, data->map, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}
