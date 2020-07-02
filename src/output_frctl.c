/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_frctl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:25:25 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/03/12 21:19:50 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_light(int start, int end, double percentage)
{
	int		ret;

	ret = (1 - percentage) * start + (percentage * end);
	return (ret);
}

int			get_color(int current, int start, int end, t_frctl *f)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current == end)
		return (current);
	else
		percentage = ft_percent(f->start_iter, f->max_iter, f->iter);
	red = get_light((start >> 16) & 0xFF,
	(end >> 16) & 0xFF, percentage);
	green = get_light((start >> 8) & 0xFF,
	(end >> 8) & 0xFF, percentage);
	blue = get_light(start & 0xFF, end & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void		put_pixel(int x, int y, t_frctl *f, int color)
{
	int		i;

	if (x > 0 && x < (WIDTH_WIN - WIDTH_MENU) && y >= 0 && y < HEIGHT_WIN)
	{
		i = (x * f->bits_per_pixel / 8) + (y * f->size_line);
		f->data_addr[i] = color;
		f->data_addr[++i] = color >> 8;
		f->data_addr[++i] = color >> 16;
		f->data_addr[++i] = 0;
	}
}

void		output_background(t_frctl *f, int menu_or_img)
{
	if (menu_or_img == 1)
		ft_bzero(f->menu.data_addr, WIDTH_MENU * HEIGHT_MENU *
		(f->menu.bits_per_pixel / 8));
	else
		ft_bzero(f->data_addr, (WIDTH_WIN - WIDTH_MENU) * HEIGHT_WIN *
		(f->bits_per_pixel / 8));
}
