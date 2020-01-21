/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:09:26 by aguenel           #+#    #+#             */
/*   Updated: 2020/01/20 20:09:31 by aguenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_char(va_list *args, t_p *p)
{
	char	c;

	c = va_arg(*args, int);
	p->width -= p->precision < 1 && p->precision != -1 ? p->precision : 1;
	if (p->moins)
	{
		if ((c == '\0' || c == 0))
			ft_putchar_fd(0, 1);
		else
			write(1, &c, 1);
		ft_diuxx(p);
	}
	else
	{
		ft_diuxx(p);
		if ((c == '\0' || c == 0))
			ft_putchar_fd(0, 1);
		else
			write(1, &c, 1);
	}
	p->res++;
}
