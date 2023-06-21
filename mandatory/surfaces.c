/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surfaces.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-har <isel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:08:43 by isel-har          #+#    #+#             */
/*   Updated: 2023/06/21 12:09:25 by isel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	put_sky(t_cub *cub)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	color = create_trgb(cub->rgb_c->r, cub->rgb_c->g, cub->rgb_c->b);
	while (y < (WIN_HEIGTH / 2))
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(cub, x, y, color);
			x += 1;
		}
		y += 1;
	}
	return (y);
}

void	put_surfaces(t_cub *cub)
{
	int	x;
	int	color;
	int	y;

	y = put_sky(cub);
	color = create_trgb(cub->rgb_f->r, cub->rgb_f->g, cub->rgb_f->b);
	while (y < WIN_HEIGTH)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(cub, x, y, color);
			x += 1;
		}
		y += 1;
	}
}

void	horiz_cursor(t_cub *cub)
{
	int	i;
	int	j;
	int	ep;

	j = WIN_HEIGTH / 2;
	ep = 0;
	while (ep < 3)
	{
		i = (WIN_WIDTH / 2) - 15;
		while (i < (WIN_WIDTH / 2) + 15)
		{
			my_mlx_pixel_put(cub, i, j + ep, 0xFEDF32);
			i += 1;
		}
		ep += 1;
	}
}

void	put_cursos(t_cub *cub)
{
	int	i;
	int	j;
	int	ep;

	horiz_cursor(cub);
	j = (WIN_HEIGTH / 2) - 15;
	i = WIN_WIDTH / 2;
	while (j < (WIN_HEIGTH / 2) + 15)
	{
		ep = 0;
		while (ep < 3)
		{
			my_mlx_pixel_put(cub, i + ep, j, 0xFEDF32);
			ep += 1;
		}
		j += 1;
	}
}
