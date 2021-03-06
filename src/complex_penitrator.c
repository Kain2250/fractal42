/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_penitrator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 17:38:46 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/03/14 23:00:33 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		multi_complex(t_complex a, t_complex b)
{
	t_complex	z;

	z.real = (a.real * b.real - a.imag * b.imag);
	z.imag = (a.real * b.imag + a.imag * b.real);
	return (z);
}

t_complex		addit_complex(t_complex a, t_complex b)
{
	t_complex	z;

	z.real = a.real + b.real;
	z.imag = a.imag + b.imag;
	return (z);
}

t_complex		subtraction_complex(t_complex a, t_complex b)
{
	t_complex	z;

	z.real = a.real - b.real;
	z.imag = a.imag - b.imag;
	return (z);
}

double			mod_complex(t_complex z)
{
	double		r;

	r = sqrt(z.real * z.real + z.imag * z.imag);
	return (r);
}

t_complex		abs_complex(t_complex z)
{
	z.real = fabs(z.real);
	z.imag = fabs(z.imag);
	return (z);
}
