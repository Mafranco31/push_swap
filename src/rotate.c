/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:32:08 by mafranco          #+#    #+#             */
/*   Updated: 2023/09/11 17:04:56 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_list	*changerevrotate(t_list *list)
{
	t_list	*seclast;
	t_list	*last;
	int		i;

	if (list == NULL)
		return (NULL);
	seclast = list;
	i = ft_lstsize(list);
	while (i > 2)
	{
		seclast = seclast->next;
		i--;
	}
	last = seclast->next;
	seclast->next = NULL;
	last->next = list;
	return (last);
}

void	revrotate(t_list **lista, t_list **listb, int i, int times)
{
	if (times - 1 > 0)
		revrotate(lista, listb, i, times - 1);
	if (i == 1)
	{
		*lista = changerevrotate(*lista);
		write(1, "rra\n", 4);
	}
	else if (i == 2)
	{
		*listb = changerevrotate(*listb);
		write(1, "rrb\n", 4);
	}
	else if (i == 3)
	{
		*lista = changerevrotate(*lista);
		*listb = changerevrotate(*listb);
		write(1, "rrr\n", 4);
	}
}

static t_list	*changerotate(t_list *list)
{
	t_list	*temp;
	t_list	*first;

	if (list == NULL)
		return (NULL);
	temp = ft_lstlast(list);
	temp->next = list;
	first = list->next;
	list->next = NULL;
	return (first);
}

void	rotate(t_list **lista, t_list **listb, int i, int times)
{
	if (times - 1 > 0)
		rotate(lista, listb, i, times - 1);
	if (i == 1 && *lista)
	{
		*lista = changerotate(*lista);
		write(1, "ra\n", 3);
	}
	else if (i == 2 && *listb)
	{
		*listb = changerotate(*listb);
		write(1, "rb\n", 3);
	}
	else if (i == 3 && *lista && *listb)
	{
		*lista = changerotate(*lista);
		*listb = changerotate(*listb);
		write(1, "rr\n", 3);
	}
}
