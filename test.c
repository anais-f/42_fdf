//#include "fdf.h"

//
//int main(int argc, char **argv)
//{
//	t_vars	vars;
//	t_data	data;
//	int		file;
//	int 	nb_line = 1;
//	int 	nb_point = 0;
//	char 	*str;
//	int 	i = 0;
//	int 	j = 0;
//	t_topo	**topo_line_array;
//	//t_topo	**topo_global_array;
//
//	file = open(argv[1], O_RDONLY);
//	str = get_next_line(file);
//	while (str)
//	{
//		while ((str[i] >= '0' && str[i] <= '9') && (str[i + 1] == ' ' || str[i + 1] == '\n' || str[i + 1] == '\0'))
//		{
//			nb_point++;
//			i++;
//		}
//		topo_line_array[j] = malloc(sizeof(t_topo) * nb_point);
//		if (topo_line_array[j] == NULL)
//		{
//			perror("Error during allocation memory");
//			return (-1);
//		}
//		free(str);
//		str = get_next_line(file);
//		nb_line++;
//
//	}
//	topo_line_array = malloc(nb_line * sizeof(t_topo *));
//	if (topo_line_array == NULL)
//	{
//		perror("Error during allocation memory");
//		return (-1);
//	}
//	close(file);






//void	create_array(char *s, t_topo **map, int *nb_point)
//{
//	int file;
//	int i;
//	int j;
//	char *str;
//
//	file = open(s, O_RDONLY);
//	str = get_next_line(file);
//	while (str)
//	{
//		nb_point = 0;
//		i = 0;
//		while (str[i])
//		{
//			if ((str[i] >= '0' && str[i] <= '9') && (str[i + 1] == ' ' || str[i + 1] == '\n' || str[i + 1] == '\0'))
//				(*nb_point)++;
//			i++;
//		}
//		map[j] = malloc(sizeof(t_topo) * nb_point);
//		if (map[j] == NULL)
//		{
//			perror("Error during allocation memory");
//			return ;
//		}
//		k = 0;
//
//		int l;
//		while (k != nb_point)
//		{
//			i = 0;
//			l = 0;
//			while (str[i] && str[i] != '\n')
//			{
//				map[j][l].z = ft_atoi(str + i);
//				l++;
//				printf("atoi = %d\n", ft_atoi(str + i));
//				while (str[i] && str[i] != ' ')
//					i++;
//				if (str[i])
//					i++;
//			}
//			map[j][k].y0 = j;
//			map[j][k].x0 = k;
//			k++;
//			printf("k = %d\n", k);
//		}
//		j++;
//
//		free(str);
//		str = get_next_line(file);
//	}
//	close(file);
//}