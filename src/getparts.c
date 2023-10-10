/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getparts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:23:12 by mafranco          #+#    #+#             */
/*   Updated: 2023/10/05 15:08:47 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*gettable(t_list **lista, int len)
{
	int		i;
	int		*table;
	t_list	*tmp;

	table = (int *)malloc(sizeof(int) * (len));
	if (!table)
		return (NULL);
	i = 0;
	tmp = *lista;
	while (tmp)
	{
		table[i] = tmp->nb;
		tmp = tmp->next;
		i++;
	}
	return (table);
}

void	sorttable(int *table, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		if (table[i] > table[i + 1])
		{
			j = table[i];
			table[i] = table[i + 1];
			table[i + 1] = j;
			i = 0;
		}
		else
			i++;
	}
}

int	*getparts(t_list **lista, int len)
{
	int	*t;

	t = gettable(lista, len);
	if (!t)
		return (0);
	sorttable(t, len);
	return (t);
}
