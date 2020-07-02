/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:15:49 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/03/14 21:54:17 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_color_start(t_frctl *f, int key)
{
	if ((f->clr_sw.red == 1) && (f->clr_sw.start == 1) && key == KEY_PLUS)
		f->color.start += RAD_STEP;
	else if ((f->clr_sw.red == 1) && (f->clr_sw.start == 1) && key ==
		KEY_MINUS)
		f->color.start -= RAD_STEP;
	else if ((f->clr_sw.green == 1) && (f->clr_sw.start == 1) && key ==
		KEY_PLUS)
		f->color.start += GREEN_STEP;
	else if ((f->clr_sw.green == 1) && (f->clr_sw.start == 1) && key ==
		KEY_MINUS)
		f->color.start -= GREEN_STEP;
	else if ((f->clr_sw.blue == 1) && (f->clr_sw.start == 1) && key ==
		KEY_PLUS)
		f->color.start += BLUE_STEP;
	else if ((f->clr_sw.blue == 1) && (f->clr_sw.start == 1) && key ==
		KEY_MINUS)
		f->color.start -= BLUE_STEP;
	calc_plur(f);
}

void	change_color_m(t_frctl *f, int key)
{
	if ((f->clr_sw.red == 1) && (f->clr_sw.plur == 1) && key == KEY_PLUS)
		f->color.plur += RAD_STEP;
	else if ((f->clr_sw.red == 1) && (f->clr_sw.plur == 1) && key ==
		KEY_MINUS)
		f->color.plur -= RAD_STEP;
	else if ((f->clr_sw.green == 1) && (f->clr_sw.plur == 1) && key ==
		KEY_PLUS)
		f->color.plur += GREEN_STEP;
	else if ((f->clr_sw.green == 1) && (f->clr_sw.plur == 1) && key ==
		KEY_MINUS)
		f->color.plur -= GREEN_STEP;
	else if ((f->clr_sw.blue == 1) && (f->clr_sw.plur == 1) && key ==
		KEY_PLUS)
		f->color.plur += BLUE_STEP;
	else if ((f->clr_sw.blue == 1) && (f->clr_sw.plur == 1) && key ==
		KEY_MINUS)
		f->color.plur -= BLUE_STEP;
	calc_plur(f);
}

void	change_color_final(t_frctl *f, int key)
{
	if ((f->clr_sw.red == 1) && (f->clr_sw.final == 1) && key == KEY_PLUS)
		f->color.final += RAD_STEP;
	else if ((f->clr_sw.red == 1) && (f->clr_sw.final == 1) && key ==
		KEY_MINUS)
		f->color.final -= RAD_STEP;
	else if ((f->clr_sw.green == 1) && (f->clr_sw.final == 1) && key ==
		KEY_PLUS)
		f->color.final += GREEN_STEP;
	else if ((f->clr_sw.green == 1) && (f->clr_sw.final == 1) && key ==
		KEY_MINUS)
		f->color.final -= GREEN_STEP;
	else if ((f->clr_sw.blue == 1) && (f->clr_sw.final == 1) && key ==
		KEY_PLUS)
		f->color.final += BLUE_STEP;
	else if ((f->clr_sw.blue == 1) && (f->clr_sw.final == 1) && key ==
		KEY_MINUS)
		f->color.final -= BLUE_STEP;
	calc_plur(f);
}

void	switch_color(t_frctl *f, int key)
{
	if (key == KEY_R)
		f->clr_sw.red *= -1;
	else if (key == KEY_G)
		f->clr_sw.green *= -1;
	else if (key == KEY_B)
		f->clr_sw.blue *= -1;
	put_menu(f);
}

void	switch_area(t_frctl *f, int key)
{
	if (key == KEY_T)
		f->clr_sw.start *= -1;
	else if (key == KEY_H)
		f->clr_sw.plur *= -1;
	else if (key == KEY_N)
		f->clr_sw.final *= -1;
	put_menu(f);
}
