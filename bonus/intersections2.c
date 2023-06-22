/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-har <isel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:15:44 by isel-har          #+#    #+#             */
/*   Updated: 2023/06/22 17:16:33 by isel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/cub.h"

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

void	intersections(double rayangle, t_cub *cub)
{
	double	dis_h;
	double	dis_v;

	cub->vert_line = false;
	cub->hori_line = false;
	cub->door = false;
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
