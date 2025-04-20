/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:02:00 by walter            #+#    #+#             */
/*   Updated: 2025/04/20 09:17:01 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_lowest_right(t_token **tokens, int index)
{
	int	lowest;
	
	if (!tokens[index + 1])
		return (-1);
	index++;
	lowest = index;
	while (tokens[index])
	{
		if (tokens[index]->precedence < tokens[lowest]->precedence)
			lowest = index;
		index++;
	}
	return (lowest);
}

t_ast_node	*parse_right(t_token **tokens, int index)
{
	index = find_lowest_right(tokens, index);
	if (index == -1)
		return (NULL);
	if (tokens[index]->type == OR || tokens[index]->type == AND)
		return (logic_creator(tokens, index));
	else if (tokens[index]->type == PIPE)
		return (pipe_creator(tokens, index));
	else
		return (cmd_creator(tokens, index));
}

int	find_lowest_left(t_token **tokens, int index)
{
	int	lowest;

	if (index == 0)
		return (-1);
	index--;
	lowest = index;
	while (index >= 0)
	{
		if (tokens[index]->precedence <= tokens[lowest]->precedence)
			lowest = index;
		index--;
	}
	return (lowest);
}

t_ast_node	*parse_left(t_token **tokens, int index)
{
	index = find_lowest_left(tokens, index);
	if (index == -1)
		return (NULL);
	if (tokens[index]->type == OR || tokens[index]->type == AND)
		return (logic_creator(tokens, index));
	else if (tokens[index]->type == PIPE)
		return (pipe_creator(tokens, index));
	else
		return (cmd_creator(tokens, index));
}
