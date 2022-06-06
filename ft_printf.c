/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdenna <mabdenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 05:09:07 by mabdenna          #+#    #+#             */
/*   Updated: 2021/12/09 07:21:41 by mabdenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_help(char c, va_list p, int *l, char *pt)
{
	if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(p, int), 1, l);
	else if (c == 's')
	{
		pt = va_arg(p, char *);
		if (pt == NULL)
			pt = "(null)";
		ft_putstr_fd(pt, 1, l);
	}
	else if (c == 'c')
		ft_putchar_fd(va_arg(p, int), 1, l);
	else if (c == 'x')
		ft_tohex(va_arg(p, unsigned int), "0123456789abcdef", 16, l);
	else if (c == 'X')
		ft_tohex(va_arg(p, unsigned int), "0123456789ABCDEF", 16, l);
	else if (c == 'u')
		ft_putnbr_fd(va_arg(p, unsigned int), 1, l);
	else if (c == 'p')
	{
		ft_putstr_fd("0x", 1, l);
		ft_tohex(va_arg(p, unsigned long int), "0123456789abcdef", 16, l);
	}
	else if (c == '%')
		ft_putchar_fd('%', 1, l);
}

int	ft_printf(const char *str, ...)
{
	va_list	p;
	int		i;
	int		l;
	char	*pt;

	i = 0;
	l = 0;
	pt = NULL;
	va_start(p, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_help(str[i], p, &l, pt);
			i++;
			continue ;
		}
		ft_putchar_fd(str[i], 1, &l);
		i++;
	}
	va_end(p);
	return (l);
}
