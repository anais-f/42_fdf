/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:51:54 by anfichet          #+#    #+#             */
/*   Updated: 2024/02/06 17:51:54 by anfichet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1920
# define HEIGH 1080

# include "libft.h"
# include <mlx.h>
# include <mlx_int.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h> // strerror
# include <math.h>
# include <errno.h>

typedef struct	s_vars {
	void	*mlx_ptr;
	void	*win_ptr;
}				t_vars;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;
	t_vars	*vars;
}	t_data;

typedef struct	s_topo
{
	int x;
	int y;
	int z;
	int px;
	int py;
}	t_topo;

typedef struct	s_line
{
	t_topo	*topo; // tableau de points de chaque ligne
	size_t 	nb_point_per_line;
}	t_line;

typedef struct	s_map
{
	t_line	*line; //tableau de lignes
	int 	nb_line;
}	t_map;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	ft_key_close(int keycode, t_vars *vars);
int	ft_mouse_close(t_vars *vars);
void plot_line_low(int x0, int y0, int x1, int y1, t_data *data);
void plot_line_high(int x0, int y0, int x1, int y1, t_data *data);
void	plot_line(int x0, int y0, int x1, int y1, t_data *data);
int	key_hook(int keycode, t_vars *vars);
int ft_mouse_line(int button, int x1, int y1, t_data *data);

int	count_lines(char *s, t_map	*map);
int	create_array(char *s, t_map *map);
size_t ft_array_len(char **array);
int	allocate_line(t_line *line, char *str);
void	free_array(char **array);
void	fill_array(char **split_return, t_line *line);
void	free_map(t_map *map);

#endif