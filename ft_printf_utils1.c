/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:46:26 by zait-sli          #+#    #+#             */
/*   Updated: 2021/12/08 10:47:45 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * -1);
	}
	else if (n < 10)
	{
		ft_putchar(n + '0');
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	return (count_nbr(n));
}

int	count_nbr(long long nbr)
{
	int	count;

	count = 0;
	if (nbr <= 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

int	ft_unsigned(long long nbr)
{
	int	len;

	if (nbr < 0)
	{
		nbr = 4294967295 + nbr + 1;
		len = count_nbr(nbr);
		ft_putnbr(nbr);
	}
	else
	{
		ft_putnbr(nbr);
		len = count_nbr(nbr);
	}
	return (len);
}

int	x_forp(unsigned long n, char a)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (n < 16)
	{
		ft_putchar(base[n]);
		i++;
	}
	else
	{
		i += x_forp(n / 16, a);
		i += x_forp(n % 16, a);
	}
	return (i);
}

int	ft_p(unsigned long long n)
{
	int	len;

	len = ft_putstr("0x");
	len += x_forp(n, 'x');
	return (len);
}
