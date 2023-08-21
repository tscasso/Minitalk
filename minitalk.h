/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <tscasso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:09:07 by tscasso           #+#    #+#             */
/*   Updated: 2023/05/25 18:30:58 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define MAX_PID 99998

void	handle_error(char *s);
int		ft_atoi(const char *str);

#endif
