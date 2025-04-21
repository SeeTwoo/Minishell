/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_creators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:23:49 by walter            #+#    #+#             */
/*   Updated: 2025/04/21 17:11:31 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_precedence(int type)
{
	if (type == AND || type == OR)
		return (0);
	else if (type == PIPE)
		return (1);
	else if (type == WORD || type == IN || type == HD ||
				type == APPEND || type == TRUNC)
		return (2);
	else if (type == OPEN_PAREN || type == CLOSE_PAREN)
		return (3);
}

t_token	*separator_token(t_token *token, char **line)
{
	size_t	len;

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
		return (token);
	}
	token->type = hash_string(token->lexeme);
	token->prec = get_precedence(token->type);
	return (token);
}

t_token	*parenthesis_token(t_token *token, char **line)
{
	token->lexeme = parenthesis(line, **line);
	if (!token->lexeme)
	{
		ft_error_msg("Memory allocation failed", NULL);
		return (NULL);
	}
	token->type = OPEN_PAREN;
	if (token->lexeme[0] == ')')
		token->type = CLOSE_PAREN;
	token->prec = get_precedence(token->type);
	return (token);
}

t_token	*commands_token(t_token *token, char **line)
{
	token->lexeme = words(line);
	if (!token->lexeme)
		return (NULL);
	token->type = WORD;
	token->prec = get_precedence(token->type);
	return (token);
}
