/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:36:07 by anfichet          #+#    #+#             */
/*   Updated: 2024/02/28 19:38:51 by anfichet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

size_t	ft_array_len(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_map(t_map *map)
{
	size_t	i;
	size_t	nb_line;

	i = 0;
	nb_line = map->nb_line;
	while (i < nb_line)
	{
		free(map->line[i].topo);
		i++;
	}
	free(map->line);
}

void	init_struct(t_data *data)
{
	data->zoom = 20;
	data->offset_px = 1;
	data->offset_py = 1;
	data->z_heigh = 0.5;
	data->color[0] = 13253734;
	data->color[1] = 14379663;
	data->color[2] = 15248062;
	data->color[3] = 11002080;
	data->color[4] = 4891554;
	data->color[5] = 7391174;
	data->color[6] = 8101330;
	data->color[7] = 12301530;
	data->color[8] = 14341342;
	data->color[9] = 16052451;
	data->actual_color = 0;

}
