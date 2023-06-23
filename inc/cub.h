/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-har <isel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:55:49 by isel-har          #+#    #+#             */
/*   Updated: 2023/06/23 12:34:20 by isel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include "get_next_line.h"
# include "objects.h"
# include "cub2.h"

void	still_open(t_cub *cub);
void	movement(int keycode, t_cub *cub);
void	beside_wall(t_cub *cub, int keycode);
void	my_mlx_pixel_put(t_cub *c, int x, int y, int color);
void	init_values(t_cub *cub);
int		ft_move(int keycode, t_cub *cub);
void	draw_mini_map(t_cub *cub, int y);
int		check_wall(t_cub *cub, int x, int y);
void	intersections(double rayangle, t_cub *cub);
void	cast_all_rays(t_cub *cub);
void	DDA(t_cub *cub);
void	render_walls(double rayangle, t_cub *cub, int i);
double	cal_distance(double x1, double y1, double x2, double y2);
void	put_surfaces(t_cub *cub);
double	set_angle(double angle);
t_tx	*new_texture(t_cub *cub, char *file);
void	set_textures(t_cub *cub);
void	player_minimap(t_cub *cub, int x, int y);
void	put_square(t_cub *cub, int x, int y, int color);
void	put_cursos(t_cub *cub);
void	check_walls2(char **s, t_cub *cub);
void	zoomed_map(t_cub *cub, double x, double y);
void	mini_player(t_cub *cub, int x, int y, int size);
int		create_trgb(int r, int g, int b);
void	draw(t_cub *cub);
void	move_player(t_cub *cub, int keycode);
void	increment_angle(t_cub *cub, int keycode);
char	*ft_strdup(char *s);
int		ft_strcmp(char *s1, char *s2);
char	*get_map(int fd, int i);
void	catch_door(t_cub *cub);

#endif
