/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-har <isel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:33:57 by isel-har          #+#    #+#             */
/*   Updated: 2023/06/22 17:38:05 by isel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/cub.h"

void	gun_sprite(t_cub *cub)
{
	cub->n_of_img = 0;
	cub->gun_key = 0;
	cub->gun_sprite = ft_malloc(sizeof(void *) * 7);
	cub->gun_sprite[0] = mlx_xpm_file_to_image(cub->m_ptr, \
	"textures/1.xpm", &cub->w, &cub->h);
	cub->gun_sprite[1] = mlx_xpm_file_to_image(cub->m_ptr, \
	"textures/2.xpm", &cub->w, &cub->h);
	cub->gun_sprite[2] = mlx_xpm_file_to_image(cub->m_ptr, \
	"textures/3.xpm", &cub->w, &cub->h);
	cub->gun_sprite[3] = mlx_xpm_file_to_image(cub->m_ptr, \
	"textures/4.xpm", &cub->w, &cub->h);
	cub->gun_sprite[4] = mlx_xpm_file_to_image(cub->m_ptr, \
	"textures/5.xpm", &cub->w, &cub->h);
	cub->gun_sprite[5] = mlx_xpm_file_to_image(cub->m_ptr, \
	"textures/6.xpm", &cub->w, &cub->h);
	cub->gun_sprite[6] = mlx_xpm_file_to_image(cub->m_ptr, \
	"textures/7.xpm", &cub->w, &cub->h);
}

int	gun_animation(t_cub *cub)
{
	static int	i;

	if (i >= 0 && i < 1)
		cub->n_of_img = 0;
	else if (i >= 1 && i < 2)
		cub->n_of_img = 1;
	else if (i >= 2 && i < 3)
		cub->n_of_img = 2;
	else if (i >= 3 && i < 4)
		cub->n_of_img = 3;
	else if (i >= 4 && i < 5)
		cub->n_of_img = 4;
	else if (i >= 5 && i < 6)
		cub->n_of_img = 5;
	else if (i >= 6 && i < 7)
		cub->n_of_img = 6;
	else if (i == 7)
	{
		i = 0;
		cub->gun_key = 0;
	}
	draw(cub);
	i++;
	return (0);
}

int	gun_key(int key, int x, int y, t_cub *cub)
{
	(void)x, (void)y;
	if (key == 1)
	{
		cub->gun_key = 1;
	}
	return (0);
}
