/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_creators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:23:49 by walter            #+#    #+#             */
/*   Updated: 2025/04/01 19:25:09 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token *separator_token(t_token *token, char **line, int *err)
{
	size_t	len;
//	printf("separator_token\n");
	token->lexeme = separators(line, **line);
	if (!token->lexeme)
	{
		ft_error_msg("Memory allocation failed", NULL);
		return (NULL);
	}
	len = ft_strlen(token->lexeme);
	if (len > 2 || (len == 1 && token->lexeme[0] == '&'))
	{
		ft_error_msg("Syntax error in the line", token->lexeme);
		*err = 1;
		return (token);
	}
	token->type = hash_string(token->lexeme);
	return (token);
}

t_token	*parenthesis_token(t_token *token, char **line, int *err)
{
//	printf("parenthesis token\n");
	token->lexeme = parenthesis(line, **line);
	if (!token->lexeme)
	{
		ft_error_msg("Memory allocation failed", NULL);
		return (NULL);
	}
	token->type = OPEN_PAREN;
	*err = 0;
	if (token->lexeme[0] == ')')
		token->type = CLOSE_PAREN;
	return (token);
}

t_token *commands_token(t_token *token, char **line, int *err)
{
//	printf("commands_token\n");
	token->lexeme = filtered_dup(line, err);
	if (!token->lexeme)
		return (NULL);
	token->type = CMD;
	return (token);
}
