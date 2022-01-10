/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ex.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 07:04:11 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/07 11:03:23 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int	main(int argc, char *argv[])
{
	pid_t				pid;

	pid = fork();
	printf("pid: %d\n", pid);
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		while (1)
		{
			printf("Hello world.\n");
			usleep(300000);
		}
	}
	else
	{
		printf("pid: %d\n", pid);
		// sleep(1);
		// kill(pid, SIGKILL);
		wait(NULL);
	}
	return (0);
}
