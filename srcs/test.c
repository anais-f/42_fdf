/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:35:50 by anfichet          #+#    #+#             */
/*   Updated: 2024/02/18 16:35:50 by anfichet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

/*int	ft_mouse_line(int button, int x1, int y1, t_data *data)
{
	int	x;
	int	y;

	x = WIDTH / 2;
	y = HEIGH / 2;
	if (button == 1)
	{
		bresenham_choose_line(x, y, x1, y1, data);
		mlx_put_image_to_window(data->vars->mlx_ptr,data->vars->win_ptr, \
			data->img, 0, 0);
	}
	return (0);
}*/

/*mlx_mouse_hook(vars.win_ptr, ft_mouse_line, &data);*/

void	print_map(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->nb_line)
	{
		j = 0;
		while (j < map->line[i].nb_point_per_line)
		{
			printf("x = %d, y = %d, z = %d, iso px=%f, iso py=%f\n", \
				map->line[i].topo[j].x, map->line[i].topo[j].y, \
				map->line[i].topo[j].z, map->line[i].topo[j].px, \
				map->line[i].topo[j].py);
			j++;
		}
		i++;
	}
}

//void	bresenham_high(t_topo topo_start, t_topo topo_end, t_data *data)
//{
//	//double test = (double)data->actual_color;
//	t_bresenham	param;
//
//	param.dx = topo_end.px - topo_start.px;
//	param.dy = topo_end.py - topo_start.py;
//	param.xi = 1;
//	param.decision = (2 * param.dx) - param.dy;
//	if (param.dx < 0)
//	{
//		param.xi = -1;
//		param.dx = param.dx * -1;
//	}
//	while (topo_start.py <= topo_end.py  && ((topo_start.py >= 0 && topo_start.py <= HEIGH) || (topo_start.px >= 0 && topo_start.px <= WIDTH)))
//	{
////		if (test < 9)
////			test += 0.03;
////		else
////			test = 0;
//		my_mlx_pixel_put(data, topo_start.px, topo_start.py, data->color[test]);
//		if (param.decision > 0)
//		{
//			topo_start.px = topo_start.px + param.xi;
//			param.decision = param.decision + (2 * (param.dx - param.dy));
//		}
//		else
//			param.decision = param.decision + 2 * param.dx;
//		topo_start.py++;
//	}
//}
