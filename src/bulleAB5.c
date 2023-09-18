/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bulleAB5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:51:25 by mafranco          #+#    #+#             */
/*   Updated: 2023/09/15 12:50:14 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	put5frontb(t_list **lista, t_list **listb, t_nb5 n)
{
	t_nb4	nb4;

	if (n.j > n.k && n.j > n.l && n.j > n.m && n.j > n.i)
		rotate(lista, listb, 2, 1);
	else if (n.k > n.j && n.k > n.l && n.k > n.m && n.k > n.i)
		rotate(lista, listb, 2, 2);
	else if (n.l > n.j && n.l > n.k && n.l > n.m && n.l > n.i)
		revrotate(lista, listb, 2, 2);
	else if (n.m > n.j && n.m > n.k && n.m > n.l && n.m > n.i)
		revrotate(lista, listb, 2, 1);
	push(lista, listb, 1, 1);
	nb4 = init4(listb);
	put4front(nb4, lista, listb);
}

int	tri5(t_list **lista, t_list **listb, int nblst)
{
	t_nb5	n;

	if (nblst == 1)
		n = init5(lista);
	if (nblst == 2)
		n = init5(listb);
	if (nblst == 2)
		put5frontb(lista, listb, n);
	return (0);
}
