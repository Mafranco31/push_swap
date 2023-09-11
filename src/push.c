/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:31:40 by mafranco          #+#    #+#             */
/*   Updated: 2023/09/11 18:52:25 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push2(t_list **lista, t_list **listb, t_list *temp)
{
	temp = *listb;
	*listb = temp->next;
	if (*lista)
		temp->next = *lista;
	else
		temp->next = NULL;
	*lista = temp;
}

void	push(t_list **lista, t_list **listb, int i, int times)
{
	t_list	*temp;

	temp = NULL;
	if (i == 1 && *listb)
	{
		/*temp = *listb;
		*listb = temp->next;
		if (*lista)
			temp->next = *lista;
		else
			temp->next = NULL;
		*lista = temp;*/
		push2(lista, listb, temp);
		write(1, "pa\n", 3);
	}
	else if (i == 2 && *lista)
	{
		/*temp = *lista;
		*lista = temp->next;
		if (*listb)
			temp->next = *listb;
		else
			temp->next = NULL;
		*listb = temp;*/
		push2(listb, lista, temp);
		write(1, "pb\n", 3);
	}
	if (times - 1 > 0)
		push(lista, listb, i, times - 1);
}
