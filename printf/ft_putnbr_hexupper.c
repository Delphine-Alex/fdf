/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexupper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:51:16 by dpaiva            #+#    #+#             */
/*   Updated: 2024/12/21 19:53:16 by dpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexupper(const unsigned int nb)
{
	if (nb / 16)
		return (ft_putnbr_hexupper(nb / 16) + ft_putnbr_hexupper(nb % 16));
	else if (!(nb / 10))
		return (ft_putchar(nb + '0'));
	else
		return (ft_putchar((nb - 10) + 'A'));
}
