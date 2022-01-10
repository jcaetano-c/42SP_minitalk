/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:07:42 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/10 08:58:17 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	send_signals(char *message, int pid)
{
	int	i;
	int	shift;

	i = 0;
	while (message[i])
	{
		shift = -1;
		write(1, &message[i], 1);
		write(1, "\n", 2);
		while (++shift < 8)
		{
			if (message[i] & 0x80 >> shift)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(3);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;

	if (argc != 3)
	{
		write(STDIN_FILENO, "client: invalid arguments\n", 27);
		write(1, "correct format: ./client <SERVER_PID> <MESSAGE>\n]", 50);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	send_signals(argv[2], pid);
	return (0);
}
