/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:47:45 by dpaiva            #+#    #+#             */
/*   Updated: 2025/03/25 20:07:29 by dpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(t_point *point)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = point->x;
	tmp_y = point->y;
	point->x = (tmp_x - tmp_y) * cos(0.523599);
	point->y = (tmp_x + tmp_y) * sin(0.523599) - point->z;
}

void	set_point(t_data *data, t_point *point, int x, int y)
{
	int		offset_x;
	int		offset_y;
	double	isow;
	double	isoh;

	data->space = 20;
	isow = (data->width - 1) / 2.0;
	isoh = (data->height -1) / 2.0;
	offset_x = (x - isow) * data->space;
	offset_y = (y - isoh) * data->space;
	point->x = offset_x;
	point->y = offset_y;
	point->z = data->map[y][x];
	ft_isometric(point);
	point->x += WINDOW_WIDTH / 2;
	point->y += WINDOW_HEIGHT / 2;
}

void	ft_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = data->addr + (y * data->size_line)
			+ (x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
