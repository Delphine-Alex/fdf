/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexlower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:40:40 by dpaiva            #+#    #+#             */
/*   Updated: 2024/12/21 19:42:42 by dpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexlower(const unsigned int nb)
{
	if (nb / 16)
		return (ft_putnbr_hexlower(nb / 16) + ft_putnbr_hexlower(nb % 16));
	else if (!(nb / 10))
		return (ft_putchar(nb + '0'));
	else
		return (ft_putchar((nb - 10) + 'a'));
}
