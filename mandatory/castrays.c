/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-har <isel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:40:28 by isel-har          #+#    #+#             */
/*   Updated: 2023/06/21 11:48:20 by isel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	vertical_intersection(double rayangle, t_cub *cub)
{
	first_ver_intersect(rayangle, cub);
	if (!is_wall(cub, cub->x_v + 1, cub->y_v)
		&& !is_wall(cub, cub->x_v - 1, cub->y_v))
	{
		while (true)
		{
			next_ver_intersect(rayangle, cub);
			if (is_wall(cub, cub->x_v + 1, cub->y_v)
				|| is_wall(cub, cub->x_v - 1, cub->y_v))
				break ;
		}
	}
}

void	horizontal_intersection(double rayangle, t_cub *cub)
{
	first_horizontal_intersection(rayangle, cub);
	if (!is_wall(cub, cub->x_h, cub->y_h + 1)
		&& !is_wall(cub, cub->x_h, cub->y_h - 1))
	{
		while (true)
		{
			next_horizontal_intersection(rayangle, cub);
			if (is_wall(cub, cub->x_h, cub->y_h + 1)
				|| is_wall(cub, cub->x_h, cub->y_h - 1))
				break ;
		}
	}
}

void	intersections(double rayangle, t_cub *cub)
{
	double	dis_h;
	double	dis_v;

	cub->vert_line = false;
	cub->hori_line = false;
	horizontal_intersection(rayangle, cub);
	vertical_intersection(rayangle, cub);
	dis_h = cal_distance(cub->p_x, cub->p_y, cub->x_h, cub->y_h);
	dis_v = cal_distance(cub->p_x, cub->p_y, cub->x_v, cub->y_v);
	if (dis_h > dis_v)
	{
		cub->vert_line = true;
		cub->next_x = cub->x_v;
		cub->next_y = cub->y_v;
		cub->x_offset = (int)cub->y_v % S_SIZE;
	}
	else
	{
		cub->hori_line = true;
		cub->next_x = cub->x_h;
		cub->next_y = cub->y_h;
		cub->x_offset = (int)cub->x_h % S_SIZE;
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

	rayangle = cub->angle - (FOV_AGL / 2);
	rayangle = set_angle(rayangle);
	i = 0;
	while (i < NUM_RAYS)
	{
		intersections(rayangle, cub);
		rayangle += FOV_AGL / (double)NUM_RAYS;
		rayangle = set_angle(rayangle);
		render_walls(rayangle, cub, i);
		i += 1;
	}
}
