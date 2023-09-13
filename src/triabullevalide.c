/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triabullevalide.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:50:28 by mafranco          #+#    #+#             */
/*   Updated: 2023/09/13 12:17:31 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	suite(t_list **lista, t_list **listb)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;

	tmp = *listb;
	tmp2 = tmp->next;
	tmp3 = tmp2->next;
	if (tmp2->nb < tmp3->nb)
	{
		swap(lista, listb, 2);
		revrotate(lista, listb, 2, 1);
	}
	else
		rotate(lista, listb, 2, 1);
	push(lista, listb, 1, 3);
}

int	triabulle(t_list **lista, t_list **listb)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;

	tmp = *listb;
	tmp2 = tmp->next;
	tmp3 = tmp2->next;
	if (tmp->nb > tmp2->nb && tmp->nb > tmp3->nb)
	{
		push(lista, listb, 1, 1);
		if (tmp2->nb < tmp3->nb)
			swap(lista, listb, 2);
		push(lista, listb, 1, 2);
	}
	else if ((tmp->nb > tmp2->nb && tmp->nb < tmp3->nb) ||
		(tmp->nb < tmp2->nb && tmp->nb > tmp3->nb))
	{
		if (tmp->nb < tmp2->nb)
			swap(lista, listb, 2);
		else
			revrotate(lista, listb, 2, 1);
		push(lista, listb, 1, 3);
	}
	else
		suite(lista, listb);
	return (0);
}
