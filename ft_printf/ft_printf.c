/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <marvin@42.fr>                    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:40:07 by tscasso           #+#    #+#             */
/*   Updated: 2023/04/20 14:40:19 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_arg_dec(const char str, va_list arg)
{
	int				length;
	long unsigned	mem;

	length = 0;
	mem = 0;
	if (str == 'x')
		length = ft_puthexanbr(va_arg(arg, unsigned int), 'x', 0);
	else if (str == 'X')
		length = ft_puthexanbr(va_arg(arg, unsigned int), 'X', 0);
	else if (str == 'p')
	{
		mem = va_arg(arg, long unsigned);
		if (mem == 0)
		{	
			length += ft_putstr("(nil)");
		}
		else
		{
			length += ft_putstr("0x");
			length += ft_putlonghexanbr(mem, 0);
		}
	}
	return (length);
}

int	check_arg_int(const char str, va_list arg)
{
	int	length;

	length = 0;
	if (str == 'd' || str == 'i')
		length = ft_putlongnbr(va_arg(arg, int), 0);
	else if (str == 'u')
		length = ft_putlongnbr(va_arg(arg, unsigned int), 0);
	return (length);
}

int	check_arg(const char str, va_list arg)
{
	int	length;

	length = 0;
	if (str == 'c')
		length = ft_putchar(va_arg(arg, int));
	else if (str == 's')
		length = ft_putstr(va_arg(arg, char *));
	else if (str == 'd' || str == 'i' || str == 'u')
		length = check_arg_int(str, arg);
	else if (str == 'x' || str == 'X' || str == 'p')
		length = check_arg_dec(str, arg);
	else
	{
		if (str == '%')
			length = ft_putchar('%');
		else
			length = ft_putchar(str);
	}
	return (length);
}

int	check_str(const char *str, va_list arg)
{
	unsigned int	i;
	unsigned int	length;

	i = 0;
	length = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += check_arg(str[i + 1], arg);
			i++;
		}
		else
			length += ft_putchar(str[i]);
		i++;
	}
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		length;

	if (!format || !*format)
		return (0);
	va_start(arg, format);
	length = check_str((const char *)format, arg);
	va_end(arg);
	return (length);
}
