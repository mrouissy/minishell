

#include "../../headers/head.h"

int count_tokens(char *promt)
{
	int tokens = 0;
	int i = 0;
	char quote;
	bool in_word = false;

	while (promt[i])
	{
		if (is_space(promt[i]))
		{
			in_word = false;
			i++;
		}
		else if (promt[i] == '\'' || promt[i] == '\"')
		{
			quote = promt[i];
			i++;
			tokens++;
			while (promt[i] && promt[i] != quote)
				i++;
			if (promt[i] == quote)
				i++;
			in_word = false;
		}
		else if (!in_word)
		{
			tokens++;
			in_word = true;
			while (promt[i] && !is_space(promt[i]) && promt[i] != '\'' && promt[i] != '\"' && !is_schar(promt[i]))
				i++;
		}
		else
			i++;
	}
	return tokens;
}

void free_split(char **str)
{
	int  i = 0;
	while(str[i])
		free(str[i++]);
	free(str);
}

char **ft_split(char *promt)
{
	int i = 0, j = 0, k = 0;
	char quote;
	int wc = count_tokens(promt);
	char **tokens = ft_safe_malloc((wc + 1) * sizeof(char *),ALLOCATE,0,NULL);
	if (!tokens)
		return (NULL);
	char *tmp = ft_safe_malloc(3,ALLOCATE,0,NULL);
	if (!tmp)
		return (NULL);

	while (i < wc)
	{
		while (promt[j] && is_space(promt[j]))
			j++;
		if (is_sstring(promt + j))
		{
			k = 0;
			tokens[i] = ft_safe_malloc(ft_strlen(tmp) + 1,ALLOCATE,0,NULL);
			while (promt[j] && is_schar(promt[j]))
				tokens[i][k++] = promt[j++];
			tokens[i][k] = '\0';
		}
		else if (promt[j] == '\'' || promt[j] == '\"')
		{
			quote = promt[j];
			k = 0;
			tokens[i] = ft_safe_malloc(ft_strlen(promt) + 1, ALLOCATE, 0, NULL);
			if (!tokens[i])
				return (NULL);
			tokens[i][k++] = quote;
			j++;
			while (promt[j] && promt[j] != quote)
				tokens[i][k++] = promt[j++];
			if (promt[j] == quote && promt[j + 1] && !is_space(promt[j + 1]))
			{
				if(is_space(promt[++j]))
				{
					tokens[i][k++] = quote;
					tokens[i][k] = '\0';
					i++;
					continue;
				}
				while (promt[j] && !is_space(promt[j]))
					tokens[i][k++] = promt[j++];
				tokens[i][k++] = quote;
			}
			tokens[i][k] = '\0';
		}
		else
		{
			k = 0;
			tokens[i] = ft_safe_malloc(ft_strlen(promt) + 1,ALLOCATE,0,NULL);
			if (!tokens[i])
				return (NULL);
			while (promt[j] && !is_space(promt[j]) && promt[j] != '\'' && promt[j] != '\"' && !is_schar(promt[j]))
				tokens[i][k++] = promt[j++];
			while (promt[j] && is_schar(promt[j]))
				tokens[i][k++] = promt[j++];
			tokens[i][k] = '\0';
		}
		i++;
	}
	tokens[i] = NULL;
	return tokens;
}

void fill_tokens(s_toknes **tokenes, char *promt)
{
	char **cmd;
	int i = 0;
	s_toknes *tmp;

	cmd = ft_split(promt);
	while (cmd[i])
	{
		if(!ft_strcmp(cmd[i],">"))
			tmp = new(cmd[i],0);
		else if(!ft_strcmp(cmd[i],">"))
			tmp = new(cmd[i],3);
		else if(!ft_strcmp(cmd[i],">>"))
			tmp = new(cmd[i],4);
		else if(!ft_strcmp(cmd[i],"<<"))
			tmp = new(cmd[i],5);
		else if(!ft_strcmp(cmd[i],"$"))
			tmp = new(cmd[i],6);
		else if(!ft_strcmp(cmd[i],"|"))
			tmp = new(cmd[i],1);
		else if(!ft_strcmp(cmd[i],"\0"))
			tmp = new(cmd[i],7);
		else
			tmp = new(cmd[i],0);

		add_back(tmp,tokenes);
		i++;
	}
	while(*tokenes)
	{
		printf("%s==>%d\n",(*tokenes)->value,(*tokenes)->type);
		*tokenes=(*tokenes)->next;
	}
}
