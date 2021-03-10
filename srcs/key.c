/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:56:42 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/03/10 11:56:46 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mousemove(int mx, int my, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (!mlx->ps && mlx->str[1][0] == '1')
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		set(mlx, &mlx->c, mx, my);
		menujulia(*mlx, mx, my);
		choice(mlx);
	}
	return (0);
}

void		key_press2(t_mlx *mlx, int key)
{
	if (key == 69)
		mlx->iter += 50;
	if (key == 78 && mlx->iter > 50)
		mlx->iter -= 50;
	if (key == 15)
	{
		mlx->xmax = 2;
		mlx->xmin = -2;
		mlx->ymax = 2;
		mlx->ymin = -2;
		mlx->iter = 100;
		mlx->str[1][0] == '1' ? mlx->c.x = 0 : 0;
		mlx->str[1][0] == '1' ? mlx->c.y = 0 : 0;
	}
}

void		key_press1(t_mlx *mlx, int key)
{
	double	per;

	if (key == 123 || key == 124)
	{
		per = (mlx->ymax - mlx->ymin) * 0.05;
		if (key == 123)
		{
			mlx->xmin += per;
			mlx->xmax += per;
		}
		else if (key == 124)
		{
			mlx->xmin -= per;
			mlx->xmax -= per;
		}
	}
	if (key == 36)
	{
		changefract(mlx);
		ft_exit(mlx, key);
	}
}

int			key_press(int key, void *param)
{
	t_mlx	*mlx;
	double	per;

	mlx = (t_mlx *)param;
	if (key == 53)
		ft_exit(mlx, key);
	if (key == 126 || key == 125)
	{
		per = (mlx->ymax - mlx->ymin) * 0.05;
		if (key == 126)
		{
			mlx->ymin += per;
			mlx->ymax += per;
		}
		else if (key == 125)
		{
			mlx->ymin -= per;
			mlx->ymax -= per;
		}
	}
	key_press1(mlx, key);
	key_press2(mlx, key);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	choice(mlx);
	return (0);
}

int			mousepress(int button, int x, int y, void *param)
{
	t_mlx	*mlx;
	double	x1;
	double	y1;

	mlx = (t_mlx *)param;
	x1 = (mlx->xmax - mlx->xmin) * (double)(x / W) + mlx->xmin;
	y1 = (mlx->ymax - mlx->ymin) * (double)(y / W) + mlx->ymin;
	if (button == 5)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		applyzoom(mlx, x1, y1, 1.2);
	}
	else if (button == 4)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		applyzoom(mlx, x1, y1, 0.8);
	}
	choice(mlx);
	if (button == 1 && !mlx->ps)
		mlx->ps = 1;
	else if (button == 1 && mlx->ps)
		mlx->ps = 0;
	return (0);
}
