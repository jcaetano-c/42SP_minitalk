/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ex.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 07:04:11 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/06 10:50:20 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void	catch_int(int sig_num)
{
	signal(SIGINT, catch_int);
	printf(" Don't do that\n");
	fflush(stdout);
}

int	main(int argc, char *argv[])
/*
*	pause()
*		pausa o processo até que um sinal seja recebido
*/
{
	signal(SIGINT, catch_int);
	while (1)
		pause();
}
