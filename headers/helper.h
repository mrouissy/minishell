/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:13:31 by mrouissy          #+#    #+#             */
/*   Updated: 2025/04/29 14:00:10 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
#define HELPER_H

//exit code -------------
#define FAILED_STATUS 127
#define QUIT_STATUS 139
//-------------------------
#include <stdbool.h>
#include "parsing.h"

//helper_1
int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);
bool ft_strchr(char c, char *arry);
char **ft_split(char *promt);
void free_split(char **str);

//helper_linked_list
s_toknes *new(char * value, int type);
void add_back(s_toknes *new, s_toknes **head);


#endif
