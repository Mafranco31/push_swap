/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bulleA.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:59:32 by mafranco          #+#    #+#             */
/*   Updated: 2023/09/18 11:49:30 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	tri5a(t_list **lista, t_list **listb, t_nb5 n, int i)
{
	if (n.i < n.j && n.i < n.k && n.i < n.l && n.i < n.m)
		push(lista, listb, 2, 1);
	else
	{
		if (n.j < n.i && n.j < n.k && n.j < n.l && n.j < n.m)
			i = 1;
		if (n.k < n.i && n.k < n.j && n.k < n.l && n.k < n.m)
			i = 2;
		if (n.l < n.i && n.l < n.j && n.l < n.k && n.l < n.m)
			i = 3;
		if (n.m < n.i && n.m < n.j && n.m < n.k && n.m < n.l)
			i = 4;
		rotate(lista, listb, 1, i);
		push(lista, listb, 2, 1);
		revrotate(lista, listb, 1, i);
	}
}

static void	tri4a(t_list **lista, t_list **listb, t_nb4 n)
{
	if (n.i < n.j && n.i < n.k && n.i < n.l)
		push(lista, listb, 2, 1);
	else if (n.j < n.i && n.j < n.k && n.j < n.l)
	{
		rotate(lista, listb, 1, 1);
		push(lista, listb, 2, 1);
		revrotate(lista, listb, 1, 1);
	}
	else if (n.k < n.i && n.k < n.j && n.k < n.l)
	{
		rotate(lista, listb, 1, 2);
		push(lista, listb, 2, 1);
		revrotate(lista, listb, 1, 2);
	}
	else if (n.l < n.i && n.l < n.j && n.l < n.k)
	{
		rotate(lista, listb, 1, 3);
		push(lista, listb, 2, 1);
		revrotate(lista, listb, 1, 3);
	}
}

static void	tri3a(t_list **lista, t_list **listb)
{
	t_tmp3	cpy;

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
	t_nb5	nb5;

	nb5 = init5(lista);
	if (len == 5)
		tri5a(lista, listb, nb5, 0);
	if (len == 4)
		tri4a(lista, listb, n);
	tri3a(lista, listb);
	if (len == 4)
		push(lista, listb, 1, 1);
	if (len == 5)
		push(lista, listb, 1, 1);
}
