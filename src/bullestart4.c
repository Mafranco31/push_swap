/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bulle4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:13:10 by mafranco          #+#    #+#             */
/*   Updated: 2023/09/15 10:28:36 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_nb4	init4(t_list **lista)
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

int	put4frontstart(t_nb4 n, t_list **lista, t_list **listb)
{
	if (n.j < n.i && n.j < n.k && n.j < n.l)
		rotate(lista, listb, 1, 1);
	else if (n.k < n.i && n.k < n.j && n.k < n.l)
		rotate(lista, listb, 1, 2);
	else if (n.l < n.i && n.l < n.j && n.l < n.k)
		revrotate(lista, listb, 1, 1);
	push(lista, listb, 2, 1);
	bulle3(lista, listb);
	push(lista, listb, 1, 1);
	return (0);
}

static int	test4(t_nb4 n, t_list **lista, t_list **listb)
{
	if (n.l < n.i && n.j < n.k && n.k < n.l)
		rotate(lista, listb, 1, 1);
	else if (n.l < n.i && n.i < n.j && n.k < n.l)
		rotate(lista, listb, 1, 2);
	else if (n.l < n.i && n.i < n.j && n.j < n.k)
		revrotate(lista, listb, 1, 1);
	else
		return (0);
	return (1);
}

void	bulle4(t_list **lista, t_list **listb)
{
	t_nb4	n;

	n = init4(lista);
	if (test4(n, lista, listb) == 1)
		return ;
	put4frontstart(n, lista, listb);
}
