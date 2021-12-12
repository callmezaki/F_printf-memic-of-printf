/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:23:21 by zait-sli          #+#    #+#             */
/*   Updated: 2021/12/08 17:22:20 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<unistd.h>
# include <stdarg.h>

int		ft_putnbr(long long n);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		count_nbr(long long nbr);
int		ft_unsigned(long long nbr);
int		x(unsigned int n, char a);
int		ft_p(unsigned long long n);
int		x_forp(unsigned long n, char a);
int		ft_printf(const char *format, ...);
int		check_ps(const char *format, int a);
int		check_flag(const char *format, int a, va_list ap);
int		check_hash_x(const char *format, int a);
int		check_hash_upx(const char *format, int a);

#endif