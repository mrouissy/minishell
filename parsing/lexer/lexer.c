

#include "../../headers/head.h"

bool is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

bool is_schar(char c)
{
	return (c == '<' || c == '|' || c == '>');
}

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
	char **tokens = malloc((wc + 1) * sizeof(char *));
	if (!tokens)
		return (NULL);

	while (i < wc)
	{
		while (promt[j] && is_space(promt[j]))
			j++;
		if (promt[j] == '\'' || promt[j] == '\"')
		{
			quote = promt[j++];
			k = 0;
			tokens[i] = malloc(ft_strlen(promt) + 1);
			while (promt[j] && promt[j] != quote)
				tokens[i][k++] = promt[j++];
			tokens[i][k] = '\0';
			if (promt[j] == quote)
				j++;
		}
		else
		{
			k = 0;
			tokens[i] = malloc(ft_strlen(promt) + 1);
			while (promt[j] && !is_space(promt[j]) && promt[j] != '\'' && promt[j] != '\"' && !is_schar(promt[j]))
				tokens[i][k++] = promt[j++];
			if (promt[j] && is_schar(promt[j]))
				tokens[i][k++] = promt[j++];
			tokens[i][k] = '\0';
		}
		i++;
	}
	tokens[i] = NULL;
	return tokens;
}

bool fill_tokens(char *promt)
{
	char **tokenes;
	int i = 0;
	tokenes = ft_split(promt);
	while (tokenes[i])
		printf("%s\n",tokenes[i++]);
	free_split(tokenes);
	return true;
}
