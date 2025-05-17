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
			return var;
		}
		str++;
	}
	return NULL;
}

char *replace_var(char *new)
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
	while (new[i])
	{
		k = 0;
		while(new[i] && new[i] != '$')
			tmp[k++] = new[i++];
		tmp[k] = '\0';
		if (!(str = ft_strjoin(str,tmp)))
			return NULL;
		if(new[i] == '$' && new[i-1] != '\\')
		{
			var = getenv(get_dollar_var(new + i,new[0]));
			if(!var)
			{
				while (!is_space(new[i]) && new[i])
					tmp[k++] = new[i++];
				tmp[k] = '\0';
				if (!(var= ft_strjoin(str,tmp)))
					return NULL;
			}
			else
			{
				while (!is_space(new[i]) && new[i] != new[0] && new[i])
					i++;
			}
			if (!(str = ft_strjoin(str,var)))
				return NULL;
		}
		else if(new[i - 1] == '\\' && new[i] == '$')
		{
			while (!is_space(new[i]) && new[i])
				tmp[k++] = new[i++];
			tmp[k] = '\0';
			if (!(str = ft_strjoin(str,tmp)))
				return NULL;
		}
	}
	return str;
}

bool expand(s_toknes *toknes)
{
	while (toknes)
	{
		if(toknes->type == TOKEN_DOLLAR )
		{
			toknes->value = replace_var(toknes->value);
		}
		toknes = toknes->next;
	}
	return true;
}
