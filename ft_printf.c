/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:45:40 by zait-sli          #+#    #+#             */
/*   Updated: 2021/12/12 19:25:55 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flag(const char *format, int a, va_list ap)
{
	if ((format[a] == 'd' || format[a] == 'i' ) && va_arg(ap, int) >= 0)
	{
		return (check_ps(format, a));
	}
	if (format[a] == 'x' && va_arg(ap, int) != 0)
	{
		return (check_hash_x(format, a));
	}
	if (format[a] == 'X' && va_arg(ap, int) != 0)
	{
		return (check_hash_upx(format, a));
	}
	return (0);
}

int	ft_isprint(int c)
{
	if (c != 'c' && c != 's' && c != 'd' && c != '%'
		&& c != 'u' && c != 'x' && c != 'p' && c != 'X' && c != 'i')
		return (1);
	else
		return (0);
}

int	ft_convert(char a, va_list ap)
{
	if (a == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (a == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (a == 'd' || a == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (a == '%')
		return (ft_putchar('%'));
	else if (a == 'u')
		return (ft_unsigned(va_arg(ap, int)));
	else if (a == 'x' || a == 'X')
		return (x(va_arg(ap, unsigned int), a));
	else if (a == 'p')
		return (ft_p(va_arg(ap, unsigned long long)));
	return (ft_putchar(a));
}

int	treat_specifier(const char *format, int i, va_list ap)
{
	int		count;
	va_list	temp;

	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while ((format[i] == '#' || format[i] == '+'
					|| format[i] == ' ' || ft_isprint(format[i])) && format[i])
				i++;
			va_copy(temp, ap);
			count += check_flag(format, i, temp);
			count += ft_convert(format[i], ap);
			i++;
		}
		else if (format[i])
		{
			i += ft_putchar(format[i]);
			count++;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;	
	va_list	ap;

	va_start(ap, format);
	i = 0;
	count = 0;
	count = treat_specifier(format, i, ap);
	va_end(ap);
	return (count);
}