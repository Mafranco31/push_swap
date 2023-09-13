/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:31:13 by mafranco          #+#    #+#             */
/*   Updated: 2023/09/12 17:48:14 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	insertlst(t_list **mid, int nb)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*new;

	tmp = *mid;
	tmp2 = tmp->next;
	new = ft_lstnew(nb);
	if (nb < tmp->nb)
	{
		ft_lstadd_front(mid, new);
	}
	else
	{
		while (tmp2 && (tmp->nb < nb && tmp2->nb < nb))
		{
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		if (tmp2 == NULL)
			ft_lstadd_back(mid, new);
		else
		{
			tmp->next = new;
			new->next = tmp2;
		}
	}
}

int	getnblst(t_list **lst, int num)
{
	t_list	*tmp;
	int	i;

	tmp = *lst;
	i = 1;
	while (i < (num / 2) && tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp->nb);
}

int	optimid(t_list **lista, int len)
{
	t_list	*mid;
	t_list	*tmp;
	int	i;

	tmp = *lista;
	mid = ft_lstnew(tmp->nb);
	tmp = tmp->next;
	if (tmp->nb > mid->nb)
		ft_lstadd_back(&mid, ft_lstnew(tmp->nb));
	else
		ft_lstadd_front(&mid, ft_lstnew(tmp->nb));
	tmp = tmp->next;
	while (tmp && ft_lstsize(mid) <= len)
	{
		insertlst(&mid, tmp->nb);
		tmp = tmp->next;
	}
	i = getnblst(&mid, ft_lstsize(mid));
	freelist(mid);
	return (i);
}

t_list	*transformtolist(int argc, char **argv)
{
	t_list	*ptr;
	int		i;

	if (checkint(argc, argv) == 1)
		return (NULL);
	i = ft_atoi(argv[argc - 1]);
	ptr = ft_lstnew(i);
	argc--;
	if (ptr == NULL)
		return (NULL);
	while (argc > 1)
	{
		i = ft_atoi(argv[argc - 1]);
		if (checkdouble(ptr, i) == 1)
		{
			freelist(ptr);
			return (NULL);
		}
		ft_lstadd_front(&ptr, ft_lstnew(i));
		argc--;
	}
	return (ptr);
}
