/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:52:02 by anfichet          #+#    #+#             */
/*   Updated: 2024/02/06 17:52:02 by anfichet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int main(void)
{
	void 	*mlx;
	void	*mlx_win;
	t_data	img;
	int x = 15;
	int y = 15;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello Ian!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	while (x < 500 )
	{
		my_mlx_pixel_put(&img, x, y, 0x00267390);
		x++;
	}
	while (y < 500)
	{
		my_mlx_pixel_put(&img, x, y, 0x00267390);
		y++;
	}
	x = 15;
	while (x < 500)
	{
		my_mlx_pixel_put(&img, x, y, 0x00267390);
		x++;
	}
	x = 15;
	while (y > 15)
	{
		my_mlx_pixel_put(&img, x, y, 0x00267390);
		y--;
	}


	mlx_put_image_to_window(mlx, mlx_win, img.img, 15, 15);
	mlx_loop(mlx);

}
