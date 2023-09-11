#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (new = NULL);
	new -> nb = content;
	new -> next = NULL;
	return (new);
}
