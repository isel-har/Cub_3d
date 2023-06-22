/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-har <isel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:20:16 by isel-har          #+#    #+#             */
/*   Updated: 2023/06/22 17:34:18 by isel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	init_keys(t_cub *cub)
{
	cub->move_backward = 0;
	cub->move_forward = 0;
	cub->move_right = 0;
	cub->move_left = 0;
	cub->rotation_right = 0;
	cub->rotation_left = 0;
	cub->gun_key = 0;
}

void	get_angle(t_cub *cub)
{
	if (cub->p_or == NORTH)
		cub->angle = 270 * (M_PI / 180);
	if (cub->p_or == SOUTH)
		cub->angle = 90 * (M_PI / 180);
	if (cub->p_or == EAST)
		cub->angle = 0;
	if (cub->p_or == WEST)
		cub->angle = 180 * (M_PI / 180);
}

void	init_values(t_cub *cub)
{
	int	tmp;

	cub->y_map = 0;
	cub->x_map = 0;
	cub->door_index = 0;
	cub->door_row = 0;
	cub->all_map = 0;
	cub->data = ft_malloc(sizeof(t_data));
	while (cub->map_2d[cub->y_map])
	{
		cub->x_map = 0;
		tmp = 0;
		while (cub->map_2d[cub->y_map][cub->x_map])
			cub->x_map += 1;
		if (cub->x_map > tmp)
			tmp = cub->x_map;
		cub->y_map += 1;
	}
	cub->x_map = tmp;
	cub->win_width = cub->x_map * S_SIZE;
	cub->win_height = cub->y_map * S_SIZE;
	get_angle(cub);
	cub->m_ptr = mlx_init();
	gun_sprite(cub);
}
