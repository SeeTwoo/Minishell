/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:18:22 by walter            #+#    #+#             */
/*   Updated: 2025/04/01 19:26:58 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_whitespace(char **line)
{
	while (ft_isspace(**line))
		(*line)++;
}

t_token	*scan_token(char **line, int *err)
{
	t_token		*token;
	t_token		*temp;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->next = NULL;
	if (**line == '(' || **line == ')')
		temp = parenthesis_token(token, line, err);
	else if (ft_strchr(SEPARATORS, **line))
		temp = separator_token(token, line, err);
	else
		temp = commands_token(token, line, err);
	if (!temp)
	{
		free(token);
		return (NULL);
	}
	return (token);
}

t_token	*lexer(char *line)
{
	t_token		*head;
	t_token		*tail;
	int			error;

	head = NULL;
	tail = NULL;
	error = 0;
	head = scan_token(&line, &error);
	tail = head;
	if (!head)
		return (free_tokens(head));
	while (*line)
	{
		skip_whitespace(&line);
		if (!(*line))
			break ;
		tail->next = scan_token(&line, &error);
		tail = tail->next;
		if (!tail)
			return (free_tokens(head));
	}
	if (error == 1)
		return (free_tokens(head));
	return (head);
}
