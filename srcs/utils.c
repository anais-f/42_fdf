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
}
