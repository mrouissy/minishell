#include "../../headers/head.h"
//nedd to handel mult $ in one token
char *get_dollar_var(char *str)
{
	int i = 0;
	char *var;

	while (*str)
	{
		if (*str == '$')
		{
			var = ft_safe_malloc(word_len(str) + 1, ALLOCATE, 0, 0);
			if (!var)
				return NULL;
			str++;
			while (*str && !is_space(*str))
			{
				var[i++] = *str;
				str++;
			}
			var[i] = '\0';
			return var;
		}
		str++;
	}
	return NULL;
}

char *replace_var(char *new, int dollar)
{
	char *str;
	int i = 0;
	int k = 0 ;
	char *var;
	char *tmp = ft_safe_malloc(ft_strlen(new),ALLOCATE,0,0);
	if(!tmp)
		return(printf("error in allocate replace_var"),NULL);
	if (!new)
		return (printf("string null new"),NULL);
	while (new[i] && dollar)
	{
		k = 0;
		while(new[i] && new[i] != '$')
			tmp[k++] = new[i++];
		tmp[k] = '\0';
		str = ft_strjoin(str,tmp);
		if(new[i] == '$')
		{
			var = get_dollar_var(new + i);
			str = ft_strjoin(str,getenv(var));
			dollar--;
		}
	}
	return str;
}

bool expand(s_toknes *toknes)
{
	char **cmd;
	int dollar = 0;
	char *str ;
	int i = 0 ;
	while (toknes)
	{
		if(toknes->type == TOKEN_DOLLAR && toknes->value[0] == '\"')
		{
			cmd = ft_split(toknes->value);
			if(!cmd)
				return(printf("error in split"));
			while (cmd[i])
			{
				//
				// if((dollar = ft_strchr('$',cmd[i])))
				// 	cmd[i] = replace_var(cmd[i], dollar);
				str = ft_strjoin(str,cmd[i]);
				i++;
			}
			toknes->value = str;
			printf("%s\n",toknes->value);
		}
		toknes = toknes->next;
	}
	return true;
}

