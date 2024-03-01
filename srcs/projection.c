/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:53:41 by anfichet          #+#    #+#             */
/*   Updated: 2024/02/29 18:31:53 by anfichet         ###   ########.fr       */
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
		while (j < line[i].nb_point_per_line)
		{
			line[i].topo[j].px = ((sqrt(2.0) / 2) * (double)line[i].topo[j].x * data->zoom) \
				- ((sqrt(2.0) / 2) * (double)line[i].topo[j].y * data->zoom);
			line[i].topo[j].py = (1 / sqrt(6.0) * (double)line[i].topo[j].x * data->zoom) \
				+ (1 / sqrt(6.0) * (double)line[i].topo[j].y * data->zoom) \
				- (sqrt(2.0 / 3.0) * (double)line[i].topo[j].z * (data->zoom / 2));
			line[i].topo[j].px += (double)WIDTH / 2;
			line[i].topo[j].py += (double)HEIGH / 2;
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

void	draw_x_line(t_line *line, t_map *map, t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < map->nb_line)
	{
		j = 0;
		while (j < (map->line[i].nb_point_per_line - 1))
		{
			bresenham_choose_line(line[i].topo[j], line[i].topo[j + 1], data);
			j++;
		}
		i++;
	}
}

// refaire si ligne non entiere
//

void	draw_y_line(t_line *line, t_map *map, t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < (map->line[i].nb_point_per_line))
	{
		i = 0;
		while (i < map->nb_line - 1)
		{
			if (!line[i].topo[j])
			{

			}
			bresenham_choose_line(line[i].topo[j], line[i + 1].topo[j], data);
			i++;
		}
		j++;
	}
}
