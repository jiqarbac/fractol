/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:13:18 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/02/27 17:31:54 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_mlx mlx)
{
	mlx.i = -1;
	while (++mlx.i < W)
	{
		mlx.j = -1;
		while (++mlx.j < H)
		{
			mlx.it = 0;
			mlx.zr = (mlx.xmax - mlx.xmin) * (double)(mlx.i / W) + mlx.xmin;
			mlx.zi = (mlx.ymax - mlx.ymin) * (double)(mlx.j / H) + mlx.ymin;
			while (mlx.zr * mlx.zr + mlx.zi * mlx.zi < 4 && mlx.it < mlx.iter)
			{
				mlx.tmp = mlx.zr;
				mlx.zr = mlx.zr * mlx.zr - mlx.zi * mlx.zi + mlx.c.x;
				mlx.zi = (2 * mlx.tmp * mlx.zi) + mlx.c.y;
				mlx.it++;
			}
			dt(&mlx, mlx.i, mlx.j, clr(mlx.it));
		}
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
}
