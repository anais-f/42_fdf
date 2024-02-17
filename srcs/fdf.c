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

	printf("valeur x = %d\n", x);
	printf("valeur y = %d\n", y);
//	printf("line_length = %d\n", data->line_length);
//	printf("bits = %d\n", data->bits_per_pixel);

	if (x > WIDTH || y > HEIGH || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int main(void)
{
	t_vars	vars;
	t_data	data;
	t_point	point;


	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WIDTH, HEIGH, "Hello Ian!");
	data.img = mlx_new_image(vars.mlx_ptr, WIDTH, HEIGH);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	printf("line_length = %d\n", data.line_length);
	printf("bits = %d\n", data.bits_per_pixel);


	point.x0 = 10;
	point.x1 = 50;
	point.y0 = 10;
	point.y1 = 100;

	plot_line(point.x0, point.y0, point.x1, point.y1, &data);
//	exit (0);

	//clean l'image aussi a faire
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, data.img, 0, 0);
	mlx_key_hook(vars.win_ptr, ft_key_close, &vars);
	//mlx_mouse_hook(vars.win_ptr, ft_mousedown, &vars);
//	mlx_hook(vars.win_ptr, 2, 1L<<0, ft_key_close, &vars); pour close
	mlx_hook(vars.win_ptr, 17, 0L, mlx_loop_end, vars.mlx_ptr);
	mlx_loop(vars.mlx_ptr);
	//mlx_destroy_display(vars.mlx_ptr);
	//free(vars.mlx_ptr);
}

// pour Dx > Dy
int plot_line_low(int x0, int y0, int x1, int y1, t_data *data)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int yi = 1;
	int D = (2 * dy) - dx;
	int y = y0;
	int x = x0;

	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	while (x <= x1)
	{
		my_mlx_pixel_put(&data->img, x, y, 0x002ecc71);
		if (D > 0)
		{
			y = y + yi;
			D = D + (2 * (dy - dx));
		}
		else
			D = D + 2 * dy;
		x++;
	}
}

//pour dx < dy
int	plot_line_high(int x0, int y0, int x1, int y1, t_data *data)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int xi = 1;
	int D = (2 * dx) - dy;
	int	x = x0;
	int y = y0;

	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}

	while (y <= y1)
	{
		my_mlx_pixel_put(&data->img, x, y, 0x002ecc71);
		if (D > 0)
		{
			x = x + xi;
			D = D + (2 * (dx - dy));
		}
		else
			D = D + 2 * dx;
		y++;
	}
}

void	plot_line(int x0, int y0, int x1, int y1, t_data *data)
{
	if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x0 > x1)
			plot_line_low(x1, y1, x0, y0, data);
		else
			plot_line_low(x0, y0, x1, y1, data);
	}
	else
	{
		if (y0 > y1)
			plot_line_high(x1, y1, x0, y0, data);
		else
			plot_line_high(x0, y0, x1, y1, data);
	}
}



//WKIPEDIA
//point.x1 = 50;
//point.x2 = 800;
//point.y1 = 0;
//point.y2 = 50;
//int dx = point.x2 - point.x1;
//int dy = point.y2 - point.y1;
//int yi = 1;
//
////CAS 1
//if (dy < 0)
//{
//yi = -1;
//dy = -dy;
//}
//int D = (2 * dy) - dx;
//int y = point.y1;
//
//for (point.x1; point.x1 <= point.x2; point.x1++)
//{
//my_mlx_pixel_put(&img, point.x1, point.y1, 0x002ecc71);
//if (D > 0)
//{
//y = y + yi;
//D = D + (2 * (dy - dx));
//}
//else
//D = D + 2 * dy;
//}
//
////---------------------------------------------
////CAS 2
//int xi = 1;
//if (dx < 0)
//{
//xi = -1;
//dx = -dx;
//}
//D = (2 * dx) - dy;
//int x = point.x1;
//
//for (point.y1; point.y1 <= point.y2; point.y1++)
//{
//my_mlx_pixel_put(&img, point.x1, point.y1, 0x002ecc71);
//if (D > 0)
//{
//x = x + xi;
//D = D + (2 * (dx - dy));
//}
//else
//D = D + 2 * dx;
//}
//
//// CHOIX DECISION
//if (abs(point.y2 - point.y1) < abs(point.x2 - point.x1))
//{
//if (point.x1 > point.x2)
//my_mlx_pixel_put(&img, point.x1, point.y1, 0x002ecc71); // A REVOIR
//else
//my_mlx_pixel_put(&img, point.x1, point.y1, 0x002ecc71); // A REVOIR
//}
//else
//{
//if (point.y1 > point.y2)
//my_mlx_pixel_put(&img, point.x1, point.y1, 0x002ecc71); // A REVOIR
//else
//my_mlx_pixel_put(&img, point.x1, point.y1, 0x002ecc71); // A REVOIR
//}


// YOUTUBE
//	int x1 = 10;
//	int x2 = 200;
//	int y1 = 10;
//	int y2 = 150;
//	int ex = abs(x2-x1);
//	int ey = abs(y2-y1);
//	int dx = 2*ex;
//	int dy = 2*ey;
//	int Dx = ex;
//	int Dy = ey;
//	int i = 0;
//	int Xincr = 1;
//	int Yincr = 1;
//	if (x1 > x2)
//		Xincr = -1;
//	if (y1 > y2)
//		Yincr = -1;
//
//	if (Dx > Dy)
//	{
//		while (i <= Dx)
//		{
//			my_mlx_pixel_put(&img, x1, y1, 0x002ecc71);
//			i++;
//			x1 += Xincr;
//			ex -= dy;
//			if (ex < 0)
//			{
//				y1 += Yincr;
//				ex += dx;
//			}
//		}
//	}
//	if (Dx < Dy)
//	{
//		while (i <= Dy)
//		{
//			my_mlx_pixel_put(&img, x1, y1, 0x002ecc71);
//			i++;
//			y1 += Yincr;
//			ey -= dx;
//			if (ey < 0)
//			{
//				x1 += Xincr;
//				ey += dy;
//			}
//		}
//	}
