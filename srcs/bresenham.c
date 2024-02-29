/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:17:07 by anfichet          #+#    #+#             */
/*   Updated: 2024/02/28 19:38:41 by anfichet         ###   ########.fr       */
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

/* for dx > dy, octants along the x axis */
void	bresenham_low(t_topo topo_start, t_topo topo_end, t_data *data)
{
	int dx = topo_end.px - topo_start.px;
	int	dy = topo_end.py - topo_start.py;
	int	yi = 1;
	int	D = (2 * dy) - dx;

	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	while (topo_start.px <= topo_end.px)
	{
		my_mlx_pixel_put(data, topo_start.px, topo_start.py, 0x002ecc71);
		if (D > 0)
		{
			topo_start.py = topo_start.py + yi;
			D = D + (2 * (dy - dx));
		}
		else
			D = D + 2 * dy;
		topo_start.px++;
	}
}

/* for dx < dy, octants along the y axis */
void	bresenham_high(t_topo topo_start, t_topo topo_end, t_data *data)
{
	int dx = topo_end.px - topo_start.px;
	int dy = topo_end.py - topo_start.py;
	int xi = 1;
	int D = (2 * dx) - dy;

	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	while (topo_start.py <= topo_end.py)
	{
		my_mlx_pixel_put(data, topo_start.px, topo_start.py, 0x002ecc71);
		if (D > 0)
		{
			topo_start.px = topo_start.px + xi;
			D = D + (2 * (dx - dy));
		}
		else
			D = D + 2 * dx;
		topo_start.py++;
	}
}

void	bresenham_choose_line(t_topo topo_start, t_topo topo_end, t_data *data)
{
	if (fabs(topo_end.py - topo_start.py) < fabs(topo_end.px - topo_start.px))
	{
		if (topo_start.px > topo_end.px)
			bresenham_low(topo_end, topo_start, data);
		else
			bresenham_low(topo_start, topo_end, data);
	}
	else
	{
		if (topo_start.py > topo_end.py)
			bresenham_high(topo_end, topo_start, data);
		else
			bresenham_high(topo_start, topo_end, data);
	}
}


void	fill_isometric_point(t_map *map, t_line *line)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->nb_line)
	{
		j = 0;
		while (j < line[i].nb_point_per_line)
		{
			line[i].topo[j].px = ((sqrt(2.0) / 2) * line[i].topo[j].x)
					- ((sqrt(2.0) / 2) * line[i].topo[j].y);
			line[i].topo[j].py = (1 / sqrt(6.0) * line[i].topo[j].x)
					+ (1 / sqrt(6.0) * line[i].topo[j].y)
					- (sqrt(2.0 / 3.0) * line[i].topo[j].z);
			line[i].topo[j].px += (double)WIDTH / 2;
			line[i].topo[j].py += (double)HEIGH / 2;
			j++;
		}
		i++;
	}
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
			bresenham_choose_line(line[i].topo[j], line[i + 1].topo[j], data);
			i++;
		}
		j++;
	}
}

