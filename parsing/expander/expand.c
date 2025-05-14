#include "../../headers/head.h"

char *get_dollar_var(char quote ,char *str)
{
	int i = 0;
	char *var;
	if(quote != '\"' || !str)
		return NULL;
	while(*str)
	{
		if(*str == '$')
		{
			var = ft_safe_malloc(word_len(str),ALLOCATE,0,0);
			while (!is_space(*str))
			{
				var[i++] = *str;
				str++;
			}
			var[i] = '\0';
			return(var);
		}
		str++;
	}
	return(NULL);
}
char *replace_var(char **new, char *var)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char *str = NULL;
	char *tmp;
	char *tmp1;
	if(new)
		return NULL;
	while (new[i])
	{
		if(ft_strchr('$',new[i]))
		{
			tmp = ft_safe_malloc(ft_strlen(new[i]),ALLOCATE,0,0);
			tmp1 = ft_safe_malloc(ft_strlen(new[i]),ALLOCATE,0,0);
			if(!tmp || !tmp1)
				return(printf("error in replace var"),NULL);
			while (new[i][j] != '$')
				tmp[k++] = new[i][j++];
			tmp[k] = '\0';
			while (!is_space(new[i][j++]))
				;
			k = 0;
			while (new[i][j])
				tmp1[k++] = new[i][j++];
			tmp1[k] = '\0';
			str = ft_strjoin(str,tmp);
			str = ft_strjoin(str,getenv(var));
			str = ft_strjoin(str,tmp1);
			str = ft_strjoin(str," ");
		}
		else
		{
			str = ft_strjoin(str,new[i]);
			str = ft_strjoin(str," ");
		}
		i++;
	}
	return str;
}

bool expand(s_toknes *toknes)
{
	char **cmd;
	char *str;
	char quote;
	char *variable;
	int i = 0 ;
	while (toknes)
	{
		if(toknes->type == TOKEN_DOLLAR)
		{
			str = toknes->value;
			quote = str[0];
			cmd = ft_split(str);
			if(!cmd)
				return(printf("error in split"));
			while (cmd[i])
			{
				if(ft_strchr('$',cmd[i]))
				{
					variable = get_dollar_var(quote,cmd[i]);
					if(!variable)
						return false;
					break;
				}
				i++;
			}
			toknes->value = replace_var(cmd,variable);
		}
		toknes = toknes->next;
	}
	return true;
}
//srtjoin
