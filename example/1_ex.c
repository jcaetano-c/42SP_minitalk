/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_ex.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 07:04:11 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/10 12:31:14 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void	handle_signal(int signal);
void	end_pid(int signal);
void	restart_num(int num);

int	g_num = 0;

int	main(void)
/*
**	signal()
		1º par: int positivo que representa o número do sinal
		2º par: função a ser executada quando esse sinal for chamado;
	getpid()
		retorna o PID da execução
	sleep (3)
		faz o programa "dormir" por 3s
	kill -sig pid
		-sig: o numero do int atribuido ao signal()
		pid: o valor retornado pelo getpid()

	CTRL+	C = SIGINT
		+	S = SIGSTOP
		+	Q = SIGCONT
*/

{
	int	pid;
	int	time;

	signal(SIGTERM, handle_signal);
	signal(SIGINT, handle_signal);
	signal(SIGUSR1, handle_signal);
	pid = getpid();
	printf("PID = %d\n", pid);
	while (1)
	{
		printf("g_num = %d\n", g_num);
		g_num++;
		if (g_num > 50)
			kill(pid, SIGTERM);
		time = 0.5 * 1000000;
		usleep(time);
	}
}

void	handle_signal(int signal)
{
	if (signal == SIGTERM)
		end_pid(signal);
	else if (signal == SIGINT)
		write(STDOUT_FILENO, "\nNOPE\n", 7);
	else
		restart_num(signal);
}

void	end_pid(int signal)
{
	write(STDOUT_FILENO, "Encerrando a execução...\n", 28);
	exit(SIGTERM);
}

void	restart_num(int signal)
{
	g_num = 0;
}
