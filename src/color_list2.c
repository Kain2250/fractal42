/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_list2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 21:12:26 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/03/14 21:53:01 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	switch_color_preset(t_frctl *f, int key)
{
	if (key == KEY_1)
	{
		f->color.odd = 0;
		f->color.interpol = 1;
	}
	else if (key == KEY_2)
	{
		f->color.odd = 1;
		f->color.interpol = 0;
	}
	else if (key == KEY_3)
	{
		f->color.odd = 0;
		f->color.interpol = 1;
	}
	else if (key == KEY_4)
	{
		f->color.odd = 1;
		f->color.interpol = 0;
	}
	calc_plur(f);
}

void	odd_pars(t_frctl *f, t_crd crd)
{
	if (f->iter % 2 == 1)
	{
		f->color.curent = get_color(f->color.curent, f->color.start,
		f->color.final, f);
		put_pixel(crd.x, crd.y, f, f->color.curent);
	}
	else
	{
		f->color.final = COLOR_BURLYWOOD;
		f->color.start = COLOR_BLACK;
		f->color.curent = get_color(f->color.curent, f->color.start,
		f->color.final, f);
		put_pixel(crd.x, crd.y, f, f->color.curent);
		f->color.start = COLOR_BLACK;
		f->color.final = COLOR_BLUE;
	}
}

void	interpol_pars(t_frctl *f, t_crd crd)
{
	f->color.curent = get_color(f->color.curent, f->color.start,
	f->color.final, f);
	put_pixel(crd.x, crd.y, f, f->color.curent);
}

int		find_color(t_frctl *f, t_crd crd)
{
	if (f->iter == f->max_iter)
	{
		put_pixel(crd.x, crd.y, f, f->color.plur);
		return (1);
	}
	else
	{
		if (f->color.odd == 1)
			odd_pars(f, crd);
		else if (f->color.interpol == 1)
			interpol_pars(f, crd);
	}
	return (0);
}
