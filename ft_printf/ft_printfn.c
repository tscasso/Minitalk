/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:54:52 by tscasso           #+#    #+#             */
/*   Updated: 2023/04/20 14:55:07 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	unsigned int	length;

	length = 1;
	write(1, &c, length);
	return (length);
}

int	ft_putstr(char *str)
{
	unsigned int	length;
	unsigned int	i;

	i = 0;
	length = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		length += ft_putchar(str[i]);
		i++;
	}
	return (length);
}

int	ft_puthexanbr(unsigned int n, char c, int length)
{
	char	*base;

	base = "0123456789abcdef";
	if (n > 15)
	{
		length += ft_puthexanbr(n / 16, c, 0);
		length += ft_puthexanbr(n % 16, c, 0);
	}
	if (n <= 15)
	{
		if (n > 9 && c == 'X')
			length += ft_putchar(base[n] - 32);
		else
			length += ft_putchar(base[n]);
	}
	return (length);
}

int	ft_putlonghexanbr(long unsigned n, int length)
{
	char	*base;

	base = "0123456789abcdef";
	if (n > 15)
	{
		length += ft_putlonghexanbr(n / 16, 0);
		length += ft_putlonghexanbr(n % 16, 0);
	}
	if (n <= 15)
	{
		length += ft_putchar(base[n]);
	}
	return (length);
}

int	ft_putlongnbr(long int n, int length)
{
	if (n < 0)
	{
		length = ft_putchar('-');
		n = -n;
	}
	if (n >= 0 && n <= 9)
	{	
		length += ft_putchar(n + '0');
	}
	if (n > 9)
	{
		length += ft_putlongnbr(n / 10, 0);
		length += ft_putlongnbr(n % 10, 0);
	}
	return (length);
}
