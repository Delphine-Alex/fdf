/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:20:41 by dpaiva            #+#    #+#             */
/*   Updated: 2024/12/22 18:41:00 by dpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printadress(const unsigned long nb)
{
	if (nb / 16)
		return (ft_printadress(nb / 16) + ft_printadress(nb % 16));
	else if (!(nb / 10))
		return (ft_putchar(nb + '0'));
	else
		return (ft_putchar((nb - 10) + 'a'));
}

int	ft_putadress(const void *adress)
{
	if (!adress)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (2 + ft_printadress((unsigned long) adress));
}
