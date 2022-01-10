/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:07:42 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/10 08:42:19 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

// server.c
void	handler_sigusr2(int signum)
{
	(void)signum;
	write(STDIN_FILENO, "0", 1);
}

void	handler_sigusr1(int signum)
{
	(void)signum;
	write(STDIN_FILENO, "1", 1);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_put_pid(pid);
	signal(SIGUSR1, handler_sigusr1);
	signal(SIGUSR2, handler_sigusr2);
	while (1)
		pause();
}
