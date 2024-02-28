/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:17:07 by anfichet          #+#    #+#             */
/*   Updated: 2024/02/27 21:57:12 by anfichet         ###   ########.fr       */
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
void bresenham_low(int x0, int y0, int x1, int y1, t_data *data)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int yi = 1;
	int D = (2 * dy) - dx;

	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	while (x0 <= x1)
	{
		my_mlx_pixel_put(data, x0, y0, 0x002ecc71);
		if (D > 0)
		{
			y0 = y0 + yi;
			D = D + (2 * (dy - dx));
		}
		else
			D = D + 2 * dy;
		x0++;
	}
}

/* for dx < dy, octants along the y axis */
void	bresenham_high(int x0, int y0, int x1, int y1, t_data *data)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int xi = 1;
	int D = (2 * dx) - dy;

	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	while (y0 <= y1)
	{
		my_mlx_pixel_put(data, x0, y0, 0x002ecc71);
		if (D > 0)
		{
			x0 = x0 + xi;
			D = D + (2 * (dx - dy));
		}
		else
			D = D + 2 * dx;
		y0++;
	}
}

void	bresenham_choose_line(int x0, int y0, int x1, int y1, t_data *data)
{
	if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x0 > x1)
			bresenham_low(x1, y1, x0, y0, data);
		else
			bresenham_low(x0, y0, x1, y1, data);
	}
	else
	{
		if (y0 > y1)
			bresenham_high(x1, y1, x0, y0, data);
		else
			bresenham_high(x0, y0, x1, y1, data);
	}
}

/*
void	projection(t_topo *topo)
{
	topo->px = (sqrt(2) / 2 * x0 ) - (sqrt(2) / 2 * y0 );
	topo->py = (sqrt(2/3) * z) - (1 / sqrt(6) * x0) - (1 / sqrt(6) * y0);
}
*/

