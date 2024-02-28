/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:52:02 by anfichet          #+#    #+#             */
/*   Updated: 2024/02/27 22:50:10 by anfichet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"



int main(int argc, char **argv)
{
	t_vars	vars;
	t_data	data;
	int 	nb_point = 0;
	char 	*str;
	t_topo	**topo_array;

	int i;
	int j = 0;
	int nb_line;

	//INIT MES STRCUTURES DE POINT A ZERO



	nb_line = count_lines(argv[1], &topo_array);
	create_array(argv[1], topo_array, &nb_point);

	printf("nb de ligne = %d et nb de point = %d\n", nb_line, nb_point);

	i = 0;
	while (i < nb_line )
	{
		j = 0;
		while (j < nb_point)
		{
			printf("x = %d, y = %d, z = %d\n", topo_array[i][j].x0, topo_array[i][j].y0, topo_array[i][j].z);
			j++;
		}
		i++;
	}








	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WIDTH, HEIGH, "Hello Ian!");
	data.vars = &vars;
	data.img = mlx_new_image(vars.mlx_ptr, WIDTH, HEIGH);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);




	mlx_mouse_hook(vars.win_ptr, ft_mouse_line, &data);
	//mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, data.img, 0, 0);
	mlx_key_hook(vars.win_ptr, ft_key_close, &vars);
	mlx_hook(vars.win_ptr, 17, 0L, mlx_loop_end, vars.mlx_ptr);


	mlx_loop(vars.mlx_ptr);
	mlx_destroy_image(vars.mlx_ptr, data.img);
	mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
	mlx_destroy_display(vars.mlx_ptr);
	free(vars.mlx_ptr);
}






