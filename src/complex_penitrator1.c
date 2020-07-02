/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_penitrator1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:45:29 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/03/15 21:54:05 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		sin_cos_tg_complex(t_complex z, char *real, char *imag)
{
	if (ft_strcmp(real, "sin") == 0)
		z.real = sin(z.real);
	if (ft_strcmp(imag, "sin") == 0)
		z.imag = sin(z.imag);
	if (ft_strcmp(real, "cos") == 0)
		z.real = cos(z.real);
	if (ft_strcmp(imag, "cos") == 0)
		z.imag = cos(z.imag);
	if (ft_strcmp(real, "tan") == 0)
		z.real = tan(z.real);
	if (ft_strcmp(imag, "tan") == 0)
		z.imag = tan(z.imag);
	return (z);
}

t_complex		quatro_complex(t_complex a, t_complex b)
{
	t_complex	z;

	z = multi_complex(multi_complex(a, b), multi_complex(a, b));
	return (z);
}
