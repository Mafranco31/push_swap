/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testalgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:47:24 by mafranco          #+#    #+#             */
/*   Updated: 2023/09/13 12:23:27 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	checkswap(t_list **lista, t_list **listb)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lista;
	tmp2 = tmp->next;
	if (tmp2 == NULL)
		return ;
	if (tmp->nb > tmp2->nb)
		swap(lista, listb, 1);
}

static int	getbot(t_list **lista, t_list **listb, int ref, int len)
{
	int	low;
	t_list	*tmp;
	int	high;

	tmp = *lista;
	low = 0;
	high = 0;
	while (len > 0)
	{
		if (tmp->nb <= ref)
		{
			push(lista, listb, 2, 1);
			low++;
		}
		else
		{
			rotate(lista, listb, 1, 1);
			high++;
		}
		tmp = *lista;
		len--;
	}
	revrotate(lista, listb, 1, high);
	//if (low != 3)
	push(lista, listb, 1, low);
	return (low);
}

static int	bouclealgo(t_list **lista, t_list **listb, int ref, int len)
{
	int	i;

	i = getbot(lista, listb, ref, len);
	printf("i = %i\n", i);
	if (i > 2)
		bouclealgo(lista, listb, optimid(lista, i), i);
	//else if (i == 3)
	//	triabulle(lista, listb);
	else
	{
		if (i == 2)
			checkswap(lista, listb);
		rotate(lista, listb, 1, i);
	}
	if (len - i > 2)
		bouclealgo(lista, listb, optimid(lista, len - i), len - i);
	//else if (i == 3)
	//	triabulle(lista, listb);
	else
	{
		if (len - i == 2)
			checkswap(lista, listb);
		rotate(lista, listb, 1, len - i);
	}
	return (0);
}

int	algo(t_list **lista, t_list **listb)
{
	int	i;

	i = optimid(lista, ft_lstsize(*lista));
	bouclealgo(lista, listb, i, ft_lstsize(*lista));
	return (0);
}
