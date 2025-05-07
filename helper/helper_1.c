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

bool ft_strchr(char c, char *arry)
{
	if(!arry && !c)
		return (false);
	while(*arry)
	{
		if(c == *arry)
			return (true);
		arry++;
	}
	return (false);
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
// int main()
// {
// 	printf("%d\n",is_sstring("<<"));
// 	printf("%d\n",is_sstring(">>"));
// 	printf("%d\n",is_sstring("<>"));
// 	printf("%d\n",is_sstring("><"));
// 	printf("%d\n",is_sstring("||"));
// 	printf("%d\n",is_sstring("hello"));
// 	return 0;
// }

