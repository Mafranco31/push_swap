/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:50:28 by mafranco          #+#    #+#             */
/*   Updated: 2023/09/11 19:23:32 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	getit2(t_list **lista, t_list **listb)
{
	t_list	*a;
	t_list	*b;
	
	a = *lista;
	while (a->next != NULL)
	{
		b = a->next;
		if (a->nb < b->nb)
		{
			swap(lista, listb, 1);
		}
		push(lista, listb, 2, 1);
		a = *lista;
	}
	push(lista, listb, 2, 1);
}

static void	getit1(t_list **lista, t_list **listb)
{
	t_list	*a;
	t_list	*b;

	a = *lista;
	while (a->next != NULL)
	{
		b = a->next;
		if (a->nb > b->nb)
		{
			swap(lista, listb, 1);
		}
		push(lista, listb, 2, 1);
		a = *lista;
	}
	//push(lista, listb, 2, 1);
}

int	algo(t_list **lista, t_list **listb)
{
	t_list	*a;
	t_list	*b;
	int	i;
	int	j;

	a = *lista;
	b = a->next;
	j = 1;
	i = ft_lstsize(*lista) - 1;
	while (j < i)
	{
		if (a->nb < b->nb)
		{
			b = b->next;
			a = a->next;
			j++;
		}
		else
		{
			getit1(lista, listb);
			getit2(listb, lista);
			j = 1;
			a = *lista;
			b = a->next;
		}
		printf("j = %d\n", j);
		write(1, "lista\n", 7);
		printlist(ft_lstsize(*lista), *lista);
		write(1, "listb\n", 7);
		printlist(ft_lstsize(*listb), *listb);
	}
	return (0);
}
