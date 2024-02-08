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

#include "libft.h"
#include <mlx.h>
#include <mlx_int.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h> // strerror
#include <math.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;
}	t_data;



#endif