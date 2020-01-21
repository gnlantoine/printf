/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:11:06 by aguenel           #+#    #+#             */
/*   Updated: 2020/01/20 20:11:09 by aguenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_u_width1(t_p *p, unsigned int num)
{
	if (p->moins)
	{
		print_smth('0', p->precision, p);
		convert_u(num, p);
		print_smth(' ', p->width, p);
	}
	else if (p->zero && p->width < p->precision && !p->bprecision)
	{
		p->width -= p->precision > 0 && p->nbrn ? 1 : 0;
		print_smth('0', p->width, p);
		if (p->precision != 0)
			print_smth('0', p->precision, p);
		if (num != 0 || p->precision != 0)
			convert_u(num, p);
	}
	else
	{
		p->width -= p->precision > 0 && p->nbrn ? 1 : 0;
		print_smth(' ', p->width, p);
		if (p->precision != 0)
			print_smth('0', p->precision, p);
		if (num != 0 || p->precision != 0)
			convert_u(num, p);
	}
}
