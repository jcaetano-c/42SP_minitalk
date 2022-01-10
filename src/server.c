/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:07:42 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/08 23:04:16 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_usr1(int sig)
{
	write(1, "USR1 Recebido\n", 15);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_put_pid(pid);
	write(1, "\nEsperando sinal do sistema\n", 29);
	signal(SIGBUS, handler_usr1);
	while (1)
	{
		sleep(1);
	}
}
