/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortinb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:39:57 by mafranco          #+#    #+#             */
/*   Updated: 2023/10/09 10:05:54 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sortinb2(int nb, t_list **lista, t_list **listb)
{
	t_list	*tmp;

	tmp = *listb;
	if (tmp->nb <= nb)
		rotate(lista, listb, 2, 1);
}

void	sortinb1(t_table *t, t_list **lista, t_list **listb)
{
	int		i;
	int		count;
	t_list	*tmp;

	i = 1;
	while (i < t->parts)
	{
		count = 0;
		while (count < t->size)
		{
			tmp = *lista;
			if (tmp->nb < t->table[i * t->size])
			{
				push(lista, listb, 2, 1);
				sortinb2(t->table[i * t->size] - (t->size / 2), lista, listb);
				count++;
			}
			else
				rotate(lista, listb, 1, 1);
		}
		i++;
	}
	push(lista, listb, 2, t->lastsize);
}
