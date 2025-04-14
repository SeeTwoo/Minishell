/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:02:00 by walter            #+#    #+#             */
/*   Updated: 2025/04/14 10:31:41 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_lowest_right(t_token **tokens, int index)
{
	int	lowest;
	
	lowest = index
	while (1)
	{
		if (tokens[index]->precedence < tokens[lowest]->precedence)
			lowest = tokens[index]->precedence;
		if (!tokens[index + 1])
			return (lowest);
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
	int	lowest;

	lowest = index;
	while (1)
	{
		if (tokens[index]->precedence < tokens[lowest]->precedence)
			lowest = tokens[index]->precedence;
		if (index = 0)
			return (lowest);
		index--;
	}
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
