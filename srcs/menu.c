/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:03:16 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/03/10 11:14:30 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		menu2(t_mlx mlx)
{
	char	*it;

	it = ft_itoa(mlx.iter);
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 10, W + 70, 0xffff00,
			"R           = Reset");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 10, W + 130, 0xffff00,
			"+           = + 50 iteration");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 10, W + 150, 0xffff00,
			"-           = - 50 iteration");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 10, W + 170, 0xffff00,
			"Enter       = Change fractal");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 10, W + 90, 0xffff00,
			"Scroll UP   = Zoom UP");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 10, W + 110, 0xffff00,
			"Scroll DOWN = Zoom DOWN");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 320, W + 110, 0xffff00,
			"iteration = ");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 450, W + 110, 0xffff00,
			it);
	ft_strdel(&it);
}

void		menu(t_mlx mlx)
{
	mlx.str[1][0] == '2' ? mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 10,
			W + 10, 0xffff00, "Mandelbrot") : 0;
	mlx.str[1][0] == '1' ? mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 10,
			W + 10, 0xffff00, "Julia") : 0;
	mlx.str[1][0] == '1' ? mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 320,
			W + 150, 0xffff00,
			"Mouse Left Button = stop && start") : 0;
	mlx.str[1][0] == '1' ? mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 520,
			W + 170, 0xffff00, "moving julia") : 0;
	mlx.str[1][0] == '1' ? mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 320,
			W + 70, 0xffff00, "Mouse x   = ") : 0;
	mlx.str[1][0] == '1' ? mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 320,
			W + 90, 0xffff00, "Mouse y   = ") : 0;
	mlx.str[1][0] == '3' ? mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 10,
			W + 10, 0xffff00, "Burningship") : 0;
	mlx.str[1][0] == '4' ? mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 10,
			W + 10, 0xffff00, "Treecorns") : 0;
	menu2(mlx);
}

void		menujulia(t_mlx mlx, int mx, int my)
{
	mlx_string_put(mlx.mlx_ptr, \
	mlx.win_ptr, 450, W + 70, 0xffff00, ft_itoa(mx));
	mlx_string_put(mlx.mlx_ptr, \
	mlx.win_ptr, 450, W + 90, 0xffff00, ft_itoa(my));
}
