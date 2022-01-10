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
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define _XOPEN_SOURCE 700

void	handler(int signum)
{
	if (signum == SIGINT)
		printf("CONTROL");
}

int	main(void)
{
	int					i;
	struct sigaction	s_sa;

	s_sa.sa_handler = handler;
	printf("Hello\n");
	while (1)
	{
		printf("/");
		sleep(1);
		if(sigaction(SIGINT, &s_sa, NULL) == -1)
			perror("SIGACTION");
		else
			printf("OK.");
	}
	return (0);
}
