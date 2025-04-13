/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:02:00 by walter            #+#    #+#             */
/*   Updated: 2025/04/12 10:26:17 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_lowest_right(t_token **tokens, int index)
{
	int	paren;
	int	lowest;
	
	paren = 0;
	lowest = tokens[index]
	while (1)
	{
		if (!tokens[index + 1])
			return (lowest);
		if (tokens[index + 1]->type == CLOSE_PAREN && paren = 0)
			return (lowest);
		if (tokens[index]->precedence < tokens[lowest]->precedence)
			lowest = tokens[index]->precedence;
		if (tokens[index]->type == OPEN_PAREN)
			paren++;
		if (tokens[index]->type == CLOSE_PAREN)
			paren--;
		index++;
	}
}

t_ast_node	*parse_right(t_token **tokens, int i)
{
	i = find_lowest_right(tokens, i);
	if (i == -1)
		return (NULL);
	if (tokens[i]->type == OR || tokens[i]->type == AND)
		return (logic_creator(tokens, i));
	else if (tokens[i]->type == PIPE)
		return (pipe_creator(tokens, i));
	else
		return (cmd_creator(tokens, i));
}

int	find_lowest_left(t_token **tokens, int index)
{
	
}

t_ast_node	*parse_left(t_token **tokens, int index)
{
	i = find_lowest_left(tokens, i);
	if (i == -1)
		return (NULL);
	if (tokens[i]->type == OR || tokens[i]->type == AND)
		return (logic_creator(tokens, i));
	else if (tokens[i]->type == PIPE)
		return (pipe_creator(tokens, i));
	else
		return (cmd_creator(tokens, i));
}

t_ast_node	*parser(t_token **tokens)
{
	t_ast_node	*head;
	int			index;

	index = 0;
	error = 0;
	head = parse_right(tokens, index);
	if (!head)
		return (NULL);
	if (error = 1)
	{
		free_ast(head);
		return (NULL);
	}
	return (head);
}
