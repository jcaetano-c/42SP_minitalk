/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_ex.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 06:58:25 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/10 07:07:33 by jcaetano         ###   ########.fr       */
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

static void	handler(int signum)
{
	printf("\nNOPE\n");
}


int main()
{
	int					i;
	struct sigaction	sa_signal;

	sa_signal.sa_handler = handler;
	sigemptyset(&sa_signal.sa_mask);
	// Restart functions if interrupted by handler
	sa_signal.sa_flags = SA_RESTART;
	printf("HEY\n");
	i = 0;
	while (1)
	{
		printf("%d\n", ++i);
		/*
		sigaction(int sig, struct sigaction, struct sigaction oact);
		*/
		if (sigaction(SIGINT, &sa_signal, NULL) == -1)
			perror("ERRO.");
			usleep(0.2 * 1000000);
	}
}
