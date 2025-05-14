#include "../../headers/head.h"

bool check_position(s_toknes *cur)
{
	s_toknes *last = last_token(cur);
	if(last->type != TOKEN_WORD || cur->type != TOKEN_WORD)
		return(printf("error in order of argiment"),false);
	return(true);
}

bool chech_syntax(s_toknes *cur)
{
	if (!cur )
		return (write(2,"Error no tokens",22),false);
	if (!check_position(cur))
		return(false);
	while(cur)
	{
		if(cur->type == TOKEN_WORD && is_sstring(cur->value))
			return (write(2,"Error can't be || ",22),false);
		if (cur->type == TOKEN_PIPE &&  cur->next->type != TOKEN_WORD)
			return (write(2,"Error must be an word after | ",22),false);
		cur = cur->next;
	}
}
