/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_ex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 07:50:51 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/05 20:43:13 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void	handler(int signal)
{
	if (signal == SIGINT)
		write(STDOUT_FILENO, "\nNOPE\n", 7);
	if (signal == SIGTERM)
	{
		write(STDOUT_FILENO, "\nTerminated\n", 13);
		exit(1);
	}
}

int	main(void)
{
	signal(SIGINT, handler);
	signal(SIGTERM, handler);
	while (1)
	{
		printf("Cycle. %d\n", getpid());
		sleep(1);
	}
}
