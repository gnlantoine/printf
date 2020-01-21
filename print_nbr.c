/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:09:41 by aguenel           #+#    #+#             */
/*   Updated: 2020/01/20 20:09:45 by aguenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_di_width(t_p *p, int num)
{
	if ((!p->moins) && (p->zero) && p->precision == -1
	&& p->width > p->precision && p->bprecision == false)
	{
		if (p->nbrn)
			ft_putchar_fd('-', 1);
		if (p->precision == -1)
			print_smth('0', p->width, p);
		else
			print_smth(' ', p->width, p);
		ft_putnbr_fd(num, 1, p);
	}
	else
		ft_di_width1(p, num);
}

void			ft_di(t_p *p, int num)
{
	if (p->width >= 1)
		ft_di_width(p, num);
	else
	{
		if (p->nbrn)
			ft_putchar_fd('-', 1);
		if (p->precision != 0 && !p->done)
			p->precision = p->nbrn ? p->precision + 1 : p->precision;
		print_smth('0', p->precision, p);
		ft_putnbr_fd(num, 1, p);
	}
}

void			init_prec_width(t_p *p, int num)
{
	p->nbrn = num < 0 ? true : false;
	p->res += num < 0 ? 1 : 0;
	p->width -= (p->precision > (int)ft_size((long long)num))
	&& p->precision != -1 ? p->precision : (int)ft_size((long long)num);
	p->bprecision = p->precision > -1 ? true : false;
	p->width += (int)ft_size((long long)num) == 1 && p->precision == 0
	&& ((p->width != 0 && !p->moins) || num == 0) ? 1 : 0;
}

void			ft_precisionnot0(t_p *p, int num)
{
	if (p->precision == (int)ft_size((long long)num) && p->nbrn)
	{
		p->precision = 1;
		p->done = true;
	}
	else
		p->precision = p->precision > (int)ft_size((long long)num) ?
		p->precision - (int)ft_size((long long)num) : -1;
}

void			ft_nbr(va_list *args, t_p *p)
{
	int		num;

	num = va_arg(*args, int);
	init_prec_width(p, num);
	if (p->precision != 0)
		ft_precisionnot0(p, num);
	if (p->precision == 0 && p->width == 0 && num == 0)
		return ;
	else if (p->moins && (p->precision == -1 || p->precision == 0))
	{
		print_smth('0', p->precision, p);
		ft_di(p, num);
	}
	else if (!(p->moins) || (p->moins && p->precision > 0))
		ft_di(p, num);
	else if (p->precision == 0 && p->width > 0)
	{
		print_smth(' ', p->width, p);
		if (num != 0)
			ft_di(p, num);
	}
}
