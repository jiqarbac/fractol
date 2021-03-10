/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:57:03 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/03/10 11:57:05 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				set(t_mlx *mlx, t_point *point, int x, int y)
{
	point->x = (mlx->xmax - mlx->xmin) * x / H + mlx->xmin;
	point->y = (mlx->ymax - mlx->ymin) * y / W + mlx->ymin;
}

void				dt(t_mlx *mlx, int x, int y, int color)
{
	mlx->dtadd[x + y * (int)H] = color;
}

int					clr(int iter)
{
	double			per;
	int				color;
	unsigned char	*ptr;

	per = iter / 100.0;
	ptr = (unsigned char *)&color;
	ptr[3] = 0;
	ptr[0] = 255 * (1.0 - per) * powf(per, 3) * 9;
	ptr[1] = 255 * powf(1.0 - per, 2) * powf(per, 2) * 15;
	ptr[2] = 255 * powf(1.0 - per, 3) * per * 8.5;
	return (color);
}

int					ft_exit(void *param, int key)
{
	t_mlx			*mlx;

	mlx = (t_mlx *)param;
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	key == 36 ? main(2, mlx->str) : exit(0);
	return (0);
}

void				changefract(t_mlx *mlx)
{
	if (mlx->str[1][0] == '1')
		mlx->str[1][0] = '2';
	else if (mlx->str[1][0] == '2')
		mlx->str[1][0] = '3';
	else if (mlx->str[1][0] == '3')
		mlx->str[1][0] = '4';
	else if (mlx->str[1][0] == '4')
		mlx->str[1][0] = '1';
}
