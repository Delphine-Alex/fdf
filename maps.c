/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:02:04 by dpaiva            #+#    #+#             */
/*   Updated: 2025/03/15 19:02:06 by dpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_map_size(t_data *data, char *file)
{
	char	**map;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit_error("Map empty: Resource temporarily unavailable");
	}
	line = get_next_line(fd);
	if (line == NULL)
	{

		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit_error("Error: No such file or directory");
	}
	data->height = 0;
	data->width = 0;
	map = ft_split(line, ' ');
	while (map[data->width] != NULL)
		data->width++;
	ft_free(map);
	while (line != NULL)
	{
		data->height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	ft_map_error(t_data *data, char *file)
{
	char	**map;
	char	*line;
	int		fd;
	int		x;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map = ft_split(line, ' ');
		x = 0;
		while (map[x] != NULL)
		x++;
		if (x != data->width)
		{
			free(line);
			mlx_destroy_image(data->mlx, data->img);
			mlx_destroy_window(data->mlx, data->win);
			mlx_destroy_display(data->mlx);
			free(data->mlx);
			ft_free(map);
			exit_error("Wrong map format: Resource temporarily unavailable");
		}
		ft_free(map);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	ft_parse_map(t_data *data, char *file)
{
	char	**map;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	data->map = malloc(sizeof(int *) * (data->height));
	if (!data->map)
		exit_error("Memory allocation failed");
	data->y = -1;
	while (++data->y < data->height)
	{
		data->map[data->y] = malloc(sizeof(int) * (data->width));
		if (!data->map[data->y])
			exit_error("Memory allocation failed");
		line = get_next_line(fd);
		map = ft_split(line, ' ');
		free(line);
		data->x = -1;
		while (++data->x < data->width)
		data->map[data->y][data->x] = ft_atoi(map[data->x]);
		ft_free(map);
	}
	close(fd);
}

void	ft_print_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			set_point(data, &data->a, x, y);
			if (x + 1 < data->width)
			{
				set_point(data, &data->b, x + 1, y);
				ft_draw_line(data);
			}
			if (y + 1 < data->height)
			{
				set_point(data, &data->b, x, y + 1);
				ft_draw_line(data);
			}
			x++;
		}
		y++;
	}
}

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	ft_free_int(int **ptr, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (ptr[i] != NULL)
			free(ptr[i]);
		i++;
	}
	free(ptr);
}
