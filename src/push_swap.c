/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:21:29 by mafranco          #+#    #+#             */
/*   Updated: 2023/09/11 18:55:20 by mafranco         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_list	*lista;
	t_list	*listb;

	listb = NULL;
	if (argc <= 2)
		return (0);
	lista = transformtolist(argc, argv);
	if (lista == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	algo(&lista, &listb);
	/*swap(&lista, &listb, 1);
	push(&lista, &listb, 2, 4);
	revrotate(&lista, &listb, 3, 2);*/
	write(1, "Liste A\n", 8);
	printlist(argc, lista);
	write(1, "\nListe B\n", 9);
	printlist(argc, listb);
	freelist(lista);
	freelist(listb);
	return (0);
}

/*	swap : 1 = sa, 2 = sb, 3 = ss
	push : 1 = pa (b sur a), 2 = pb (a sur b)
	rotate : 1 = ra, 2 = rb, 3 = rr (bas en haut)
	revrotate : 1 = rra, 2 = rrb, 3 = rrr (haut en bas)
*/
