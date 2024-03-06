/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:35:50 by anfichet          #+#    #+#             */
/*   Updated: 2024/03/05 19:32:54 by anfichet         ###   ########.fr       */
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
	while (str)
	{
		free(str);
		str = get_next_line(file);
		map->nb_line++;
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
	char	**split_return;

	split_return = ft_split_whitespace(str);
	if (split_return == NULL)
		return (-1);
	line->nb_point = ft_array_len(split_return);
	line->topo = ft_calloc(line->nb_point, sizeof(t_topo));
	if (line->topo == NULL)
	{
		free_array(split_return);
		return (-1);
	}
	fill_topo_array(split_return, line);
	free_array(split_return);
	return (0);
}

void	fill_topo_array(char **split_return, t_line *line)
{
	size_t		i;
	static int	y = 0;

	i = 0;
	while (i < line->nb_point)
	{
		if (split_return[i])
		{
			line->topo[i].x = (int)i;
			line->topo[i].y = (int)y;
			line->topo[i].z = ft_atoi(split_return[i]);
		}
		i++;
	}
	y++;
}
