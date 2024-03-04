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

/* for dx > dy, octants along the x axis */
void	bresenham_low(t_topo topo_start, t_topo topo_end, t_data *data)
{
	t_bresenham	param;

	param.dx = topo_end.px - topo_start.px;
	param.dy = topo_end.py - topo_start.py;
	param.yi = 1;
	param.decision = (2 * param.dy) - param.dx;
	if (param.dy < 0)
	{
		param.yi = -1;
		param.dy = param.dy * -1;
	}
	while (topo_start.px <= topo_end.px && ((topo_start.px >= 0 && topo_start.px <= WIDTH) || (topo_start.py >= 0 && topo_start.py <= HEIGH)))
	{
		my_mlx_pixel_put(data, topo_start.px, topo_start.py, data->color[data->actual_color]);
		if (param.decision > 0)
		{
			topo_start.py = topo_start.py + param.yi;
			param.decision = param.decision + (2 * (param.dy - param.dx));
		}
		else
			param.decision = param.decision + 2 * param.dy;
		topo_start.px++;
	}
}

/* for dx < dy, octants along the y axis */
void	bresenham_high(t_topo topo_start, t_topo topo_end, t_data *data)
{
	t_bresenham	param;

	param.dx = topo_end.px - topo_start.px;
	param.dy = topo_end.py - topo_start.py;
	param.xi = 1;
	param.decision = (2 * param.dx) - param.dy;
	if (param.dx < 0)
	{
		param.xi = -1;
		param.dx = param.dx * -1;
	}
	while (topo_start.py <= topo_end.py  && ((topo_start.py >= 0 && topo_start.py <= HEIGH) || (topo_start.px >= 0 && topo_start.px <= WIDTH)))
	{
		my_mlx_pixel_put(data, topo_start.px, topo_start.py, data->color[data->actual_color]);
		if (param.decision > 0)
		{
			topo_start.px = topo_start.px + param.xi;
			param.decision = param.decision + (2 * (param.dx - param.dy));
		}
		else
			param.decision = param.decision + 2 * param.dx;
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
