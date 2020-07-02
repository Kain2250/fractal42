/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_conf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:29:15 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/03/15 23:05:26 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			switch_plur(t_frctl *f)
{
	if (f->type_fract == MAND1)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		COLOR_WHITE, "Mandelbrot");
	else if (f->type_fract == MAND2)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		COLOR_WHITE, "TriplelBrot");
	else if (f->type_fract == MAND3)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		COLOR_WHITE, "Koridor");
	else if (f->type_fract == MAND4)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		COLOR_WHITE, "Buffalo");
	else if (f->type_fract == MAND5)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		COLOR_WHITE, "Alien");
	else if (f->type_fract == MAND6)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		COLOR_WHITE, "MegaBrot");
	else if (f->type_fract == MAND7)
		mlx_string_put(f->ptr, f->win, f->menu.x + 50, f->menu.y += 25,
		COLOR_WHITE, "Buket");
	switch_plur2(f);
}

t_complex		init_mand3(t_complex z)
{
	t_complex	z2;

	z2 = sin_cos_tg_complex(z, "tan", "tan");
	return (z2);
}

t_complex		init_mand5(t_complex z)
{
	t_complex	z2;
	t_complex	z3;

	z3.real = mod_complex(z);
	z3.imag = mod_complex(z);
	z2 = multi_complex(z3, z3);
	return (z2);
}

t_complex		mand_who(t_frctl *f, t_complex z)
{
	t_complex	z2;

	if (f->type_fract == MAND2)
		z2 = multi_complex(multi_complex(z, z), multi_complex(z, z));
	else if (f->type_fract == MAND3)
		z2 = init_mand3(z);
	else if (f->type_fract == MAND4)
		z2 = abs_complex(multi_complex(z, z));
	else if (f->type_fract == MAND5)
		z2 = init_mand5(z);
	else if (f->type_fract == MAND6)
		z2 = quatro_complex(quatro_complex(z, z), quatro_complex(z, z));
	else if (f->type_fract == MAND7)
		z2 = abs_complex(addit_complex(z, quatro_complex(z, z)));
	else
		z2 = sin_cos_tg_complex(quatro_complex(z, z), "tan", "sin");
	return (z2);
}

void			calc_plur(t_frctl *f)
{
	pthread_t	tid[f->threads];
	t_frctl		cur[f->threads];
	int			i;

	i = 0;
	while (i++ < f->threads)
	{
		ft_memcpy((void *)&cur[i - 1], (void *)f, sizeof(t_frctl));
		cur[i - 1].cur_y = ((double)(1.00 / f->threads) * (WIDTH_WIN -
		WIDTH_MENU)) * (i - 1);
		cur[i - 1].max_y = ((double)(1.00 / f->threads) * (WIDTH_WIN -
		WIDTH_MENU)) * (i);
	}
	i = 0;
	output_background(f, 0);
	while (i < f->threads)
	{
		pthread_create(&tid[i], NULL, draw_plur, &cur[i]);
		i++;
	}
	i = 0;
	while (i < f->threads)
		pthread_join(tid[i++], NULL);
	mlx_put_image_to_window(f->ptr, f->win, f->img, 0, 0);
	put_menu(f);
}
