/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:39:01 by mrouissy          #+#    #+#             */
/*   Updated: 2025/04/29 15:34:42 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/head.h"

void display()
{
	char *head = h1;
	write(1,RED,8);
	while (*head)
	{
		write(1,head++,1);
		if(*head == '\n')
			usleep(100000);
	}
	write(1,WHT,8);
}
int main()
{
	char * line;

	handel_signals();
	display();
	while (1)
	{
		line =readline("./minishell$ ");
		if(ft_strlen(line))
			add_history(line);
		fill_tokens(line);
	}
	free(line);
	clear_history();
	return (0);
}
