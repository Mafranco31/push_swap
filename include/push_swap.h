/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:27:51 by mafranco          #+#    #+#             */
/*   Updated: 2023/10/05 16:02:27 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/src/libft.h"

typedef struct s_table
{
	int	*table;
	int	len;
	int	size;
	int	lastsize;
	int	parts;
	int	restup;
	int	restdown;
}		t_table;

typedef struct s_nb5
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	m;
}		t_nb5;

typedef struct s_tmp5
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;
	t_list	*tmp4;
	t_list	*tmp5;
}		t_tmp5;

typedef struct s_nb4
{
	int	i;
	int	j;
	int	k;
	int	l;
}		t_nb4;

typedef struct s_tmp3
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;
}		t_tmp3;

typedef struct s_tmp4
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;
	t_list	*tmp4;
}		t_tmp4;

void	swap(t_list **lista, t_list **listb, int i);

void	push(t_list **lista, t_list **listb, int i, int times);

void	rotate(t_list **lista, t_list **listb, int i, int times);

void	revrotate(t_list **lista, t_list **listb, int i, int times);

int		checkdouble(t_list *list, int i);

int		checkint(int argc, char **argv);

void	freelist(t_list *list);

t_list	*transformtolist(int argc, char **argv);

int		printlist(int argc, t_list *list);

void	printnbr(char *nb);

int		triabulle(t_list **lista, t_list **listb, int len);

int		algo(t_list **lista, t_list **listb);

int		optimid(t_list **lista, int len);

int		getnblst(t_list **lst, int num);

int		checklsta(t_list **lst);

int		checklstb(t_list **lst);

void	bulle4(t_list **lista, t_list **listb);

void	bulle3(t_list **lista, t_list **listb);

void	triabulle1list(t_list **lista, t_list **listb, int nblst, int len);

t_nb4	init4(t_list **lista);

void	bullelista(t_list **lista, t_list **listb, t_nb4 n, int len);

int		checkbulle(t_list **lista, t_list **listb, int nblst, int len);

int		put4frontstart(t_nb4 n, t_list **lista, t_list **listb);

void	bulle5(t_list **lista, t_list **listb);

int		tri5(t_list **lista, t_list **listb, int nblst);

t_nb5	init5(t_list **lista);

void	put4front(t_nb4 n, t_list **lista, t_list **listb);

int		*getparts(t_list **lista, int len);

void	sortinb1(t_table *t, t_list **lista, t_list **listb);

void	sortina1(t_table *t, t_list **lista, t_list **listb);

#endif
