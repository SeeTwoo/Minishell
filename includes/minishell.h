/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:49:32 by walter            #+#    #+#             */
/*   Updated: 2025/04/21 20:29:06 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "minishell_structs.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# ifndef SEP
#  define SEP "<>|&"
# endif

t_token	*free_tokens(t_token *tokens);

t_token	**lexer(char *line);

t_token *commands_token(t_token *token, char **line);
t_token *separator_token(t_token *token, char **line);
t_token *parenthesis_token(t_token *token, char **line);

char	*words(char **line);
char	*separators(char **line, char c);
char	*parenthesis(char **line, char c);
int		hash_string(char const *s);

t_ast_node	*parse_right(t_token **tokens, int index, int lim);
t_ast_node	*parse_left(t_token **tokens, int index, int lim);

int	find_lowest_right(t_token **tok, int i, int lim);
int	find_lowest_left(t_token **tok, int i, int lim);

t_ast_node	*cmd_creator(t_token **tokens, int index);
t_ast_node	*pipe_creator(t_token **tokens, int index);
t_ast_node	*logic_creator(t_token **tokens, int index);

char	**args_creator(t_token **tok);

t_redirect	*get_redirect(t_token **tokens, int index);

void	print_ast(t_ast_node *head);

#endif
