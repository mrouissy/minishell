/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:27:11 by mrouissy          #+#    #+#             */
/*   Updated: 2025/04/29 15:39:20 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
#define SIGNALS_H

#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
// mac
extern void rl_replace_line (const char *, int);

//handel ctrl + c ctrl + d ctrl + \  //
void handel_signals();

#endif
