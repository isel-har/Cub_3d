/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sides.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-har <isel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:56:39 by isel-har          #+#    #+#             */
/*   Updated: 2023/06/22 17:31:37 by isel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

double	cal_distance(double x1, double y1, double x2, double y2)
{
	double	deltax;
	double	deltay;

	deltax = fabs(x2 - x1);
	deltay = fabs(y2 - y1);
	return (sqrt(deltax * deltax + deltay * deltay));
}

bool	right_side(double rayangle)
{
	if ((rayangle > 3 * (M_PI / 2) && rayangle <= 2 * M_PI)
		|| (fabs(rayangle) >= 0 && rayangle < M_PI / 2))
		return (true);
	return (false);
}

int	is_wall(t_cub *cub, double x, double y)
{
	int	x2;
	int	y2;

	x2 = (int)floor(x / S_SIZE);
	y2 = (int)floor(y / S_SIZE);
	if (x2 < 0 || x2 > (cub->win_width / S_SIZE) - 1
		|| y2 < 0 || y2 > (cub->win_height / S_SIZE) - 1)
		return (-1);
	if (cub->map_2d[y2][x2] == '1')
		return (1);
	if (cub->map_2d[y2][x2] == 'D')
		return (2);
	return (0);
}

int	check_wall(t_cub *cub, int x, int y)
{
	int	fpx;
	int	fpy;

	fpx = (int)floor(x) / S_SIZE;
	fpy = (int)floor(y) / S_SIZE;
	if (fpx < 0 || fpx > cub->win_width
		|| fpy < 0 || fpy > cub->win_height)
		return (1);
	if (cub->map_2d[fpy][fpx] == '1')
		return (1);
	if (cub->map_2d[fpy][fpx] == 'D')
		return (2);
	if (cub->map_2d[fpy][fpx] == 'x')
		return (3);
	return (0);
}

int	player_up(double angle)
{
	if ((angle * (180 / M_PI)) > (double)180
		&& (angle * (180 / M_PI)) < (double)360)
		return (1);
	return (0);
}
