/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triabulle1listA.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:59:32 by mafranco          #+#    #+#             */
/*   Updated: 2023/09/14 17:19:10 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	tri4a(t_list **lista, t_list **listb, t_nb4 n)
{
	if (n.i < n.j && n.i < n.k && n.i < n.l)
		push(lista, listb, 2, 1);
	if (n.j < n.i && n.j < n.k && n.j < n.l)
	{
		rotate(lista, listb, 1, 1);
		push(lista, listb, 2, 1);
		revrotate(lista, listb, 1, 1);
	}
	if (n.k < n.i && n.k < n.j && n.k < n.l)
	{
		rotate(lista, listb, 1, 2);
		push(lista, listb, 2, 1);
		revrotate(lista, listb, 1, 2);
	}
	if (n.l <  n.i && n.l < n.j && n.l < n.k)
	{
		rotate(lista, listb, 1, 3);
		push(lista, listb, 2, 1);
		revrotate(lista, listb, 1, 3);
	}
}

static void	tri3a(t_list **lista, t_list **listb)
{
	t_tmp3 cpy;

	cpy.tmp = *lista;
	cpy.tmp2 = cpy.tmp->next;
	cpy.tmp3 = cpy.tmp2->next;
	if (cpy.tmp2->nb > cpy.tmp3->nb && cpy.tmp2->nb > cpy.tmp->nb)
	{
		rotate(lista, listb, 1, 1);
		swap(lista, listb, 1);
		revrotate(lista, listb, 1, 1);
	}
	else if (cpy.tmp->nb > cpy.tmp3->nb && cpy.tmp->nb > cpy.tmp2->nb)
	{
		swap(lista, listb, 1);
		rotate(lista, listb, 1, 1);
		swap(lista, listb, 1);
		revrotate(lista, listb, 1, 1);
	}
	cpy.tmp = *lista;
	cpy.tmp2 = cpy.tmp->next;
	if (cpy.tmp->nb > cpy.tmp2->nb)
		swap(lista, listb, 1);
}

void	bullelista(t_list **lista, t_list **listb, t_nb4 n, int len)
{
	if (len == 4)
		tri4a(lista, listb, n);
	tri3a(lista, listb);
	if (len == 4)
		push(lista, listb, 1, 1);
}
