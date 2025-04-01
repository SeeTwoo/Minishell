/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:49:32 by walter            #+#    #+#             */
/*   Updated: 2025/04/01 03:12:04 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "minishell_structs.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>

t_token	*free_tokens(t_token *tokens);

t_token	*lexer(char *line);

t_token	*end_of_line_token(t_token *token, char **line, int *err);
t_token *wrong_token(t_token *token, char **line, int *err);
t_token *commands_token(t_token *token, char **line, int *err);
t_token *separators_token(t_token *token, char **line, int *err);
t_token *parenthesis_token(t_token *token, char **line, int *err);

char	*filtered_dup(char **line, int *err);
char	*separators(char **line, char c);
int		hash_string(char const *s);

#endif
