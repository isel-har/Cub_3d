/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-har <isel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:14:36 by isel-har          #+#    #+#             */
/*   Updated: 2023/06/25 17:56:22 by isel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

t_tx	*depends_side(double rayangle, t_cub *cub)
{
	t_tx	*tx;

	tx = NULL;
	if (cub->hori_line == true)
	{
		if (rayangle > M_PI && rayangle < 2 * M_PI)
			tx = cub->south_txt;
		else
			tx = cub->north_txt;
	}
	else if (cub->vert_line == true)
	{
		if (rayangle > (M_PI / 2) && rayangle < (M_PI * 3) / 2)
			tx = cub->west_txt;
		else
			tx = cub->east_txt;
	}
	return (tx);
}

unsigned int	get_color_in_texture(t_cub *cub, int y2, double w_h, t_tx *tx)
{
	int				x;
	int				y;
	unsigned int	color;

	y = y2 + (w_h / 2) - (WIN_HEIGTH / 2);
	x = (cub->x_offset / 32) * tx->width;
	y = y * (tx->height / w_h);
	color = tx->data[abs((y * tx->height) + x)];
	return (color);
}

void	put_rect(double rayangle, int x, t_cub *cub, double plan_height)
{
	int				top_pixel;
	int				bottom_pixel;
	unsigned int	color;
	t_tx			*tx;

	top_pixel = (WIN_HEIGTH / 2) - ((int)plan_height / 2);
	if (top_pixel < 0)
		top_pixel = 0;
	bottom_pixel = (WIN_HEIGTH / 2) + ((int)plan_height / 2);
	if (bottom_pixel > WIN_HEIGTH)
		bottom_pixel = WIN_HEIGTH;
	tx = depends_side(rayangle, cub);
	while (top_pixel < bottom_pixel)
	{
		color = get_color_in_texture(cub, top_pixel, plan_height, tx);
		my_mlx_pixel_put(cub, x, top_pixel, color);
		top_pixel++;
	}
}

void	render_walls(double rayangle, t_cub *cub, int i)
{
	double	raydistance;
	double	screen_wall;
	double	newang;

	newang = cub->angle - rayangle;
	newang = set_angle(newang);
	raydistance = cal_distance(cub->p_x, cub->p_y, cub->next_x, cub->next_y) \
	* cos(newang);
	if (round(raydistance) == 0)
		raydistance = 1;
	screen_wall = WIN_HEIGTH * S_SIZE / raydistance;
	put_rect(rayangle, i, cub, screen_wall);
}
