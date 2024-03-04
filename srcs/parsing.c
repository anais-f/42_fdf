/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:35:50 by anfichet          #+#    #+#             */
/*   Updated: 2024/03/01 14:13:16 by anfichet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	create_lines(char *s, t_map *map)
{
	int		file;
	char	*str;

	map->nb_line = 0;
	file = open(s, O_RDONLY);
	if (file == -1)
		return (-1);
	str = get_next_line(file);
	count_lines(map, file, str);
	if (errno != 0)
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

size_t	count_lines(t_map *map, int file, char *str)
{
	//int i = 0;
	while (str)
	{
		free(str);
		str = get_next_line(file);
//		if (str == NULL)
//			return (-1);
		map->nb_line++;
//		if (ft_strlen_protect(str) > 1) // me fait des leaks
//			map->nb_line++;
//		if (str[0] == '\n')
//			map->nb_line--;

	}
	return (map->nb_line);
}

int	create_topo_array(char *s, t_map *map)
{
	int		file;
	char	*str;
	size_t	i;
	t_line	*line;

	i = 0;
	file = open(s, O_RDONLY);
	if (file == -1)
		return (-1);
	str = get_next_line(file);
	while (str)
	{
		line = &map->line[i];
		if (allocate_line(line, str, map) == -1)
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

int	allocate_line(t_line *line, char *str, t_map *map)
{
	char	**split_return;
//	int i = 0;

	split_return = ft_split_whitespace(str);
	if (split_return == NULL)
		return (-1);
	line->nb_point_per_line = ft_array_len(split_return);
	find_biggest_line(map, line);
//	while (&line[i])
//	{
//		if (line->nb_point_per_line < map->nb_point_biggest_line)
//		{
//			printf("map invalide");
//			return (-1);
//		}
//		i++;
//	}
	line->topo = ft_calloc(line->nb_point_per_line, sizeof(t_topo));
	if (line->topo == NULL)
	{
		free_array(split_return);
		return (-1);
	}
	fill_topo_array(split_return, line, map);
	free_array(split_return);
	return (0);
}

void	fill_topo_array(char **split_return, t_line *line, t_map *map)
{
	size_t		i;
	static int	y = 0;
	(void)map;

	i = 0;
	while (i < line->nb_point_per_line)
	{
		if (split_return[i])
		{
			line->topo[i].x = (int)i /*- ((int)line->nb_point_per_line / 2)*/;
			line->topo[i].y = (int)y/*- ((int)map->nb_line / 2)*/;
			line->topo[i].z = ft_atoi(split_return[i]);
		}
		i++;
	}
	y++;
}

void	find_biggest_line(t_map *map, t_line *line)
{
	size_t i;
	size_t j;

	i = 0;
	map->nb_point_biggest_line = line->nb_point_per_line;
	while (i < map->nb_line)
	{
		j = 0;
		while (j < line[i].nb_point_per_line)
		{
			j++;
		}
		if (line[i].nb_point_per_line > line[i - 1].nb_point_per_line)
			map->nb_point_biggest_line = line[i].nb_point_per_line;
		i++;
	}
}
