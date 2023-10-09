/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullestart5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:42:51 by mafranco          #+#    #+#             */
/*   Updated: 2023/10/09 10:24:14 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_nb5	init5(t_list **lista)
{
	t_nb5	n;
	t_tmp5	t;

	t.tmp = *lista;
	t.tmp2 = t.tmp->next;
	t.tmp3 = t.tmp2->next;
	t.tmp4 = t.tmp3->next;
	t.tmp5 = t.tmp4->next;
	n.i = t.tmp->nb;
	n.j = t.tmp2->nb;
	n.k = t.tmp3->nb;
	n.l = t.tmp4->nb;
	n.m = t.tmp5->nb;
	return (n);
}

int	put5frontstart(t_nb5 n, t_list **lista, t_list **listb)
{
	t_nb4	nb4;

	if (n.j < n.k && n.j < n.l && n.j < n.m && n.j < n.i)
		rotate(lista, listb, 1, 1);
	else if (n.k < n.j && n.k < n.l && n.k < n.m && n.k < n.i)
		rotate(lista, listb, 1, 2);
	else if (n.l < n.j && n.l < n.k && n.l < n.m && n.l < n.i)
		revrotate(lista, listb, 1, 2);
	else if (n.m < n.j && n.m < n.k && n.m < n.l && n.m < n.i)
		revrotate(lista, listb, 1, 1);
	push(lista, listb, 2, 1);
	nb4 = init4(lista);
	put4frontstart(nb4, lista, listb);
	push(lista, listb, 1, 1);
	return (0);
}

static int	test5(t_nb5 n, t_list **lista, t_list **listb)
{
	if (n.j < n.k && n.k < n.l && n.l < n.m && n.m < n.i)
		rotate(lista, listb, 1, 1);
	else if (n.i < n.j && n.k < n.l && n.l < n.m && n.m < n.i)
		rotate(lista, listb, 1, 2);
	else if (n.i < n.j && n.j < n.k && n.l < n.m && n.m < n.i)
		revrotate(lista, listb, 1, 2);
	else if (n.j < n.k && n.k < n.l && n.m < n.i && n.i < n.j)
		revrotate(lista, listb, 1, 1);
	else
		return (0);
	return (1);
}

void	bulle5(t_list **lista, t_list **listb)
{
	t_nb5	n;

	n = init5(lista);
	if (test5(n, lista, listb) == 1)
		return ;
	put5frontstart(n, lista, listb);
}
