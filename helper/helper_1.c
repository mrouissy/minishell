/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:08:32 by mrouissy          #+#    #+#             */
/*   Updated: 2025/04/29 14:10:16 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/head.h"

int ft_strlen(char *str)
{
	int i;
	if(!str)
		return 0;
	i = -1;
	while (str[++i])
		;
	return (i);
}

int ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int ft_strchr(char c, char *arry)
{
	int i = 0;
	if(!arry && !c)
		return (0);
	while(*arry)
	{
		if(c == *arry)
			i++;
		arry++;
	}
	return (i);
}
bool is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

bool is_schar(char c)
{
	return (c == '<' || c == '|' || c == '>');
}
bool is_sstring(char *str)
{

	if (is_schar(str[0]) && str[0] == str[1] && str[0] != '|')
		return true;
	else
		return false;

}
int word_len(char *str)
{
	int i = 0;
	if(!str)
		return i;
	while(str[i] && !is_space(str[i]) && !is_schar(str[i]))
		i++;
	return i;
}
char *ft_strdup(char *str)
{
	if(!str)
		return NULL;
	char *dup = ft_safe_malloc(ft_strlen(str) + 1 ,ALLOCATE,0,0);
	if(!dup)
		return NULL;
	while(*str)
	{
		*dup = *str;
		dup++;
		str++;
	}
	return dup;
}
char *ft_strjoin(char *s1, char *s2)
{
	if(!s1)
		return ft_strdup(s2);
	else if (!s2)
		return ft_strdup(s1);
	char *ret = ft_safe_malloc(ft_strlen(s1) + ft_strlen(s2) + 1,ALLOCATE,0,0);
	while (*s1)
	{
		*ret = *s1;
		s1++;
	}
	while (*s2)
	{
		*ret = *s2;
		s2++;
	}
	return ret;
}
int wc(char *str)
{
	int i = 0;
	bool in_word = true;
	while (*str)
	{
		if(is_space(*str) && !in_word)
			in_word = true;
		else if (in_word)
		{
			i++;
			in_word = false;
		}
		str++;
	}
	return i;
}
char **ft_split(char *str)
{
	int count = wc(str);
	int i = 0;
	int j = 0;
	char **result = ft_safe_malloc(count + 1,ALLOCATE,0,0);
	if(!result || !str)
		return(NULL);
	while (*str)
	{
		if(!is_space(*str))
		{
			j = 0;
			result[i] =ft_safe_malloc(word_len(str) + 1 ,ALLOCATE,0,0);
			if(!result[i])
				return(free_split(result),NULL);
			while (!is_space(*str) && *str)
				result[i][j++] = *str++;
			result[i][j] = '\0';
			i++;
		}
		else
			str++;
	}
	result[i] = NULL;
	return result;
}

