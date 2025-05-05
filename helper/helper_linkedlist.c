
 #include "..//headers/head.h"

s_toknes *new(char * value, int type)
{
	s_toknes *node = malloc(sizeof(s_toknes));
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
