/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_creators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:23:49 by walter            #+#    #+#             */
/*   Updated: 2025/04/01 16:00:43 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*end_of_line_token(t_token *token, char **line, int *err)
{
//	printf("end of line token\n");
	(void)line;
	(void)err;
	token->lexeme = NULL;
	token->type = END_OF_LINE;
	return (token);
}

t_token *separator_token(t_token *token, char **line, int *err)
{
//	printf("separator_token\n");
	token->lexeme = separators(line, **line);
	if (!token->lexeme)
	{
		ft_error_msg("Memory allocation failed", NULL);
		return (NULL);
	}
	if (ft_strlen(token->lexeme) > 2)
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

t_token *wrong_token(t_token *token, char **line, int *err)
{
//	printf("wrong token\n");
	(*line)++;
	*err = 1;
	token->lexeme = NULL;
	token->type = 13;
	ft_error_msg("Wrong character in command line", NULL);
	return (token);
}
