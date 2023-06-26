/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-har <isel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:36:02 by isel-har          #+#    #+#             */
/*   Updated: 2023/06/25 15:06:06 by isel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

bool	hit_door(t_cub *cub, char c)
{
	if (c == 'v')
	{
		if (check_wall(cub, cub->next_x + 1, cub->next_y) == 2
			|| check_wall(cub, cub->next_x - 1, cub->next_y) == 2)
			return (true);
	}
	if (c == 'h')
	{
		if (check_wall(cub, cub->next_x, cub->next_y + 1) == 2
			|| check_wall(cub, cub->next_x, cub->next_y - 1) == 2)
			return (true);
	}
	return (false);
}

void	catch_door(t_cub *cub)
{
	if (cub->vert_line == true)
	{
		if (hit_door(cub, 'v'))
		{
			cub->door = true;
			if (cal_distance(cub->p_x, cub->p_y, cub->next_x, cub->next_y) < 6)
			{
				cub->door_x = cub->next_x;
				cub->door_y = cub->next_y;
			}
		}
	}
	if (cub->hori_line == true)
	{
		if (hit_door(cub, 'h'))
		{
			cub->door = true;
			if (cal_distance(cub->p_x, cub->p_y, cub->next_x, cub->next_y) < 6)
			{
				cub->door_x = cub->next_x;
				cub->door_y = cub->next_y;
			}
		}
	}
}

double	set_angle(double angle)
{
	if (angle > 2 * M_PI)
		angle -= (2 * M_PI);
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

void	cast_all_rays(t_cub *cub)
{
	int		i;
	double	rayangle;

	rayangle = cub->angle - (cub->fov / 2);
	rayangle = set_angle(rayangle);
	i = 0;
	while (i < NUM_RAYS)
	{
		intersections(rayangle, cub);
		catch_door(cub);
		if ((int)rayangle == (int)cub->angle && cub->door)
			cub->d_p_dist = cal_distance(cub->p_x, cub->p_y, \
			cub->next_x, cub->next_y);
		rayangle += cub->fov / (double)NUM_RAYS;
		rayangle = set_angle(rayangle);
		render_walls(rayangle, cub, i);
		i += 1;
	}
}
