/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:19:57 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/03/19 16:49:22 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	applyzoom(t_mlx *e, double mousr, double mousi, double zmfactor)
{
	double	interpolation;

	interpolation = 1.0 / zmfactor;
	e->xmin = interpolate(mousr, e->xmin, interpolation);
	e->ymin = interpolate(mousi, e->ymin, interpolation);
	e->xmax = interpolate(mousr, e->xmax, interpolation);
	e->ymax = interpolate(mousi, e->ymax, interpolation);
}
