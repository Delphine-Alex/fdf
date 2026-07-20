/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:35:13 by dpaiva            #+#    #+#             */
/*   Updated: 2025/03/11 19:04:56 by dpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "printf/ft_printf.h"

# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1980

# define WHITE 0xFFFFFF

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;

	int		bits_per_pixel;
	int		size_line;
	int		endian;

	int		**map;
	int		width;
	int		height;

	int		x;
	int		y;

	int		space;

	char	*name;

	t_point	a;
	t_point	b;

}	t_data;

void	ft_isometric(t_point *point);
void	set_point(t_data *data, t_point *point, int x, int y);
void	ft_pixel(t_data *data, int x, int y, int color);

// fdf.c
int		ft_fdf(t_data *data);
void	ft_init_mlx(t_data *data);

// hooks.c
int		close_window(t_data *data);
void	hooks_handler(t_data *data);

// maps.c
void	ft_map_size(t_data *data, char *file);
void	ft_parse_map(t_data *data, char *file);
void	ft_free_int(int **ptr, int height);
void	ft_free(char **ptr);
void	ft_print_map(t_data *data);

// errors.c
void	ft_check_args(int argc, char **argv);
void	ft_map_error(t_data *data, char *file);
void	exit_error(char *message);

// bresemham.c
void	ft_draw_line(t_data *data);
void	slope_less_than_one(int p, int dx, int dy, t_data *data);
void	slope_bigger_than_one(int p, int dx, int dy, t_data *data);

#endif
