/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_ex.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 07:04:11 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/09 21:21:39 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
// #include <sys/wait.h>
// #include <stdlib.h>
// #include <errno.h>

#define _XOPEN_SOURCE 700

void	handler(int signum)
{
	if (signum == SIGINT)
		perror("CONTROL");
}

int	main(void)
{
	int					i;
	struct sigaction	sa_signal;

	sa_signal.sa_handler = handler;
	printf("Hello\n");
	i = sigaction(SIGINT, &sa_signal, NULL);
	printf("i = %d\n", i);
	while (1)
	{
		perror("/");
		sleep(1);
		if( i == -1)
			perror("SIGACTION");
	}
	return (0);
}
