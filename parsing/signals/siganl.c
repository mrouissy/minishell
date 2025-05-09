/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   siganl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:26:06 by mrouissy          #+#    #+#             */
/*   Updated: 2025/04/29 15:38:28 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/head.h"

static void handeler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if(sig == SIGQUIT)
	{
		exit(QUIT_STATUS);
	}
}
void handel_signals()
{
	signal(SIGQUIT,SIG_IGN);
	signal(SIGINT,SIG_IGN);
	signal(SIGQUIT,handeler);
	signal(SIGINT,handeler);
}
