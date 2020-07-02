/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:18:51 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/03/15 23:40:50 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				put_menu_plur_change_color_switch(t_frctl *f)
{
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
	COLOR_GREEN, "--------------------");
	if (f->clr_sw.plur == 1)
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
		COLOR_WHITE, "'H' - Clr_Plur ON");
	else
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
		COLOR_WHITE, "'H' - Clr_Plur OFF");
	if (f->clr_sw.final == 1)
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
		COLOR_WHITE, "'N' - Clr_Cant ON");
	else
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
		COLOR_WHITE, "'N' - Clr_Cant OFF");
	if (f->clr_sw.start == 1)
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
		COLOR_WHITE, "'T' - Clr_Backgr ON");
	else
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
		COLOR_WHITE, "'T' - Clr_Backgr OFF");
}

void				put_menu_keycode(t_frctl *f)
{
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
	COLOR_GREEN, "--------------------");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	COLOR_WHITE, "'E' - Thread + ");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	COLOR_WHITE, "'Q' - Thread - ");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	COLOR_WHITE, "'}' - Itter + ");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	COLOR_WHITE, "'{' - Itter - ");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
	COLOR_GREEN, "--------------------");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
	COLOR_WHITE, "'A,W,D,S' - Shift_Plur ");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	COLOR_WHITE, "'Arrows' - Move");
	if (f->mouse.is_pres_key == 1)
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
		COLOR_WHITE, "'Space' Move Plur ON");
	else
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
		COLOR_WHITE, "'Space' Move Plur OFF");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	COLOR_GREEN, "--------------------");
}

void				put_menu_status_plur(t_frctl *f)
{
	char			*str;

	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
	COLOR_GREEN, "--------------------");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
	COLOR_WHITE, "Itter - ");
	mlx_string_put(f->ptr, f->win, f->menu.x + 80, f->menu.y,
	COLOR_WHITE, (str = ft_itoa(f->max_iter)));
	free(str);
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
	COLOR_WHITE, "Threads - ");
	mlx_string_put(f->ptr, f->win, f->menu.x + 100, f->menu.y,
	COLOR_WHITE, (str = ft_itoa(f->threads)));
	free(str);
}

void				put_menu_color_switch(t_frctl *f)
{
	if (f->clr_sw.red == 1)
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
		COLOR_DARKRED, "'R' - Rad_Canal ON");
	else
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
		COLOR_DARKRED, "'R' - Rad_Canal OFF");
	if (f->clr_sw.green == 1)
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
		COLOR_DARKGREEN, "'G' - Green_Canal ON");
	else
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
		COLOR_DARKGREEN, "'G' - Green_Canal OFF");
	if (f->clr_sw.blue == 1)
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
		COLOR_DARKBLE, "'B' - Blue_Canal ON");
	else
		mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
		COLOR_DARKBLE, "'B' - Blue_Canal OFF");
}

void				put_menu(t_frctl *f)
{
	int				*image;
	register int	i;

	image = (int *)(f->menu.data_addr);
	i = 0;
	while (i < HEIGHT_MENU * WIDTH_MENU)
		image[i++] = COLOR_DEEPSPACEBLUE;
	mlx_put_image_to_window(f->ptr, f->win, f->menu.img,
	WIDTH_WIN - WIDTH_MENU, 0);
	f->menu.y = 0;
	f->menu.x = WIDTH_WIN - WIDTH_MENU + 5;
	switch_plur(f);
	put_menu_color_switch(f);
	put_menu_plur_change_color_switch(f);
	put_menu_color_type(f);
	put_menu_status_plur(f);
	put_menu_keycode(f);
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	COLOR_WHITE, "'Enter' - Open_new_Win ");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	COLOR_WHITE, "Mouse Move - Shift_Plur");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 25,
	COLOR_WHITE, "Scroll - Zoom");
	mlx_string_put(f->ptr, f->win, f->menu.x + 100, f->menu.y += 25,
	COLOR_BURLYWOOD, "By Bdrinkin");
}
