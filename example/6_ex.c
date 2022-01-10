/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_ex.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 07:04:11 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/09 00:04:41 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int	main(void)
{
	pid_t	pid;
	char	c;

	c = 'a';
	pid = fork();
	if ((pid) < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
		//O código aqui dentro será executado no processo filho
		printf("pid do Filho: %d\n", getpid());
		printf("FILHO: c = %c | &c = %p\n", c, &c);
	}
	else
	{
		//O código neste trecho será executado no processo pai
		printf("pid do Pai: %d\n", getpid());
		c = 'b';
		printf("PAI: c = %c | &c = %p\n", c, &c);
	}
	printf("Esta regiao sera executada por ambos processos\n\n");
	exit(0);
}
