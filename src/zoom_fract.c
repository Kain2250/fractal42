/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 19:59:41 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/03/14 19:07:01 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			julia_dezoom(t_frctl *f, int x, int y)
{
	t_complex	m;

	m.real = x / f->zoom + f->jx;
	m.imag = y / f->zoom + f->jy;
	f->zoom /= 1.50;
	f->range_move *= 1.50;
	f->jx = m.real - x / f->zoom;
	f->jy = m.imag - y / f->zoom;
	f->max_iter -= 3;
	if (f->max_iter < 10)
		f->max_iter = 10;
	if (f->max_iter > INT_MAX)
		f->max_iter = INT_MAX;
	calc_plur(f);
}

void			julia_zoom(t_frctl *f, int x, int y)
{
	t_complex	m;

	m.real = x / f->zoom + f->jx;
	m.imag = y / f->zoom + f->jy;
	f->zoom *= 1.50;
	f->range_move /= 1.50;
	f->jx = m.real - x / f->zoom;
	f->jy = m.imag - y / f->zoom;
	f->max_iter += 3;
	if (f->max_iter < 10)
		f->max_iter = 10;
	if (f->max_iter > INT_MAX)
		f->max_iter = INT_MAX;
	calc_plur(f);
}

void			other_dezoom(t_frctl *f, int x, int y)
{
	t_complex	m;

	m.real = x / f->zoom + f->cx;
	m.imag = y / f->zoom + f->cy;
	f->zoom /= 1.1;
	f->range_move *= 1.1;
	f->cx = m.real - x / f->zoom;
	f->cy = m.imag - y / f->zoom;
	f->max_iter -= 1;
	if (f->max_iter < 10)
		f->max_iter = 10;
	if (f->max_iter > INT_MAX)
		f->max_iter = INT_MAX;
	calc_plur(f);
}

void			other_zoom(t_frctl *f, int x, int y)
{
	t_complex	m;

	m.real = x / f->zoom + f->cx;
	m.imag = y / f->zoom + f->cy;
	f->zoom *= 1.1;
	f->range_move /= 1.1;
	f->cx = m.real - x / f->zoom;
	f->cy = m.imag - y / f->zoom;
	f->max_iter += 1;
	if (f->max_iter < 10)
		f->max_iter = 10;
	if (f->max_iter > INT_MAX)
		f->max_iter = INT_MAX;
	calc_plur(f);
}

int				mouse_key(int button, int x, int y, void *param)
{
	t_frctl		*f;

	f = (t_frctl *)param;
	if (button == 4)
	{
		if (f->type_fract == JULIA)
			julia_dezoom(f, x, y);
		else
			other_dezoom(f, x, y);
	}
	if (button == 5)
	{
		if (f->type_fract == JULIA)
			julia_zoom(f, x, y);
		else
			other_zoom(f, x, y);
	}
	return (0);
}
