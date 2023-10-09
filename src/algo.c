/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:47:24 by mafranco          #+#    #+#             */
/*   Updated: 2023/10/09 10:15:04 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	getsizeparts(int len)
{
	if (len < 12)
		return (len / 2);
	if (len < 50)
		return (len / 4);
	if (len < 100)
		return (len / 5);
	if (len == 100)
		return (22);
	if (len < 300)
		return (len / 6);
	if (len < 500)
		return (len / 8);
	if (len == 500)
		return (60);
	return (len / 10);
}

void	initdatatable(t_table *t, int len)
{
	int	size;

	size = getsizeparts(len);
	t->len = len;
	t->size = size;
	t->parts = 1 + (len / size);
	if (len % size == 0)
	{
		t->lastsize = size;
		t->parts--;
	}
	else
		t->lastsize = len % size;
	t->restup = 0;
	t->restdown = t->lastsize;
}

int	algo(t_list **lista, t_list **listb)
{
	int		len;
	t_table	t;

	len = ft_lstsize(*lista);
	if (len < 6)
		return (triabulle(lista, listb, len));
	t.table = getparts(lista, len);
	initdatatable(&t, len);
	sortinb1(&t, lista, listb);
	sortina1(&t, lista, listb);
	free(t.table);
	return (0);
}
