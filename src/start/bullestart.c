/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullestart.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:35:48 by mafranco          #+#    #+#             */
/*   Updated: 2023/09/21 19:50:03 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	bulle3(t_list **lista, t_list **listb)
{
	t_tmp3	cpy;

	cpy.tmp = *lista;
	cpy.tmp2 = cpy.tmp->next;
	cpy.tmp3 = cpy.tmp2->next;
	if (cpy.tmp->nb > cpy.tmp2->nb && cpy.tmp->nb > cpy.tmp3->nb)
		rotate(lista, listb, 1, 1);
	else if (cpy.tmp2->nb > cpy.tmp->nb && cpy.tmp2->nb > cpy.tmp3->nb)
		revrotate(lista, listb, 1, 1);
	cpy.tmp = *lista;
	cpy.tmp2 = cpy.tmp->next;
	cpy.tmp3 = cpy.tmp2->next;
	if (cpy.tmp->nb > cpy.tmp2->nb)
		swap(lista, listb, 1);
}

static int	bulle2(t_list **lista, t_list **listb)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lista;
	tmp2 = tmp->next;
	if (tmp->nb > tmp2->nb)
		swap(lista, listb, 1);
	return (0);
}

int	triabulle(t_list **lista, t_list **listb, int len)
{
	if (len == 2)
		bulle2(lista, listb);
	else if (len == 3)
		bulle3(lista, listb);
	else if (len == 4)
		bulle4(lista, listb);
	else if (len == 5)
		bulle5(lista, listb);
	return (0);
}
