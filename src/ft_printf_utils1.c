/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <jpicron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:48:20 by jpicron           #+#    #+#             */
/*   Updated: 2022/10/06 21:18:03 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		count = write(1, "(null)", 6);
	else
	{
		while (str[count] != '\0')
		{
			count += ft_putchar(str[count]);
		}
	}
	return (count);
}

int	ft_putpoint(unsigned long long int adresse, int count)
{
	char	*set;

	set = "0123456789abcdef";
	if (count == 0)
		count += ft_putstr("0x");
	if (adresse < 0)
	{
		count += ft_putchar('-');
		count = ft_putpoint(-adresse, count);
	}
	else if (adresse >= 16)
	{
		count = ft_putpoint(adresse / 16, count);
		count += ft_putchar(set[adresse % 16]);
	}
	else
		count += ft_putchar(set[adresse]);
	return (count);
}
