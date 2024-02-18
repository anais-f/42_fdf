/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:17:07 by anfichet          #+#    #+#             */
/*   Updated: 2024/02/18 13:17:07 by anfichet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

// pour Dx > Dy
void plot_line_low(int x0, int y0, int x1, int y1, t_data *data)
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

//pour dx < dy
void	plot_line_high(int x0, int y0, int x1, int y1, t_data *data)
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

void	plot_line(int x0, int y0, int x1, int y1, t_data *data)
{
	if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x0 > x1)
		{
			plot_line_low(x1, y1, x0, y0, data);
		}

		else
		{
			plot_line_low(x0, y0, x1, y1, data);
		}

	}
	else
	{
		if (y0 > y1)
		{
			plot_line_high(x1, y1, x0, y0, data);
		}
		else
			plot_line_high(x0, y0, x1, y1, data);
	}
}