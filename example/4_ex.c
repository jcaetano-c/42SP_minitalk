/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ex.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 07:04:11 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/06 11:12:41 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

pid_t	g_mypid;

void	usr1a(int sig);
void	usr1b(int sig);

int	main(void)
/*	SVR4 Signal improvements generated, delivered, pending, blocked
	the value of the function can be SIG_DFL - default or
	SIG_IGN - ignore this signal
*/
{
	g_mypid = getpid();
	sigset(SIGINT, SIG_IGN);
	sigset(SIGUSR1, usr1a);
	printf("Running as %d, hit me wtith an INT or USR1\n", g_mypid);
	while (1)
	{
		;
	}
}

void	usr1a(int sig)
{
	sighold(sig);
	printf ("in usr1a, let's put a few sigusr1s in the queue\n");
	kill (g_mypid, SIGUSR1);
	kill (g_mypid, SIGUSR1);
	kill (g_mypid, SIGUSR1);
	printf("Put three SIGUSR1 out.  Resetting the handler to usr1b\n");
	sigset (SIGUSR1, usr1b);
	sigrelse(sig);
	printf("all done with usr1a\n");
}

void	usr1(int sig)
{
	static int	count;

	count = 0;
	printf ("in usr1b, count = %d \n", count++);
}
