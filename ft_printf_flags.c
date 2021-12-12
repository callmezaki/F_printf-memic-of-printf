/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:12:35 by zait-sli          #+#    #+#             */
/*   Updated: 2021/12/07 12:39:26 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_ps(const char *format, int a)
{
	int	k;

	k = 0;
	while (format[a] != '%')
	{
		if (format[a] == '+')
			return (ft_putchar('+'));
		else if (format[a] == ' ')
			k = 1;
		a--;
	}
	if (k == 1)
		return (ft_putchar(' '));
	return (0);
}

int	check_hash_x(const char *format, int a)
{
	while (format[a] != '%')
	{
		if (format[a] == '#')
			return (ft_putstr("0x"));
		a--;
	}
	return (0);
}

int	check_hash_upx(const char *format, int a)
{
	while (format[a] != '%')
	{
		if (format[a] == '#')
			return (ft_putstr("0X"));
		a--;
	}
	return (0);
}
