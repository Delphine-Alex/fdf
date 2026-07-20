/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:15:09 by dpaiva            #+#    #+#             */
/*   Updated: 2025/03/25 19:34:34 by dpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	slope_less_than_one(int p, int dx, int dy, t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	x = data->a.x;
	y = data->a.y;
	while (++i < abs(dx))
	{
		ft_pixel(data, x, y, WHITE);
		if (p < 0)
			p += 2 * abs(dy);
		else
		{
			if (dy < 0)
				y--;
			else
				y++;
			p += 2 * (abs(dy) - abs(dx));
		}
		if (dx < 0)
			x += -1;
		else
			x += 1;
	}
}

void	slope_bigger_than_one(int p, int dx, int dy, t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	x = data->a.x;
	y = data->a.y;
	while (++i < abs(dy))
	{
		ft_pixel(data, x, y, WHITE);
		if (p < 0)
			p += 2 * abs(dx);
		else
		{
			if (dx < 0)
				x--;
			else
				x++;
			p += 2 * (abs(dx) - abs(dy));
		}
		if (dy < 0)
			y += -1;
		else
			y += 1;
	}
}

void	ft_draw_line(t_data *data)
{
	int	dx;
	int	dy;

	dx = data->b.x - data->a.x;
	dy = data->b.y - data->a.y;
	ft_pixel(data, data->b.x, data->b.y, WHITE);
	if (abs(dx) > abs(dy))
		slope_less_than_one(2 * abs(dy) - abs(dx), dx, dy, data);
	else
		slope_bigger_than_one(2 * abs(dx) - abs(dy), dx, dy, data);
}
