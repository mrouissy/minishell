
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
		else if (is_schar(promt[i]))
		{
			tokens++;
			in_word = false;
			while (is_schar(promt[i]))
				i++;
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


char **ft_tokenes(char *promt)
{
	int i = 0, j = 0, k = 0;
	char quote;
	int wc = count_tokens(promt);
	//printf("%d\n",wc);
	char **tokens = ft_safe_malloc((wc + 1) * sizeof(char *),ALLOCATE,0,NULL);
	if (!tokens)
		return (NULL);
	while (i < wc)
	{
		while (promt[j] && is_space(promt[j]))
			j++;
		if (is_schar(promt[j]))
		{
			k = 0;
			tokens[i] = ft_safe_malloc(ft_strlen(promt) + 1,ALLOCATE,0,NULL);
			if (!tokens[i])
				return (NULL);
			while (promt[j] && is_schar(promt[j]))
				tokens[i][k++] = promt[j++];
		}
		else if ((promt[j] == '\'' || promt[j] == '\"'))
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
			if (promt[j] == quote)
			{
				j++;
				if(is_schar(promt[j]) || is_space(promt[j]) || !promt[j])
				{
					tokens[i][k++] = quote;
					i++;
					continue;
				}
				else if (!is_space(promt[j - 1]))
					tokens[i][k++] = quote;
				while (promt[j] && !is_space(promt[j]))
					tokens[i][k++] = promt[j++];
				tokens[i][k++] = quote;
			}
			else
				return (printf("Unclosed quote\n"), NULL);
			j++;
		}
		else
		{
			k = 0;
			tokens[i] = ft_safe_malloc(ft_strlen(promt) + 1,ALLOCATE,0,NULL);
			if (!tokens[i])
				return (NULL);
			while (promt[j] && promt[j] != '\'' && promt[j] != '\"')
			{
				if(is_schar(promt[j]) || is_space(promt[j]))
					break;
				tokens[i][k++] = promt[j++];
			}
		}
		tokens[i][k] = '\0';
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

	cmd = ft_tokenes(promt);
	if(!cmd)
	{
		printf("Error: ft_split failed\n");
		return ;
	}
	while (cmd[i])
	{
		if(!ft_strcmp(cmd[i],">"))
			tmp = new(cmd[i],TOKEN_REDIR_OUT);
		else if(!ft_strcmp(cmd[i],"<"))
			tmp = new(cmd[i],TOKEN_REDIR_IN);
		else if(!ft_strcmp(cmd[i],">>"))
			tmp = new(cmd[i],TOKEN_APPEND);
		else if(!ft_strcmp(cmd[i],"<<"))
			tmp = new(cmd[i],TOKEN_HEREDOC);
		else if(!ft_strcmp(cmd[i],"|"))
			tmp = new(cmd[i],TOKEN_PIPE );
		else if(!ft_strcmp(cmd[i],"\0"))
			tmp = new(cmd[i],TOKEN_EOF);
		else if(cmd[i][0] == '-')
			tmp = new(cmd[i],TOKEN_OPTION);
		else if(ft_strchr('$',cmd[i]))
			tmp = new(cmd[i],TOKEN_DOLLAR);
		else
			tmp = new(cmd[i],TOKEN_WORD);
		add_back(tmp,tokenes);
		i++;
	}
}
