/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-har <isel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:12:29 by isel-har          #+#    #+#             */
/*   Updated: 2023/06/21 12:12:31 by isel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	first_horizontal_intersection(double rayangle, t_cub *cub)
{
	if (player_up(rayangle))
		cub->y_h = floor(cub->p_y / S_SIZE) * S_SIZE;
	else
		cub->y_h = floor(cub->p_y / S_SIZE) * S_SIZE + S_SIZE;
	cub->x_h = (cub->y_h - cub->p_y) / tan(rayangle) + cub->p_x;
}

void	next_horizontal_intersection(double rayangle, t_cub *cub)
{
	if (player_up(rayangle))
	{
		cub->y_h -= S_SIZE;
		cub->x_h += (-S_SIZE / tan(rayangle));
	}
	else
	{
		cub->y_h += S_SIZE;
		cub->x_h += (S_SIZE / tan(rayangle));
	}
}

void	first_ver_intersect(double rayangle, t_cub *cub)
{
	double	y1;
	double	xdiff;

	if (right_side(rayangle))
		cub->x_v = (floor(cub->p_x / S_SIZE) + 1) * S_SIZE;
	else
		cub->x_v = floor(cub->p_x / S_SIZE) * S_SIZE;
	xdiff = cub->x_v - cub->p_x;
	y1 = xdiff * tan(rayangle);
	cub->y_v = cub->p_y + y1;
}

void	next_ver_intersect(double rayangle, t_cub *cub)
{
	if (right_side(rayangle))
	{
		cub->x_v += S_SIZE;
		cub->y_v += (S_SIZE * tan(rayangle));
	}
	else
	{
		cub->x_v -= S_SIZE;
		cub->y_v += (-S_SIZE * tan(rayangle));
	}
}
