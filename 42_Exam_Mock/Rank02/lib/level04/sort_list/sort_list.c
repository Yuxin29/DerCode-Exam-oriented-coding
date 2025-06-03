#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int	sto;
	int i;
	t_list	*tmp;
	t_list	*current;

	tmp = lst;
	i = 0;
	while (tmp && tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	while (i > 0)
	{
		current = lst;
		while (current && current->next)
		{
			if (cmp(current->data, current->next->data) == 0)
			{
				sto = current->data;
				current->data = current->next->data;
				current->next->data = sto;
			}
			current = current->next;
		}
		i--;
	}
	return (lst);
}
