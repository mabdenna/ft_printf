/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdenna <mabdenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 07:04:42 by mabdenna          #+#    #+#             */
/*   Updated: 2021/12/09 07:07:45 by mabdenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_tohex(unsigned long int nb, char *to, int base, int *l)
{
	if (nb >= (unsigned long int)base)
		ft_tohex(nb / base, to, base, l);
	ft_putchar_fd(to[nb % base], 1, l);
}
