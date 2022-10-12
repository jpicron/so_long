/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <jpicron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:41:40 by jpicron           #+#    #+#             */
/*   Updated: 2022/10/06 21:22:37 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_iswhatpercent(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar((char)va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		count += ft_putpoint(va_arg(args, unsigned long long int), 0);
	else if (c == 'd' || c == 'i')
		count += ft_putnbrdeci(va_arg(args, int), 0);
	else if (c == 'u')
		count += ft_putnbrunsigned(va_arg(args, unsigned int), 0);
	else if (c == 'x' || c == 'X')
		count += ft_putnbrhexa(va_arg(args, unsigned int), 0, c);
	else if (c == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *toprint, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, toprint);
	i = 0;
	count = 0;
	while (toprint[i] != '\0')
	{
		if (toprint[i] == '%')
		{
			count += ft_iswhatpercent(toprint[i + 1], args);
			i++;
		}
		else
			count += write(1, &toprint[i], 1);
		i++;
	}
	return (count);
}
