#include "../headers/head.h"


static void	ft_bzero(void *s, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (len--)
		*tmp++ = 0;
}

static void free_list(t_mem_node **list, int exit_status)
{
	t_mem_node *tmp;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->address);
		free(*list);
		*list = tmp;
	}
	exit(exit_status);
}

static void lst_add_back_malloc(t_mem_node **lst, void *value)
{
	t_mem_node *last;
	t_mem_node *tmp;


	if (!lst || !value)
		return;
	tmp = malloc(sizeof(t_mem_node));
	if (!tmp)
		free_list(lst, -1);
	tmp->address = value;
	tmp->next = NULL;
	if (!*lst)
	{
		*lst = tmp;
		return;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = tmp;
}

static void free_specific_node(t_mem_node **lst, void *to_delete)
{
    t_mem_node	*current;
    t_mem_node	*prev;

    if (!lst || !to_delete)
        return;
    current = *lst;
    prev = NULL;
    while (current)
    {
        if (current->address == to_delete)
        {
            free(current->address);
            if (prev)
                prev->next = current->next;
            else
                *lst = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
	free(to_delete);
}

void	*ft_safe_malloc(size_t size, int key, int exit_status, void *to_delete)
{
	static t_mem_node	*mem_node;
	void				*ptr;

	ptr = NULL;

	if (key == ALLOCATE)
	{
		ptr = malloc(size);
		if (!ptr)
			free_list(&mem_node, -1);
		lst_add_back_malloc(&mem_node, ptr);
		ft_bzero(ptr, size);
	}
	else if (key == FREE_ALL)
		free_list(&mem_node, exit_status);
	else if (key == FREE_ONE)
		free_specific_node(&mem_node, to_delete);
	return (ptr);
}



