/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortina.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:10:26 by mafranco          #+#    #+#             */
/*   Updated: 2023/10/09 10:13:19 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sortinadown(t_table *t, int i, t_list **lista, t_list **listb)
{
	t_list	*tmp;
	int		k;

	k = 0;
	tmp = *listb;
	while (k < t->len && tmp->nb != t->table[i])
	{
		k++;
		t->restdown--;
		t->restup++;
		rotate(lista, listb, 2, 1);
		tmp = *listb;
	}
	push(lista, listb, 1, 1);
	t->restdown--;
}

static void	sortinaup(t_table *t, int i, t_list **lista, t_list **listb)
{
	t_list	*tmp;
	int		k;

	k = 0;
	tmp = *listb;
	while (k < t->len && tmp->nb != t->table[i])
	{
		k++;
		t->restup--;
		t->restdown++;
		revrotate(lista, listb, 2, 1);
		tmp = *listb;
	}
	push(lista, listb, 1, 1);
	t->restdown--;
}

static int	searchnb(t_table *t, int nb, t_list **listb)
{
	t_list	*tmp;
	int		j;

	j = 0;
	tmp = *listb;
	while (j < t->len && tmp->nb != t->table[nb])
	{
		j++;
		tmp = tmp->next;
	}
	if (j > ft_lstsize(*listb) / 2)
		return (1);
	return (0);
}

void	sortina1(t_table *t, t_list **lista, t_list **listb)
{
	int	j;

	t->len--;
	while (t->len > 0)
	{
		j = searchnb(t, t->len, listb);
		if (j == 0)
			sortinadown(t, t->len, lista, listb);
		else
			sortinaup(t, t->len, lista, listb);
		t->len--;
	}
	push(lista, listb, 1, 1);
}
