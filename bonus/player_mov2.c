/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-har <isel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:46:14 by isel-har          #+#    #+#             */
/*   Updated: 2023/06/23 11:46:16 by isel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	still_open(t_cub *cub)
{
	int	i;
	int	j;

	j = 0;
	while (cub->map_2d[j])
	{
		i = 0;
		while (cub->map_2d[j][i])
		{
			if (j != cub->door_row && i != cub->door_index
				&& cub->map_2d[j][i] == 'x')
				cub->map_2d[j][i] = 'D';
			i += 1;
		}
		j += 1;
	}
}

void	mini_player(t_cub *cub, int x, int y, int size)
{
	int	i;
	int	j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			my_mlx_pixel_put(cub, x + i, y + j, 0xff00000);
			i += 1;
		}
		j += 1;
	}
}

void	right_left(t_cub *cub, int key)
{
	if (key == MOVE_LEFT)
	{
		cub->p_x += 3 * sin(cub->angle);
		cub->p_y -= 3 * cos(cub->angle);
		cub->p_minix = cub->p_x * SCALE_SIZE;
		cub->p_miniy = cub->p_y * SCALE_SIZE;
	}
	if (key == MOVE_RIGHT)
	{
		cub->p_x -= 3 * sin(cub->angle);
		cub->p_y += 3 * cos(cub->angle);
		cub->p_minix = cub->p_x * SCALE_SIZE;
		cub->p_miniy = cub->p_y * SCALE_SIZE;
	}
}

void	player_newpos(t_cub *cub, int key)
{
	if (key == MOVE_FORWARD)
	{
		cub->p_x += 3 * cos(cub->angle);
		cub->p_y += 3 * sin(cub->angle);
		cub->p_minix = cub->p_x * SCALE_SIZE;
		cub->p_miniy = cub->p_y * SCALE_SIZE;
	}
	if (key == MOVE_BACKWARD)
	{
		cub->p_x -= 3 * cos(cub->angle);
		cub->p_y -= 3 * sin(cub->angle);
		cub->p_minix = cub->p_x * SCALE_SIZE;
		cub->p_miniy = cub->p_y * SCALE_SIZE;
	}
	right_left(cub, key);
}

bool	check_sides(t_cub *cub, int xtmp, int ytmp)
{
	double	right_angle;
	double	left_angle;

	right_angle = set_angle(cub->angle - M_PI / 2);
	intersections(right_angle, cub);
	if (cal_distance(cub->p_x, cub->p_y, cub->next_x, cub->next_y) < 2)
	{
		cub->p_x = xtmp;
		cub->p_y = ytmp;
		return (true);
	}
	left_angle = set_angle(cub->angle + M_PI / 2);
	intersections(left_angle, cub);
	if (cal_distance(cub->p_x, cub->p_y, cub->next_x, cub->next_y) < 2)
	{
		cub->p_x = xtmp;
		cub->p_y = ytmp;
		return (true);
	}
	return (false);
}
