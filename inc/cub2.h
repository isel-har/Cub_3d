#ifndef CUB2_H
# define CUB2_H

void	*ft_malloc(int size);
size_t	map_size(int fd);
char	*ft_strjoin2(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	**ft_split2(char const *s);
int		whitespaces(char c);
void	free_2d(char **str);
void	free_3d(char ***s);
void	release_all(t_cub *cub, char f);
int		size_map(char **str);
void    check_elements(char ***map, t_cub *cub);
int		whitespaces(char c);
void    exit_error(t_cub *cub, char step);
void	check_map(char **map, t_cub *cub, int i);
char	*ft_itoa(int n);
int		ft_atoi(char *str);
bool	isnot_dig(char *str);
void	valid_colors(t_cub *cub, char *s, char c);
char	first_elements(char *str);
void	creation(t_cub *cub);
void	put_player(t_cub *cub);
int		ft_move(int keycode, t_cub *cub);
bool	right_side(double rayangle);
int	    player_up(double angle);
int	    is_wall(t_cub *cub, double x, double y);
void	first_horizontal_intersection(double rayangle, t_cub *cub);
void	next_horizontal_intersection(double rayangle, t_cub *cub);
void	first_ver_intersect(double rayangle, t_cub *cub);
void	next_ver_intersect(double rayangle, t_cub *cub);
int	    keys(t_cub *cub);
int		key_up(int keycode, t_cub *cub);
void	init_keys(t_cub *cub);
void	player_newpos(t_cub *cub, int key);
bool	check_sides(t_cub *cub, int xtmp, int ytmp);
void    gun_img(t_cub *cub);

#endif
