/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:09:55 by aguenel           #+#    #+#             */
/*   Updated: 2020/01/20 20:09:57 by aguenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_di_width_else(t_p *p, int num)
{
	if (p->precision > 0 && p->nbrn)
		p->width--;
	p->width -= (int)ft_size((long long)num) == 1 && p->precision == 0
	&& p->width != 0 && num != 0 ? 1 : 0;
	print_smth(' ', p->width, p);
	if (p->precision != 0 || num != 0)
	{
		if (p->nbrn)
		{
			ft_putchar_fd('-', 1);
			if (!p->done && p->precision != 0)
				p->precision++;
		}
		print_smth('0', p->precision, p);
		ft_putnbr_fd(num, 1, p);
	}
}

void			ft_di_width1(t_p *p, int num)
{
	if (p->moins)
	{
		if (p->nbrn)
		{
			ft_putchar_fd('-', 1);
			p->precision += p->precision > 0 ? 1 : 0;
			p->width -= p->precision > 0 ? 1 : 0;
		}
		if (p->moins && p->precision == (int)ft_size(num) - 1 && p->nbrn)
			p->precision--;
		print_smth('0', p->precision, p);
		if (!(num == 0 && p->precision == 0 && p->moins))
			ft_putnbr_fd(num, 1, p);
		print_smth(' ', p->width, p);
	}
	else
		ft_di_width_else(p, num);
}
