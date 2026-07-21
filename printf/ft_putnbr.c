/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:41:28 by dpaiva            #+#    #+#             */
/*   Updated: 2024/12/19 20:44:47 by dpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printnbr(const long nbr)
{
	if (nbr / 10)
		return (ft_printnbr(nbr / 10) + ft_printnbr(nbr % 10));
	else
		return (ft_putchar(nbr + '0'));
}

int	ft_putnbr(const int nb)
{
	long	nbr;

	nbr = (long)nb;
	if (nbr < 0)
	{
		nbr = -nbr;
		return (ft_putchar('-') + ft_printnbr(nbr));
	}
	else
		return (ft_printnbr(nbr));
}
