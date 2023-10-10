/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:32:19 by mafranco          #+#    #+#             */
/*   Updated: 2023/09/21 19:49:52 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static t_list	*change(t_list *list)
{
	t_list	*temp;

	if (!list)
		return (NULL);
	if (ft_lstsize(list) <= 1)
		return (list);
	temp = list->next;
	list->next = temp->next;
	temp->next = list;
	return (temp);
}

void	swap(t_list **lista, t_list **listb, int i)
{
	if (i == 1)
	{
		*lista = change(*lista);
		write(1, "sa\n", 3);
	}
	else if (i == 2)
	{
		*listb = change(*listb);
		write(1, "sb\n", 3);
	}
	else if (i == 3)
	{
		*lista = change(*lista);
		*listb = change(*listb);
		write(1, "ss\n", 3);
	}
}
