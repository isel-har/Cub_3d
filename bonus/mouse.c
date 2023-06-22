#include"../inc/cub.h"

void    mouse_rotate(t_cub *cub)
{
    if (cub->ROT_TO_RIGHT)
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
    else if (cub->ROT_TO_LEFT)
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

int    mouse(int x, int y, t_cub *cub)
{
	mlx_mouse_hide();
    (void)y;
	cub->ROT_TO_RIGHT = 0;
    cub->ROT_TO_LEFT = 0;
	if (x == WIN_WIDTH / 2)
		return (0);
    if (x > WIN_WIDTH / 2)
    {
		cub->ROT_TO_RIGHT = 1;
		mlx_mouse_move(cub->w_ptr, WIN_WIDTH / 2, WIN_HEIGTH / 2);
    }
    else if (x < WIN_WIDTH / 2)
    {
		cub->ROT_TO_LEFT = 1;
		mlx_mouse_move(cub->w_ptr, WIN_WIDTH / 2, WIN_HEIGTH / 2);
    }
    mouse_rotate(cub);
    cub->ROT_TO_RIGHT = 0;
    cub->ROT_TO_LEFT = 0;
    return (0);
}
