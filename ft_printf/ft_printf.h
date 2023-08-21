/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:01:28 by jlefevre          #+#    #+#             */
/*   Updated: 2023/04/20 15:01:32 by jlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_puthexanbr(unsigned int n, char car, int length);
int	ft_putlongnbr(long int n, int length);
int	check_arg_dec(const char str, va_list arg);
int	check_arg_int(const char str, va_list arg);
int	check_arg(const char str, va_list arg);
int	check_str(const char *str, va_list arg);
int	ft_printf(const char *format, ...);
int	ft_putlonghexanbr(long unsigned n, int length);

#endif
