/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:29:15 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/03/19 16:53:50 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>

# define W 700.0
# define H 700.0

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_color
{
	int			i;
	int			j;
	int			l;
}				t_color;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		**str;
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	int			size_line;
	int			end;
	int			bpp;
	int			*dtadd;
	int			i;
	int			j;
	int			ps;
	int			it;
	int			iter;
	double		tmp;
	double		cr;
	double		ci;
	double		zr;
	double		zi;
	t_point		c;
	t_color		r;
}				t_mlx;

void			julia(t_mlx mlx);
void			mandelbrot(t_mlx mlx);
void			burningship(t_mlx mlx);
void			treecorns(t_mlx mlx);
void			set(t_mlx *mlx, t_point *point, int x, int y);
void			applyzoom(t_mlx *e, double mousr, double mousi,
				double zmfactor);
void			choice(t_mlx *mlx);
void			dt(t_mlx *mlx, int x, int y, int color);
void			menu(t_mlx mlx);
void			menujulia(t_mlx mlx, int mx, int my);
void			changefract(t_mlx *mlx);
int				key_press(int keycode, void *param);
int				ft_exit(void *param, int key);
int				clr(int iter);
int				mousemove(int mx, int my, void *param);
int				mousepress(int button, int x, int y, void *param);
int				main(int ac, char **av);
double			ft_map(int i);

#endif
