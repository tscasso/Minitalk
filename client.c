/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <tscasso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:08:46 by tscasso           #+#    #+#             */
/*   Updated: 2023/05/25 20:59:27 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_byte(int pid, int chr)
{
	int	mask;

	mask = 128;
	while (mask)
	{
		if (mask & chr)
		{
			if (kill(pid, SIGUSR1) == -1)
				handle_error("Signal error!");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				handle_error("Signal error!");
		}
		mask /= 2;
		usleep(2000);
	}
}

void	send_msg(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_byte(pid, msg[i]);
		usleep(2000);
		i++;
	}
	send_byte(pid, 0);
}

void	my_handler(int signum, siginfo_t *siginfo, void *ucontext)
{
	(void)siginfo;
	(void)ucontext;
	if (signum == SIGUSR2)
		ft_printf("Message received!\n");
}

int	main(int argc, char *argv[])
{
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = my_handler;
	if ((sigaction(SIGUSR2, &sig, 0)) == -1)
		handle_error("Signal error!");
	if ((sigaction(SIGUSR1, &sig, 0)) == -1)
		handle_error("Signal error!");
	if (argc == 3)
		send_msg(ft_atoi(argv[1]), argv[2]);
	else
		handle_error("error");
	return (0);
}
