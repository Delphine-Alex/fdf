/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:18:54 by dpaiva            #+#    #+#             */
/*   Updated: 2024/12/10 19:11:53 by dpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(long n)
{
	size_t	word;

	word = 0;
	if (n <= 0)
		word = 1;
	else
		word = 0;
	while (n)
	{
		n = n / 10;
		word++;
	}
	return (word);
}

char	*ft_itoa(int n)
{
	char	*copy;
	size_t	is_neg;
	size_t	word;
	long	nb;

	nb = (long) n;
	word = ft_count_word(nb);
	copy = malloc(sizeof(char) * (word + 1));
	if (copy == NULL)
		return (NULL);
	is_neg = 0;
	if (nb < 0)
	{
		copy[0] = '-';
		nb = -nb;
		is_neg = 1;
	}
	copy[word] = '\0';
	while (word > is_neg)
	{
		copy[word - 1] = nb % 10 + '0';
		nb = nb / 10;
		word--;
	}
	return (copy);
}
