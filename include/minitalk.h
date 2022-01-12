/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:36:08 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/12 10:50:14 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include <stdlib.h>

extern int		g_status;
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
void	ft_put_pid(int pid);
size_t	ft_strlen(const char *str);

#endif
