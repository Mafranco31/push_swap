/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triabulle1list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:05:04 by mafranco          #+#    #+#             */
/*   Updated: 2023/09/14 17:57:08 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	bulle3b(t_list **lista, t_list **listb)
{
	t_tmp3	cpy;

	cpy.tmp = *listb;
	cpy.tmp2 = cpy.tmp->next;
	cpy.tmp3 = cpy.tmp2->next;
	if (cpy.tmp2->nb < cpy.tmp3->nb && cpy.tmp2->nb < cpy.tmp->nb)
		revrotate(lista, listb, 2, 1);
	else if (cpy.tmp->nb < cpy.tmp2->nb && cpy.tmp->nb < cpy.tmp3->nb)
		rotate(lista, listb, 2, 1);
	cpy.tmp = *listb;
	cpy.tmp2 = cpy.tmp->next;
	if (cpy.tmp->nb < cpy.tmp2->nb)
		swap(lista, listb, 2);
	push(lista, listb, 1, 3);
}

static void	put4front(t_nb4 n, t_list **lista, t_list **listb)
{
	if (n.i > n.j && n.i > n.k && n.i > n.l)
		push(lista, listb, 1, 1);
	else if (n.j > n.i && n.j > n.k && n.j > n.l)
	{
		rotate(lista, listb, 2, 1);
		push(lista, listb, 1, 1);
	}
	else if (n.k > n.i && n.k > n.j && n.k > n.l)
	{
		rotate(lista, listb, 2, 2);
		push(lista, listb, 1, 1);
	}
	else if (n.l > n.i && n.l > n.j && n.l > n.k)
	{
		revrotate(lista, listb, 2, 1);
		push(lista, listb, 1, 1);
	}
	bulle3b(lista, listb);
}

static int	test4b(t_nb4 n, t_list **lista, t_list **listb)
{
	if (n.j > n.k && n.k > n.l && n.l > n.i)
	{
		rotate(lista, listb, 2, 1);
		return (1);
	}
	if (n.k > n.l && n.l > n.i && n.i > n.j)
	{
		rotate(lista, listb, 2, 2);
		return (1);
	}
	if (n.l > n.i && n.i > n.j && n.j > n.k)
	{
		revrotate(lista, listb, 2, 1);
		return (1);
	}
	return (0);
}

void	triabulle1list(t_list **lista, t_list **listb, int nblst, int len)
{
	t_nb4	n;

	if (checkbulle(lista, listb, nblst, len) == 1)
		return ;
	if (nblst == 1 && len == 4)
		n = init4(lista);
	else if (nblst == 2 && len == 4)
		n = init4(listb);
	if (nblst == 2 && len == 4)
	{
		if (test4b(n, lista, listb) == 1)
		{
			push(lista, listb, 1, 4);
			return ;
		}
		put4front(n, lista, listb);
	}
	else if (nblst == 2 && len == 3)
		bulle3b(lista, listb);
	else
		bullelista(lista, listb, n, len);
}
