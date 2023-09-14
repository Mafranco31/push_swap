/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbeforebulle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:40:34 by mafranco          #+#    #+#             */
/*   Updated: 2023/09/14 17:33:16 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	checklsta3(t_list **lista)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;
	
	tmp = *lista;
	tmp2 = tmp->next;
	tmp3 = tmp2->next;
	if (tmp->nb < tmp2->nb && tmp2->nb < tmp3->nb)
		return (1);
	return (0);
}

static int	checklsta4(t_list **lista)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;
	t_list	*tmp4;

	tmp = *lista;
	tmp2 = tmp->next;
	tmp3 = tmp2->next;
	tmp4 = tmp3->next;
	if (tmp->nb < tmp2->nb && tmp2->nb < tmp3->nb && tmp3->nb < tmp4->nb)
		return (1);
	return (0);
}

static int	checklstb3(t_list **lista, t_list **listb)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;
	
	tmp = *listb;
	tmp2 = tmp->next;
	tmp3 = tmp2->next;
	if (tmp->nb > tmp2->nb && tmp2->nb > tmp3->nb)
	{
		push(lista, listb, 1, 3);
		return (1);
	}
	return (0);
}

static int	checklstb4(t_list **lista, t_list **listb)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;
	t_list	*tmp4;
	
	tmp = *listb;
	tmp2 = tmp->next;
	tmp3 = tmp2->next;
	tmp4 = tmp3->next;
	if (tmp->nb > tmp2->nb && tmp2->nb > tmp3->nb && tmp3->nb > tmp4->nb)
	{
		push(lista, listb, 1, 4);
		return (1);
	}
	return (0);
}

int	checkbulle(t_list **lista, t_list **listb, int nblst, int len)
{
	int	i;

	i = 0;
	if (nblst == 1 && len == 3)
		i += checklsta3(lista);
	else if (nblst == 1 && len == 4)
		i += checklsta4(lista);
	else if (nblst == 2 && len == 3)
		i += checklstb3(lista, listb);
	else if (nblst == 2 && len == 4)
		i += checklstb4(lista, listb);
	return (i);
}
