/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_maps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-har <isel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:45:29 by isel-har          #+#    #+#             */
/*   Updated: 2023/06/22 16:47:00 by isel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	put_square(t_cub *cub, int x, int y, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < S_SIZE * SCALE_SIZE)
	{
		i = 0;
		while (i < S_SIZE * SCALE_SIZE)
		{
			my_mlx_pixel_put(cub, x + i, y + j, color);
			i += 1;
		}
		j += 1;
	}
}

void	draw_mini_map(t_cub *cub, int y)
{
	int	x;
	int	cofx;
	int	cofy;

	while (cub->map_2d[y])
	{
		x = 0;
		cofy = (y * S_SIZE) * SCALE_SIZE;
		cofx = 0;
		x = 0;
		while (cub->map_2d[y][x])
		{
			if (x > 0)
				cofx = (x * S_SIZE) * SCALE_SIZE;
			if (cub->map_2d[y][x] == '1')
				put_square(cub, cofx, cofy, 0x4A4F50);
			else if (cub->map_2d[y][x] == 'D')
				put_square(cub, cofx, cofy, 0xFEDF32);
			else
				put_square(cub, cofx, cofy, 0x669A9E);
			x += 1;
		}
		y += 1;
	}
}

void	inc_x(t_cub *cub, double y, double *x)
{
	if (cub->calc_x < 0 || cub->calc_y < 0 || cub->calc_x >= cub->x_map
		|| cub->calc_y >= cub->y_map)
		my_mlx_pixel_put(cub, *x, y, 0x808080);
	else if (cub->map_2d[cub->calc_y][cub->calc_x] == '1')
		my_mlx_pixel_put(cub, *x, y, 0x4A4F50);
	else if (cub->map_2d[cub->calc_y][cub->calc_x] == 'D')
		my_mlx_pixel_put(cub, *x, y, 0xFEDF32);
	else
		my_mlx_pixel_put(cub, *x, y, 0x2cb3d8);
	*x += 1;
}

void	zoomed_map(t_cub *cub, double x, double y)
{
	double	start_x;
	double	start_y;

	start_y = cub->p_y - 200;
	start_x = cub->p_x - 200;
	while (y < 300)
	{
		x = 0;
		while (x < 250)
		{
			cub->calc_x = (start_x + x) / 32;
			cub->calc_y = (start_y + y) / 32;
			inc_x(cub, y, &x);
		}
		y += 1;
	}
	mini_player(cub, 200, 200, 10);
}
