/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:31:06 by mafranco          #+#    #+#             */
/*   Updated: 2023/10/10 12:48:58 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	maxint3(char *nb, int j)
{
	if (nb[0] > '4')
		return (1);
	else if (nb[0] == '4')
	{
		if ((j >= 1 && nb[1] > '8') || (j == 0 && nb[1] > '7'))
			return (1);
	}
	return (0);
}

static int	maxint1(char *nb, int j)
{
	if (nb[0] > '4')
		return (1);
	else if (nb[0] == '4')
	{
		if (nb[1] > '8')
			return (1);
		else if (nb[1] == '8')
		{
			if (nb[2] > '3')
				return (1);
			else if (nb[2] == '3')
			{
				if (nb[3] > '6')
					return (1);
				else if (nb[3] == '6')
					return (maxint3(&nb[4], j));
			}
		}
	}
	return (0);
}

static int	checkmaxint(char *nb, int i, int j)
{
	if (i > 10)
		return (1);
	else if (i < 10)
		return (0);
	if (nb[0] > '2')
		return (1);
	else if (nb[0] == '2')
	{
		if (nb[1] > '1')
			return (1);
		else if (nb[1] == '1')
		{
			if (nb[2] > '4')
				return (1);
			else if (nb[2] == '4')
			{
				if (nb[3] > '7')
					return (1);
				else if (nb[3] == '7')
					return (maxint1(&nb[4], j));
			}
		}
	}
	return (0);
}

int	checkint(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	argc--;
	while (argc > 0)
	{
		i = 0;
		j = 0;
		k = 0;
		if (argv[argc][j] == '-' || argv[argc][j] == '+')
			j++;
		while (argv[argc][k + j] == '0')
			k++;
		while (argv[argc][i + j + k])
		{
			if (ft_isdigit(argv[argc][i + j + k]) == 0)
				return (1);
			i++;
		}
		if (checkmaxint(&argv[argc][k + j], i, j) == 1)
			return (1);
		argc--;
	}
	return (0);
}

int	checkdouble(t_list *list, int i)
{
	t_list	*temp;

	temp = list;
	while (temp != NULL)
	{
		if (i == temp->nb)
			return (1);
		temp = temp->next;
	}
	return (0);
}
