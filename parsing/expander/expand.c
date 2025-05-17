#include "../../headers/head.h"
//nedd to handel mult $ in one token
char *get_dollar_var(char *str, char quote)
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
			while (*str && !is_space(*str) && *str != quote && *str != '\'')
			{
				var[i++] = *str;
				str++;
			}
			var[i] = '\0';
			//printf("%s\n",var);
			return var;
		}
		str++;
	}
	return NULL;
}

char *replace_var(char *new, int dollar)
{
	char *str = NULL;
	int i = 0;
	int k = 0 ;
	char *var;
	char *tmp = ft_safe_malloc(ft_strlen(new),ALLOCATE,0,0);
	if(!tmp)
		return(printf("error in allocate replace_var"),NULL);
	if (!new)
		return (printf("string null new"),NULL);
	while (dollar && new[i])
	{
		k = 0;
		while(new[i] && new[i] != '$')
			tmp[k++] = new[i++];
		tmp[k] = '\0';
		if (!(str = ft_strjoin(str,tmp)))
			return NULL;
		if(new[i] == '$')
		{
			var = get_dollar_var(new + i,new[0]);
			if (!(str = ft_strjoin(str,getenv(var))))
				return NULL;
			dollar--;
			while (!is_space(new[i]) && new[i] != new[0])
			i++;
		}
		//need handel last ' "
		// while(new[i] && new[i] != '$')
		// 	tmp[k++] = new[i++];
		// tmp[k] = '\0';
		// if (!(str = ft_strjoin(str,tmp)))
		// 	return NULL;
	}
	return str;
}

bool expand(s_toknes *toknes)
{
	while (toknes)
	{
		if(toknes->type == TOKEN_DOLLAR && toknes->value[0] == '\"')
		{
			toknes->value = replace_var(toknes->value,ft_strchr('$',toknes->value));
		}
		toknes = toknes->next;
	}
	return true;
}

