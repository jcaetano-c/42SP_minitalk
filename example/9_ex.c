/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_ex.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 06:58:25 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/10 13:39:53 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>

#define _XOPEN_SOURCE 700

void	handler_sigusr1(int signum)
{
	write(1, "HINT.\n", 7);
}

int	main(int argc, char *argv[])
{
	int					pid;
	int					x;
	struct sigaction	s_sa;

	pid = fork();
	if (pid == -1)
	{
		return (1);
	}
	if (pid == 0)
	{
		sleep(5);
		write(1, "hey", 3);
		kill(getpid(), SIGUSR1);
	}
	else
	{
		//como estamos usando scanf, é necessário reinicar a cada execução
		s_sa.sa_flags = SA_RESTART;
		s_sa.sa_handler = &handler_sigusr1;
		sigaction(SIGUSR1, &s_sa, NULL);
		printf("3x5: ");
		scanf("%d", &x);
		if (x == 15)
			printf("OK.\n");
		else
			printf("KO\n");
		wait(NULL);
	}
	return (0);
}
