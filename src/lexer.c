/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:18:22 by walter            #+#    #+#             */
/*   Updated: 2025/03/31 23:50:08 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_lookup.h"

void	skip_whitespace(char **line)
{
	while (ft_isspace(**line))
		(*line)++;
}

t_token	*scan_token(char **line, int *err)
{
	t_token	*token;

	token = malloc(sizeof(token));
	if (!token)
		return (NULL);
	skip_whitespace(line);
	if (!(token_creators(**line)(token, line, err)))
	{
		free(token)
		return (NULL);
	}
	return (token);
}

t_token	*lexer(char *line)
{
	t_token		*head;
	t_token		*tail;
	int			error;

	head = scan_token(&line, &err);
	tail = head;
	if (!head)
		return (free_tokens(head));
	while (*scanner.current)
	{
		tail->next = scan_token(&line, &err);
		tail = tail->next;
		if (!tail)
			return (free_tokens(head));
	}
	if (error == 1)
		return (free_tokens(head));
	return (head);
}
