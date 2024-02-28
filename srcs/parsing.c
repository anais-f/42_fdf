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

int	count_lines(char *s, t_map	*map)
{
	int file;
	char *str;

	// verifier que le fichier s'appelle bien .fdf !!!

	map->nb_line = 0;
	file = open(s, O_RDONLY);
	if (file == -1)
		return (-1);
	str = get_next_line(file);
	while (str)
	{
		free(str);
		str = get_next_line(file);
		map->nb_line++;
	}
	if (errno != 0) //pour verifier si gnl me revoit pas null a cause d'un malloc qui pete
	{
		close(file);
		return (-1);
	}
	map->line = ft_calloc(map->nb_line, sizeof(t_line));
	if (map->line == NULL)
	{
		close(file);
		return (-1);
	}
	close(file);
	return (0);
}


//2eme appel GNL malloc nb de x et remplir la structure
int	create_array(char *s, t_map *map)
{
	int file;
	char *str;
	int i = 0;
	t_line	*line;

	file = open(s, O_RDONLY);
	if (file == -1)
		return (-1);
	str = get_next_line(file);
	while (str)
	{
		line = &map->line[i];
		if (allocate_line(line, str) == -1)
		{
			return (-1);
		}
		i++;
		free(str);
		str = get_next_line(file);
	}
	close(file);
	return (0);
}

int	allocate_line(t_line *line, char *str)
{
	char **split_return;

	split_return = ft_split(str, ' ');
	if (split_return == NULL)
		return (-1);
	line->nb_point_per_line = ft_array_len(split_return);
	//printf("line->nb_point_per_line = %d\n", line->nb_point_per_line);
	line->topo = ft_calloc(line->nb_point_per_line, sizeof(t_topo));
	//printf("line topo = \n", line->topo->x);
	if (line->topo == NULL)
	{
		free_array(split_return);
		return (-1);
	}
	fill_array(split_return, line);
	free_array(split_return);
	return (0);
}


void	fill_array(char **split_return, t_line *line)
{
	int i;
	static	int y = 0;

	i = 0;
	while (i < line->nb_point_per_line)
	{
		line->topo[i].x = i;
		line->topo[i].y = y;
		line->topo[i].z = ft_atoi(split_return[i]);
		// a voir si securisation atoi avec errno
		i++;
	}
	y++;
}
