/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:32:16 by dpaiva            #+#    #+#             */
/*   Updated: 2024/12/19 20:50:03 by dpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_findformat(const char *str, va_list args, size_t i)
{
	if (str[i] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (str[i] == 'd' || str[i] == 'i')
		return (ft_putnbr(va_arg(args, const int)));
	else if (str[i] == 'p')
		return (ft_putadress(va_arg(args, const void *)));
	else if (str[i] == 's')
		return (ft_putstr(va_arg(args, const char *)));
	else if (str[i] == 'u')
		return (ft_putunbr(va_arg(args, const unsigned int)));
	else if (str[i] == 'x')
		return (ft_putnbr_hexlower(va_arg(args, const unsigned int)));
	else if (str[i] == 'X')
		return (ft_putnbr_hexupper(va_arg(args, const unsigned int)));
	else if (str[i] == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		nb;

	if (!format)
		return (-1);
	i = 0;
	nb = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			nb += ft_findformat(format, args, i);
		}
		else
			nb += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (nb);
}

// #include <stdio.h>
// #include <limits.h>

// int main()
// {
// 	ft_printf("--------------  no pourcent  ------------------\n");

// 	ft_printf("%1");

// 	ft_printf("\n---------------  pourcent c -------------------\n");

//     char c = 'd';
//     ft_printf("%c", c); //nb = 1

// 	ft_printf("\n-----------  pourcent pourcent ----------------\n");

//     ft_printf("Test: %%");

// 	ft_printf("\n---------------  pourcent s -------------------\n");

// 	// char *s = "Hello world, 42!";
//     char *s = NULL;
//     ft_printf("Test: %s", s);

// 	ft_printf("\n---------------  pourcent d -------------------\n");

// 	// int count = 4 + 5;
// 	// int count = -2147483648;
// 	int count = 2147483647;
//     ft_printf("Count: %d", count);

// 	ft_printf("\n---------------  pourcent u -------------------\n");

// 	int n = 9;
// 	// int count = -9;
// 	char d = 'd';
// 	ft_printf("Count: %u, %u", d, n);

// 	ft_printf("\n---------------  pourcent x -------------------\n");

// 	int nb_hexlower = 160;
// 	ft_printf("Count: %x", nb_hexlower);

// 	ft_printf("\n---------------  pourcent X -------------------\n");

// 	int nb_hexupper = UINT_MAX;
// 	ft_printf("Count: %x", nb_hexupper);

// 	printf("\n---------------  pourcent p -------------------\n");

// 	// int nbr = 5;
// 	int *ptr = NULL;
// 	// int *ptr = &nbr;
// 	ft_printf("TEST %p\n", ptr);

// 	ft_printf("\n---------------  printf(0) -------------------\n");

// 	ft_printf("%d\n", ft_printf(0));
// 	printf("%d\n", printf(0));

//     return (0);
// }
