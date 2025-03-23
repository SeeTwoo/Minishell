/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:18:22 by walter            #+#    #+#             */
/*   Updated: 2025/03/23 19:58:17 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	scan_token(char **line)
{
	
}

t_token	*lexer(char *line)
{
	t_token	*head;
	t_token	*tail;

	head = NULL;
	tail = NULL;
	while (*line)
	{
		s += ft_strchr(line, WHITE_SPACES);
		tail = scan_token(&line);
		if (!tail)
			return (free_tokens);
		if (!head)
			head = tail;
	}
	return (head);
}
