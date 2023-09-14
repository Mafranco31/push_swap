#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/src/libft.h"

typedef struct	s_nb4
{
	int	i;
	int	j;
	int	k;
	int	l;
}		t_nb4;

typedef struct	s_tmp3
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;
}		t_tmp3;

typedef struct	s_tmp4
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

int	checkdouble(t_list *list, int i);

int	checkint(int argc, char **argv);

void	freelist(t_list *list);

t_list	*transformtolist(int argc, char **argv);

int	printlist(int argc, t_list *list);

void	printnbr(char *nb);

int	triabulle(t_list **lista, t_list **listb, int len);

int	algo(t_list **lista, t_list **listb);

int	optimid(t_list **lista, int len);

int	getnblst(t_list **lst, int num);

int	checklst(t_list **lst);

void	bulle4(t_list **lista, t_list **listb);

void	bulle3(t_list **lista, t_list **listb);

void	triabulle1list(t_list **lista, t_list **listb, int nblst, int len);

t_nb4	init4(t_list **lista);

void	bullelista(t_list **lista, t_list **listb, t_nb4 n, int len);

int	checkbulle(t_list **lista, t_list **listb, int nblst, int len);

#endif
