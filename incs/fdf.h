/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:51:54 by anfichet          #+#    #+#             */
/*   Updated: 2024/03/01 17:50:32 by anfichet         ###   ########.fr       */
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

typedef struct	s_topo
{
	int	x;
	int y;
	int z;
	double px;
	double py;
}	t_topo;

typedef struct	s_line
{
	t_topo	*topo; // tableau de points de chaque ligne
	size_t 	nb_point;
}	t_line;

typedef struct	s_map
{
	t_line	*line; //tableau de lignes
	size_t 	nb_line;
}	t_map;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
	int 		bits_per_pixel;
	int 		line_length;
	int 		endian;
	int 		color[10];
	int 		actual_color;
	double 		zoom;
	double 		z_heigh;
	double 		offset_px;
	double 		offset_py;
	t_map		*map;
}	t_data;

typedef struct	s_bresenham
{
	int	dx;
	int	dy;
	int	yi;
	int xi;
	int	decision;
}	t_bresenham;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_key_hook(int keycode, t_data *data);
int		ft_mouse_close(t_data *data);
void 	bresenham_low(t_topo topo_start, t_topo topo_end, t_data *data);
void	bresenham_high(t_topo topo_start, t_topo topo_end, t_data *data);
void	bresenham_choose_line(t_topo topo_start, t_topo topo_end, t_data *data);
int		key_hook(int keycode, t_data *data);
int		ft_key_zoom_and_color(int keycode, t_data *data);
int		check_argv(char *str);
void	init_struct(t_data *data);
int		ft_mouse_zoom(int button, int x1, int y1, t_data *data);
int		ft_key_diagonal_translation(int keycode, t_data *data);
int		ft_key_translation(int keycode, t_data *data);
int 	draw_image(t_data *data);
int		launch_window(t_data *data, t_map *map, char **argv);
void	launch_event(t_data *data);
void	loop_and_destroy(t_data *data, t_map *map);
int		create_lines(char *s, t_map	*map);
size_t	count_lines(t_map *map, int file, char *str);
int		create_topo_array(char *s, t_map *map);
size_t	ft_array_len(char **array);
int		allocate_line(t_line *line, char *str, t_map *map);
void	free_array(char **array);
void	fill_topo_array(char **split_return, t_line *line, t_map *map);
void	free_map(t_map *map);
void	fill_isometric_point(t_map *map, t_line *line, t_data *data);
void	draw_line(t_line *line, t_map *map, t_data *data);

#endif