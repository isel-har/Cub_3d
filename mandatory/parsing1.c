/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-har <isel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:07:18 by isel-har          #+#    #+#             */
/*   Updated: 2023/06/26 14:40:00 by isel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

char	*get_map(int fd, int i)
{
	char	*r_map;
	char	*line;

	r_map = ft_malloc(1);
	*r_map = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (i > 6 && line[0] == '\n')
		{
			free(line);
			exit_error(0, 0);
		}
		if (line[0] != '\n')
		{
			i += 1;
			r_map = ft_strjoin2(r_map, line);
		}
		else
			free(line);
	}
	return (r_map);
}

/*int	check_sp(char **s, int i, int j)
{
	if (s[i][j] == ' ')
	{
		if (i && (int)ft_strlen(s[i - 1]) > j
			&& s[i - 1][j] != ' ' && s[i - 1][j] != '1')
			return (-1);
		if (s[i][j + 1] && s[i][j + 1] != ' '
			&& s[i][j + 1] != '1')
			return (-1);
		if (s[i + 1] && (int)ft_strlen(s[i + 1]) > j
			&& s[i + 1][j] != ' ' && s[i + 1][j] != '1')
			return (-1);
		if (j && s[i][j - 1] != ' ' && s[i][j - 1] != '1')
			return (-1);
	}
	return (0);
}

int	til_space(char **s, int i, int j)
{
	while (s[i][j])
	{
		if (s[i][j] == ' ')
			break ;
		j += 1;
	}
	return (j);
}

int	til_rev_space(char **s, int i, int j)
{
	while (j < 0)
	{
		if (s[i][j] == ' ')
			break ;
		j -= 1;
	}
	return (j);
}

void	check_walls2(char **s, t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j++] == ' ');
		//j = til_space(s, i, j);
		if (s[i][j - 1] != '1')
			exit_error(cub, 3);
		j = 0;
		while (s[i][j])
		{
			if (i == 0 && s[i][j] != ' ' && s[i][j] != '1')
				exit_error(cub, 3);
			if (check_sp(s, i, j) == -1)
				exit_error(cub, 3);
			if (!s[i + 1] && s[i][j] != ' ' && s[i][j] != '1')
				exit_error(cub, 3);
			j++;
		}
		//j = til_rev_space(s, i,)
		while (s[i][--j] == ' ');
		if (s[i][j] != '1')
			exit_error(cub, 3);
		i++;
	}
}*/

int check_sp(char **s,int i ,int j)
{
	if( s[i][j] == ' ')
	{
		if (i && (int)ft_strlen(s[i - 1]) > j
			&& s[i - 1][j] != ' ' && s[i - 1][j] != '1')
			return (-1);
		if (s[i][j + 1] && s[i][j + 1] != ' '
			&& s[i][j + 1] != '1')
			return (-1);
		if (s[i + 1] && (int)ft_strlen(s[i + 1]) > j
			&&  s[i + 1][j] != ' ' && s[i + 1][j] != '1')
			return (-1);
		if (j  && s[i][j - 1] != ' ' && s[i][j - 1] != '1')
			return (-1);

	}
	return (0);
}

void	check_walls2(char **s, t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while(s[i][j++] == ' ');
		if (s[i][j - 1] != '1')
				exit_error(cub, 3);
		j = 0;
		while (s[i][j])
		{
			if(i == 0 && s[i][j] != ' ' && s[i][j] != '1')
				exit_error(cub, 3);
			if(check_sp(s, i , j) == -1)
				exit_error(cub, 3);
			if(!s[i + 1]  && s[i][j] != ' ' && s[i][j] != '1')
				exit_error(cub, 3);
			j++;
		}
		while(s[i][--j] == ' ');
		if (s[i][j] != '1')
				exit_error(cub, 3);
		i++;
	}
}

void	check_prev(char **map, t_cub *cub)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == '0')
			{
				if (j > 0 && i + 1 > (int)ft_strlen(map[j - 1]))
					exit_error(cub, 3);
			}
			i++;
		}
		j++;
	}
}
