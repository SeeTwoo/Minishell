/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:18:22 by walter            #+#    #+#             */
/*   Updated: 2025/03/24 23:17:04 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*scan_token(t_scanner *scanner)
{
	t_token	token;

	scanner->current += ft_strspn(scanner->current, " \t\n");
	if (!(*(scanner->current)))
		return (NULL);
	token.start = scanner->current;
	scanner->current += ft_strcspn(scanner->current, " \t\n");
}

t_token	*lexer(char *line)
{
	t_token		*head;
	t_token		*tail;
	t_scanner	scanner;

	head = NULL;
	tail = NULL;
	scanner.current = line;
	while (scanner.current)
	{
		tail = scan_token(&scanner);
		if (!head)
			head = tail;
	}
	return (head);
}
