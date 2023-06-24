/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-har <isel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:39:11 by isel-har          #+#    #+#             */
/*   Updated: 2023/06/24 12:43:45 by isel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/cub.h"

void	mouse_rotate(t_cub *cub)
{
	if (cub->rot_to_right)
	{
		if (cub->angle >= 355 * (M_PI / 180))
		{
			cub->angle = 0;
			return ;
		}
		cub->angle = cub->angle * (180 / M_PI);
		cub->angle += 5;
		cub->angle = cub->angle * (M_PI / 180);
	}
	else if (cub->rot_to_left)
	{
		if (cub->angle <= 0)
		{
			cub->angle = 355 * (M_PI / 180);
			return ;
		}
		cub->angle = cub->angle * (180 / M_PI);
		cub->angle -= 5;
		cub->angle = cub->angle * (M_PI / 180);
	}
	draw(cub);
}

int	mouse(int x, int y, t_cub *cub)
{
	(void)y;
	mlx_mouse_hide();
	cub->rot_to_right = 0;
	cub->rot_to_left = 0;
	if (x == WIN_WIDTH / 2)
		return (0);
	if (x > WIN_WIDTH / 2)
	{
		cub->rot_to_right = 1;
		mlx_mouse_move(cub->w_ptr, WIN_WIDTH / 2, WIN_HEIGTH / 2);
	}
	else if (x < WIN_WIDTH / 2)
	{
		cub->rot_to_left = 1;
		mlx_mouse_move(cub->w_ptr, WIN_WIDTH / 2, WIN_HEIGTH / 2);
	}
	mouse_rotate(cub);
	cub->rot_to_right = 0;
	cub->rot_to_left = 0;
	return (0);
}
