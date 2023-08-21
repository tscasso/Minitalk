/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <tscasso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:09:03 by tscasso           #+#    #+#             */
/*   Updated: 2023/05/25 22:08:23 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	my_handler(int signum, siginfo_t *siginfo, void *ucontext)
{
	static int	out_char;
	static int	mask = 128;

	if (!out_char)
		out_char = 0;
	(void)ucontext;
	if (signum == SIGUSR1)
		out_char |= mask;
	mask /= 2;
	if (mask == 0)
	{
		if (out_char == 0)
		{
			if (kill(siginfo->si_pid, SIGUSR2) == -1)
				handle_error("Signal error!");
			ft_printf("\n");
		}
		else
			ft_printf("%c", out_char);
		out_char = 0;
		mask = 128;
	}
	if (kill(siginfo->si_pid, SIGUSR1) == -1)
		handle_error("Signal error!");
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("Serveur PID: %d\n", getpid());
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = my_handler;
	if ((sigaction(SIGUSR1, &sig, 0)) == -1)
		handle_error("Signal error!");
	if ((sigaction(SIGUSR2, &sig, 0)) == -1)
		handle_error("Signal error!");
	while (1)
		pause();
	return (0);
}
