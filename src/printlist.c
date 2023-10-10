/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:21:49 by mafranco          #+#    #+#             */
/*   Updated: 2023/09/11 17:05:11 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	printnbr(char *nb)
{
	int	i;

	i = 0;
	while (nb[i])
	{
		write(1, &nb[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return ;
}

int	printlist(int argc, t_list *list)
{
	int		i;
	char	*p;

	i = 0;
	if (!list)
		return (0);
	while (list->next != NULL)
	{
		p = ft_itoa(list->nb);
		printnbr(p);
		free(p);
		list = list->next;
		i++;
	}
	p = ft_itoa(list->nb);
	printnbr(p);
	free(p);
	i++;
	if (i != argc)
		return (argc);
	return (i);
}
