/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:56:30 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/03/15 23:13:12 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		switch_plur2(t_frctl *f)
{
	if (f->type_fract == MAND8)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		COLOR_WHITE, "SeaBrot");
	else if (f->type_fract == JULIA)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		COLOR_WHITE, "Julia");
	else if (f->type_fract == SHIP)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		COLOR_WHITE, "Fire_Ship");
	mlx_string_put(f->ptr, f->win, f->menu.x, f->menu.y += 20,
	COLOR_GREEN, "--------------------");
}

void		error_exit(char *str)
{
	ft_putendl(str);
	exit(0);
}

int			main(int ac, char **av)
{
	t_frctl	*f;

	if (ac == 2)
	{
		if (!(f = (t_frctl *)ft_memalloc(sizeof(t_frctl))))
			error_exit("\033[0;31;1mError malloc by [s_frctl]\033[0m");
		f->count_window = 0;
		init_mlx(f, (f->name = av[1]));
		pars_frctl(f->name, f);
		mlx_loop_list(f);
	}
	else
		error_exit("\033[0;32;1mOh... sorry.\nUse parametr:\033[0m\n\
		[mand]\n\
		[julia]\n\
		[fire_ship]");
	return (0);
}
