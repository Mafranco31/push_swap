/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bulle4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:13:10 by mafranco          #+#    #+#             */
/*   Updated: 2023/09/14 14:56:10 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_nb4	init4(t_list **lista)
{
	t_nb4	n;
	t_tmp4	tmp;

	tmp.tmp = *lista;
	tmp.tmp2 = tmp.tmp->next;
	tmp.tmp3 = tmp.tmp2->next;
	tmp.tmp4 = tmp.tmp3->next;
	n.i = tmp.tmp->nb;
	n.j = tmp.tmp2->nb;
	n.k = tmp.tmp3->nb;
	n.l = tmp.tmp4->nb;
	return (n);
}

static int	put1front(t_nb4 n, t_list **lista, t_list **listb)
{
	if (n.i < n.j && n.i < n.k && n.i < n.l)
		push(lista, listb, 2, 1);
	else if (n.j < n.i && n.j < n.k && n.j < n.l)
	{
		rotate(lista, listb, 1, 1);
		push(lista, listb, 2, 1);
	}
	else if (n.k < n.i && n.k < n.j && n.k < n.l)
	{
		rotate(lista, listb, 1, 2);
		push(lista, listb, 2, 1);
	}
	else if (n.l < n.i && n.l < n.j && n.l < n.k)
	{
		revrotate(lista, listb, 1, 1);
		push(lista, listb, 2, 1);
	}
	bulle3(lista, listb);
	push(lista, listb, 1, 1);
	return (0);
}

static int	testb4(t_nb4 n, t_list **lista, t_list **listb)
{
	if (n.l < n.i && n.j < n.k && n.k < n.l)
	{
		rotate(lista, listb, 1, 1);
		return (1);
	}
	else if (n.l < n.i && n.i < n.j && n.k < n.l)
	{
		rotate(lista, listb, 1, 2);
		return (1);
	}
	else if (n.l < n.i && n.i < n.j && n.j < n.k)
	{
		revrotate(lista, listb, 1, 1);
		return (1);
	}
	return (0);
}

void	bulle4(t_list **lista, t_list **listb)
{
	t_nb4	n;

	n = init4(lista);
	if (testb4(n, lista, listb) == 1)
		return ;
	put1front(n, lista, listb);
}
