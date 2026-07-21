/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:41:26 by dpaiva            #+#    #+#             */
/*   Updated: 2024/12/21 17:20:44 by dpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(const unsigned int nb)
{
	if (nb / 10)
		return (ft_putunbr(nb / 10) + ft_putunbr(nb % 10));
	else
		return (ft_putchar(nb + '0'));
}
