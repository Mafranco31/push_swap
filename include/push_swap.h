#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/src/libft.h"

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

int	triabulle(t_list **lista, t_list **listb);

int	algo(t_list **lista, t_list **listb);

int	optimid(t_list **lista, int len);

int	getnblst(t_list **lst, int num);

int	checklst(t_list **lst);

#endif
