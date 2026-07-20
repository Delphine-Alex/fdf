/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:44:56 by dpaiva            #+#    #+#             */
/*   Updated: 2025/03/25 19:45:50 by dpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_check_args(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		ft_printf("\nInvalid number of params. Too much or too few arguments!\n");
		ft_printf("Make sure you enter arguments: ./fdf maps/map_name.fdf\n\n");
		exit(EXIT_FAILURE);
	}
}

void	exit_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

// void	ft_map_error(t_data *data, char *file)
// {
// 	char	**map;
// 	char	*line;
// 	int		fd;
// 	int		x;

// 	fd = open(file, O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		map = ft_split(line, ' ');
// 		x = 0;
// 		while (map[x] != NULL)
// 		x++;
// 		if (x != data->width)
// 		{
// 			mlx_destroy_image(data->mlx, data->img);
// 			mlx_destroy_window(data->mlx, data->win);
// 			mlx_destroy_display(data->mlx);
// 			free(data->mlx);
// 			exit_error("Wrong map format: Resource temporarily unavailable");
// 			// close_window(data);
// 		}
// 		ft_free(map);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	free(line);
// 	close(fd);
// }
