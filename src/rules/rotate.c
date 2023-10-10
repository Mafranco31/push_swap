/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:32:08 by mafranco          #+#    #+#             */
/*   Updated: 2023/10/09 09:47:04 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	*changerevrotate(t_list **lst)
{
	t_list	*seclast;
	t_list	*last;
	t_list	*list;
	int		i;

	list = *lst;
	if (list == NULL || list->next == NULL)
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
	*lst = last;
	return (NULL);
}

void	revrotate(t_list **lista, t_list **listb, int i, int times)
{
	if (times - 1 > 0)
		revrotate(lista, listb, i, times - 1);
	if (i == 1)
	{
		changerevrotate(lista);
		write(1, "rra\n", 4);
	}
	else if (i == 2)
	{
		changerevrotate(listb);
		write(1, "rrb\n", 4);
	}
	else if (i == 3)
	{
		changerevrotate(lista);
		changerevrotate(listb);
		write(1, "rrr\n", 4);
	}
}

static void	*changerotate(t_list **lst)
{
	t_list	*temp;
	t_list	*first;
	t_list	*list;

	list = *lst;
	if (list == NULL || list->next == NULL)
		return (NULL);
	temp = ft_lstlast(list);
	temp->next = list;
	first = list->next;
	list->next = NULL;
	*lst = first;
	return (NULL);
}

void	rotate(t_list **lista, t_list **listb, int i, int times)
{
	if (times - 1 > 0)
		rotate(lista, listb, i, times - 1);
	if (i == 1 && *lista)
	{
		changerotate(lista);
		write(1, "ra\n", 3);
	}
	else if (i == 2 && *listb)
	{
		changerotate(listb);
		write(1, "rb\n", 3);
	}
	else if (i == 3 && *lista && *listb)
	{
		changerotate(lista);
		changerotate(listb);
		write(1, "rr\n", 3);
	}
}
