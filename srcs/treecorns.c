/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treecorns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:07:48 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/02/25 17:36:03 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	treecorns(t_mlx mlx)
{
	double	tmp;

	mlx.i = -1;
	while (++mlx.i < W)
	{
		mlx.j = -1;
		while (++mlx.j < H)
		{
			mlx.cr = (mlx.xmax - mlx.xmin) * (double)(mlx.i / W) + mlx.xmin;
			mlx.ci = (mlx.ymax - mlx.ymin) * (double)(mlx.j / H) + mlx.ymin;
			mlx.zi = 0;
			mlx.zr = 0;
			mlx.it = 0;
			while (mlx.zr * mlx.zr + mlx.zi * mlx.zi < 4 && mlx.it < mlx.iter)
			{
				tmp = mlx.zr;
				mlx.zr = (mlx.zr * mlx.zr - mlx.zi * mlx.zi + mlx.cr);
				mlx.zi = -2 * tmp * mlx.zi + mlx.ci;
				mlx.it++;
			}
			dt(&mlx, mlx.i, mlx.j, clr(mlx.it));
		}
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
}
