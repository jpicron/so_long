/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <jpicron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:56:14 by jpicron           #+#    #+#             */
/*   Updated: 2022/10/06 21:18:07 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbrdeci(int n, int count)
{
	if (n == -2147483648)
		count = ft_putstr("-2147483648");
	else if (n < 0)
	{
		count += ft_putchar('-');
		count = ft_putnbrdeci(-n, count);
	}
	else if (n >= 10)
	{
		count = ft_putnbrdeci(n / 10, count);
		count += ft_putchar(n % 10 + '0');
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_putnbrunsigned(unsigned int n, int count)
{
	if (n >= 10)
	{
		count = ft_putnbrdeci(n / 10, count);
		count += ft_putchar(n % 10 + '0');
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_putnbrhexa(unsigned int i, int count, int c)
{
	char	*set;

	if (c == 'x')
		set = "0123456789abcdef";
	if (c == 'X')
		set = "0123456789ABCDEF";
	if (i < 0)
	{
		count += ft_putchar('-');
		count = ft_putnbrhexa(-i, count, c);
	}
	else if (i >= 16)
	{
		count = ft_putnbrhexa(i / 16, count, c);
		count += ft_putchar(set[i % 16]);
	}
	else
		count += ft_putchar(set[i]);
	return (count);
}
