/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:27:11 by mrouissy          #+#    #+#             */
/*   Updated: 2025/04/25 14:36:03 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
#define SIGNALS_H

#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

//handel ctrl + c ctrl + d ctrl + \  //
void handel_signals();

#endif
