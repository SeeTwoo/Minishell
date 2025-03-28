/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:18:22 by walter            #+#    #+#             */
/*   Updated: 2025/03/26 14:06:58 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*and(t_token token, char **line)
{
	if (strspn(scanner->current, "&") != 2)
		ft_error_msg(
}

t_token	*redirections(t_token token, char **line)
{
	
}

t_token	*

t_token	*pipe(t_token, char **line)
{

}

t_token	*commands(t_token token, char **line)
{
	char	*lexeme;

	lexeme = no_quotes_dup(*line);
	if (!lexeme)
}

t_token	*scan_token(char **line)
{
	t_token	*token;

	token = malloc(sizeof(token));
	if (!token)
		return (NULL);
	*line += ft_strspn(*line, " \t");
}

t_token	*lexer(char *line)
{
	t_token		*head;
	t_token		*tail;

	head = scan_token(&line);
	tail = head;
	if (!head)
		return (free_tokens(head));
	while (*scanner.current)
	{
		tail->next = scan_token(&line);
		tail = tail->next;
		if (!tail)
			return (free_tokens(head));
	}
	return (head);
}
