
 #include "..//headers/head.h"

s_toknes *new(char * value, int type)
{
	s_toknes *node = ft_safe_malloc(sizeof(s_toknes),ALLOCATE,0,0);
	if(!node)
			return NULL;
	node->value = value;
	node->type = type;
	node->next = NULL;
	return node;
}

void add_back(s_toknes *new, s_toknes **head)
{
	s_toknes *tmp;
	if(!head || !new)
			return ;
	if(!*head)
	{
			*head = new;
			return ;
	}
	tmp = *head;
	while(tmp->next)
			tmp = tmp->next;
	tmp->next = new;
}

s_toknes *last_token(s_toknes *head)
{
	if(!head)
		return NULL;
	while(head->next)
		head=head->next;
	return head;
}
