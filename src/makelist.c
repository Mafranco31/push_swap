/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:31:13 by mafranco          #+#    #+#             */
/*   Updated: 2023/09/11 17:04:31 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
