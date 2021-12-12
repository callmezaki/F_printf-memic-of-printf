/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:46:34 by zait-sli          #+#    #+#             */
/*   Updated: 2021/12/08 10:48:04 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	else
	{
		while (s[i] != '\0')
		{
			write (1, &s[i], 1);
			i++;
		}
	}
	return (i);
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	x(unsigned int n, char a)
{
	int		i;
	char	*base;

	i = 0;
	if (a == 'x')
		base = "0123456789abcdef";
	else if (a == 'X')
		base = "0123456789ABCDEF";
	if (n < 16)
	{
		ft_putchar(base[n]);
		i++;
	}
	else
	{
		i += x(n / 16, a);
		i += x(n % 16, a);
	}
	return (i);
}
