/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:32:08 by dpaiva            #+#    #+#             */
/*   Updated: 2024/12/22 19:52:34 by dpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>

size_t	ft_putstr(const char *str);
size_t	ft_strlen(const char *str);
int		ft_putchar(int c);
int		ft_putnbr(const int n);
int		ft_putnbr_hexlower(const unsigned int n);
int		ft_putnbr_hexupper(const unsigned int n);
int		ft_putunbr(const unsigned int n);
int		ft_printf(const char *format, ...);
int		ft_putadress(const void *adress);

#endif
