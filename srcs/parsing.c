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

int	count_lines(char *s, t_topo ***map)
{
	int nb_line;
	int	file;
	char *str;

	nb_line = 0;
	file = open(s, O_RDONLY);
	str = get_next_line(file);
	while (str)
	{
		free(str);
		str = get_next_line(file);
		nb_line++;
	}
	*map = malloc(nb_line * sizeof(t_topo *));
	if (*map == NULL)
	{
		perror("Error during allocation memory");
		return (-1);
	}
	close(file);
	return (nb_line);
}

//2eme appel GNL malloc nb de x et remplir la structure
void	create_array(char *s, t_topo **map, int *nb_point)
{
	int file;
	int i;
	int j;
	char *str;

	j = 0;
	file = open(s, O_RDONLY);
	str = get_next_line(file);
	while (str)
	{
		*nb_point = 0;
		i = 0;
		while (str[i])
		{
			if ((str[i] >= '0' && str[i] <= '9') && (str[i + 1] == ' ' || str[i + 1] == '\n' || str[i + 1] == '\0'))
				(*nb_point)++;
			//printf("nb_point = %d\n", *nb_point);
			i++;
		}
		map[j] = malloc(sizeof(t_topo) * *nb_point);
		//exit (0);
		if (map[j] == NULL)
		{
			perror("Error during allocation memory");
			return ;
		}
		fill_array(str, map, j, nb_point);
		j++;
		free(str);
		str = get_next_line(file);
	}
	close(file);
}

void	fill_array(char *str, t_topo **map, int j, int *ptr_nb_point)
{
	int 	i;
	int 	k;
	int		l;
	int		nb_point;

	nb_point = *ptr_nb_point;
	k = 0;
	while (k != nb_point)
	{
		i = 0;
		l = 0;
		while (str[i] && str[i] != '\n')
		{
			map[j][l].z = ft_atoi(str + i);
			l++;
			printf("atoi = %d\n", ft_atoi(str + i));
			while (str[i] && str[i] != ' ')
				i++;
			if (str[i])
				i++;
		}
		map[j][k].y0 = j;
		map[j][k].x0 = k;
		k++;
		printf("k = %d\n", k);
	}
}


//void	check_map(char *str)
//{
//	int i;
//
//	i = 0;
//	while (str[i])
//
//}