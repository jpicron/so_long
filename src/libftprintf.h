/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <jpicron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:02:48 by jpicron           #+#    #+#             */
/*   Updated: 2022/10/06 19:47:45 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbrdeci(int n, int count);
int	ft_putnbrunsigned(unsigned int n, int count);
int	ft_putnbrhexa(unsigned int i, int count, int c);
int	ft_iswhatpercent(char c, va_list args);
int	ft_printf(const char *toprint, ...);
int	ft_putpoint(unsigned long long adresse, int count);
#endif