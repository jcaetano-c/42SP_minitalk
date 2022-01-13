/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:07:42 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/13 04:02:52 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_status;

static void	print_error(void);
static void	handler_sigusr(int signum);
static void	send_signals(char *str, int pid);

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	s_signal;

	g_status = 1;
	if (argc != 3)
	{
		print_error();
	}
	pid = ft_atoi(argv[1]);
	if (!pid)
		print_error();
	sigemptyset(&s_signal.sa_mask);
	s_signal.sa_handler = handler_sigusr;
	s_signal.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &s_signal, NULL);
	send_signals(argv[2], pid);
	return (0);
}

static void	send_signals(char *str, int pid)
{
	int	i;
	int	shift;

	if (g_status)
	{
		i = 0;
		while (str[i])
		{
			shift = 0;
			while (shift <= 7)
			{
				if (str[i] & 128 >> shift)
					kill(pid, SIGUSR2);
				else
					kill(pid, SIGUSR1);
				g_status = 0;
				usleep(0.09 * 1000000);
				++shift;
			}
			++i;
		}
	}
}

static void	handler_sigusr(int signum)
{
	g_status = 1;
	signum = (int)signum;
}

static void	print_error(void)
{
	write(STDIN_FILENO, "bclient: invalid arguments\n", 27);
	write(1, "correct format: ./client <SERVER_PID> <MESSAGE>\n]", 50);
	exit(EXIT_FAILURE);
}
