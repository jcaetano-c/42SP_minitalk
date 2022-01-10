/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:07:42 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/10 16:32:26 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static void	print_error(void);

void	send_signals(char *message, int pid)
{
	int	i;
	int	shift;

	i = 0;
	while (message[i])
	{
		shift = 0;
		while (shift <= 7)
		{
			if (message[i] & 128 >> shift)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(5);
			++shift;
		}
		++i;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;

	if (argc != 3)
	{
		print_error();
	}
	pid = ft_atoi(argv[1]);
	if (!pid)
		print_error();
	send_signals(argv[2], pid);
	return (0);
}

static void	print_error(void)
{
	write(STDIN_FILENO, "client: invalid arguments\n", 27);
	write(1, "correct format: ./client <SERVER_PID> <MESSAGE>\n]", 50);
	exit(EXIT_FAILURE);
}
