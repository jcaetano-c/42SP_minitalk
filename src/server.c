/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:07:42 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/10 16:32:57 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

// server.c
void	handler_sigusr(int signum)
{
	static char	c = 255;
	static int	bits = 0;

	if (signum == SIGUSR2)
	{
		// write(STDIN_FILENO, "1", 1);
		c = c | (128 >> bits);
	}
	else if (signum == SIGUSR1)
	{
		// write(STDIN_FILENO, "0", 1);
		c = c ^ (128 >> bits);
	}
	++bits;
	if (bits == 8)
	{
		write(1, &c, 1);
		bits = 0;
		c = 255;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	s_signal;

	pid = getpid();
	s_signal.sa_handler = handler_sigusr;
	sigemptyset(&s_signal.sa_mask);
	s_signal.sa_flags = SA_RESTART;
	ft_put_pid(pid);
	sigaction(SIGUSR1, &s_signal, NULL);
	sigaction(SIGUSR2, &s_signal, NULL);
	while (1)
		pause();
}
