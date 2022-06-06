/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdenna <mabdenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 07:04:28 by mabdenna          #+#    #+#             */
/*   Updated: 2021/12/09 07:26:45 by mabdenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(long long n, int fd, int *l)
{
	unsigned long	nm;

	if (n < 0)
	{
		ft_putchar_fd('-', fd, l);
		n = n * -1;
	}
	nm = n;
	if (nm >= 10)
		ft_putnbr_fd(nm / 10, fd, l);
	ft_putchar_fd(nm % 10 + 48, fd, l);
}
