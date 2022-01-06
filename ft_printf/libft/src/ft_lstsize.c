/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:13:26 by jcaetano          #+#    #+#             */
/*   Updated: 2021/09/21 17:20:27 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*i;
	size_t	length;

	i = lst;
	if (!i)
		return (0);
	else
	{
		length = 0;
		while (i)
		{
			i = i->next;
			length++;
		}
	}
	return (length);
}
