/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 21:11:37 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/03/10 11:11:00 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		choice(t_mlx *mlx)
{
	if (mlx->str[1][0] == '1')
		julia(*mlx);
	else if (mlx->str[1][0] == '2')
		mandelbrot(*mlx);
	else if (mlx->str[1][0] == '3')
		burningship(*mlx);
	else if (mlx->str[1][0] == '4')
		treecorns(*mlx);
	menu(*mlx);
}

t_mlx		init(char **av)
{
	t_mlx	mlx;

	mlx.str = av;
	mlx.ps = 0;
	mlx.iter = 100;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, W, H + 200, "fractol");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, W, H);
	mlx.dtadd = (int *)mlx_get_data_addr(mlx.img_ptr, &mlx.bpp,
	&mlx.size_line, &mlx.end);
	mlx.xmin = -2.0;
	mlx.xmax = 2.0;
	mlx.ymin = -2.0;
	mlx.ymax = 2.0;
	return (mlx);
}

void		ft_error(void)
{
	ft_putendl("Usage: ./fractol \"chose (1 || 2 || 3 || 4).\"\n");
	ft_putendl("1- julia.\n2- mandelbrot.\n3- burningship.\n4- treecorns.");
}

int			main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac == 2 && ft_strlen(av[1]) == 1)
	{
		if (av[1][0] == '1' || av[1][0] == '2' ||
		av[1][0] == '3' || av[1][0] == '4')
		{
			mlx = init(av);
			choice(&mlx);
			mlx_hook(mlx.win_ptr, 6, 0, &mousemove, &mlx);
			mlx_hook(mlx.win_ptr, 4, 0, &mousepress, &mlx);
			mlx_hook(mlx.win_ptr, 2, 0, &key_press, &mlx);
			mlx_hook(mlx.win_ptr, 17, 0, &ft_exit, &mlx);
			mlx_loop(mlx.mlx_ptr);
		}
		else
			ft_error();
	}
	else
		ft_error();
	return (0);
}
