/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-har <isel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:49:47 by isel-har          #+#    #+#             */
/*   Updated: 2023/06/23 11:50:54 by isel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	put_player(t_cub *cub)
{
	cub->p_x *= S_SIZE;
	cub->p_y *= S_SIZE;
	cub->p_x += S_SIZE / 2;
	cub->p_y += S_SIZE / 2;
	cub->door_index = 0;
	cub->door_row = 0;
	cub->p_minix = cub->p_x * SCALE_SIZE;
	cub->p_miniy = cub->p_y * SCALE_SIZE;
	set_textures(cub);
	cast_all_rays(cub);
	zoomed_map(cub, 0, -1);
	put_cursos(cub);
}

int	ft_close(void)
{
	exit(0);
	return (0);
}

int	key_up(int keycode, t_cub *cub)
{
	if (keycode == MOVE_FORWARD)
		cub->move_forward = 0;
	if (keycode == MOVE_BACKWARD)
		cub->move_backward = 0;
	if (keycode == MOVE_LEFT)
		cub->move_left = 0;
	if (keycode == MOVE_RIGHT)
		cub->move_right = 0;
	if (keycode == RIGHT_ROTATION)
		cub->rotation_right = 0;
	if (keycode == LEFT_ROTATION)
		cub->rotation_left = 0;
	return (0);
}

int	keys(t_cub *cub)
{
	if (cub->move_forward == 1)
		move_player(cub, MOVE_FORWARD);
	if (cub->move_backward == 1)
		move_player(cub, MOVE_BACKWARD);
	if (cub->move_right == 1)
		move_player(cub, MOVE_RIGHT);
	if (cub->move_left == 1)
		move_player(cub, MOVE_LEFT);
	if (cub->rotation_right == 1)
		increment_angle(cub, RIGHT_ROTATION);
	if (cub->rotation_left == 1)
		increment_angle(cub, LEFT_ROTATION);
	if (cub->gun_key == 1)
		gun_animation(cub);
	draw(cub);
	return (0);
}

void	creation(t_cub *cub)
{
	init_values(cub);
	init_keys(cub);
	cub->w_ptr = mlx_new_window(cub->m_ptr, WIN_WIDTH, WIN_HEIGTH, "cub3d");
	cub->data->img = mlx_new_image(cub->m_ptr, WIN_WIDTH, WIN_HEIGTH);
	cub->data->addr = mlx_get_data_addr(cub->data->img, \
	&cub->data->bits_per_pixel, \
	&cub->data->line_length, &cub->data->endian);
	put_surfaces(cub);
	put_player(cub);
	mlx_hook(cub->w_ptr, 2, 0, ft_move, cub);
	mlx_hook(cub->w_ptr, 3, 0, key_up, cub);
	mlx_hook(cub->w_ptr, 6, 0, &mouse, cub);
	mlx_hook(cub->w_ptr, 17, 0, ft_close, cub);
	mlx_mouse_hook(cub->w_ptr, gun_key, cub);
	mlx_loop_hook(cub->m_ptr, keys, cub);
	mlx_put_image_to_window(cub->m_ptr, cub->w_ptr, cub->data->img, 0, 0);
	mlx_put_image_to_window(cub->m_ptr, cub->w_ptr, cub->gun_sprite[0], \
	(WIN_WIDTH / 2) - (166 / 2), WIN_HEIGTH - 122);
	mlx_loop(cub->m_ptr);
}
