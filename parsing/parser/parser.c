#include "../../headers/head.h"

int chech_syntax(s_toknes *data_table)
{
	s_toknes *head = data_table;
	if (!head || head->type != TOKEN_WORD)
		return (write(2,"Error in begin of cmd",22));
	while(head)
	{
		//if()
		head = head->next;
	}
}
