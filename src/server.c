/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:07:42 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/14 13:19:17 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler_sigusr(int signum, siginfo_t *info, void *context);

int	main(void)
{
	pid_t				pid;
	struct sigaction	s_signal;

	pid = getpid();
	sigemptyset(&s_signal.sa_mask);
	s_signal.sa_handler = (void *)handler_sigusr;
	s_signal.sa_flags = SA_SIGINFO | SA_RESTART;
	ft_put_pid(pid);
	sigaction(SIGUSR1, &s_signal, NULL);
	sigaction(SIGUSR2, &s_signal, NULL);
	while (1)
		pause();
}

static void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	static int	c = 255;
	static int	bits = 0;

	context = (void *)context;
	if (signum == SIGUSR2)
		c = c | (128 >> bits);
	else if (signum == SIGUSR1)
		c = c ^ (128 >> bits);
	++bits;
	if (bits == 8)
	{
		write(1, &c, 1);
		bits = 0;
		c = 255;
	}
	kill(info->si_pid, SIGUSR1);
}
