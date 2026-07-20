/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:17:05 by dpaiva            #+#    #+#             */
/*   Updated: 2025/03/25 19:38:05 by dpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	ft_free_int(data->map, data->height);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

int	key_handler(int key, t_data *data)
{
	if (key == 65307)
		close_window(data);
	return (0);
}

void	hooks_handler(t_data *data)
{
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_key_hook(data->win, key_handler, data);
}
