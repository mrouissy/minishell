/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:13:31 by mrouissy          #+#    #+#             */
/*   Updated: 2025/05/17 15:18:05 by mrouissy         ###   ########.fr       */
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
int word_len(char *str);
char **ft_split(char *str);
int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);
int ft_strchr(char c, char *arry);
bool is_space(char c);
bool is_schar(char c);
bool is_sstring(char *str);
char *ft_strjoin(char *s1, char *s2);
char *remove_quote(char *token, char quote);

//helper_linked_list
s_toknes *new(char * value, int type);
void add_back(s_toknes *new, s_toknes **head);
s_toknes *last_token(s_toknes *head);


#endif
