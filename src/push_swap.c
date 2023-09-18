/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:21:29 by mafranco          #+#    #+#             */
/*   Updated: 2023/09/18 16:58:14 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	freelist(t_list *list)
{
	t_list	*temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

int	checklstb(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		i;

	i = 1;
	tmp = *lst;
	tmp2 = tmp->next;
	while (tmp2)
	{
		if (tmp->nb < tmp2->nb)
			return (i);
		tmp2 = tmp2->next;
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	checklsta(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		i;

	i = 1;
	tmp = *lst;
	tmp2 = tmp->next;
	while (tmp2)
	{
		if (tmp->nb > tmp2->nb)
			return (i);
		tmp2 = tmp2->next;
		tmp = tmp->next;
		i++;
	}
	return (0);
}

static int	testint(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*lista;
	t_list	*listb;

	listb = NULL;
	if (argc < 1)
		return (0);
	if (argc == 2)
	{
		if (testint(argv[1]) == 1)
			write(2, "Error\n", 6);
		exit(1);
	}
	lista = transformtolist(argc, argv);
	if (lista == NULL)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (checklsta(&lista) > 0)
		algo(&lista, &listb);
	freelist(lista);
	freelist(listb);
	return (0);
}

/*	swap : 1 = sa, 2 = sb, 3 = ss
	push : 1 = pa (b sur a), 2 = pb (a sur b)
	rotate : 1 = ra, 2 = rb, 3 = rr (bas en haut)
	revrotate : 1 = rra, 2 = rrb, 3 = rrr (haut en bas)
*/
