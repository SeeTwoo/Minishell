/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:02:00 by walter            #+#    #+#             */
/*   Updated: 2025/04/05 17:31:18 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast_node	*new_ast_node(int type;)
{
	t_ast_node	*new;

	new = malloc(sizeof(t_ast_node));
	if (!new)
		return (NULL);
	new->left = NULL;
	new->right = NULL;
	new->visited = 0;
	new->type = type;
	new->args = NULL;
	new->redirect = NULL;
	return (new);
}

int	find_lowest_right(t_token **tokens, int index)
{
	int	lowest;

	lowest = tokens[index]->precedence
	while (tokens[++index])
		if (tokens[index]->precedence < lowest)
			lowest = tokens[index]->precedence;
	return (tokens[lowest]);
}

t_ast_node	*init_parsing(t_token **tokens)
{
	int lowest;

	lowest = find_lowest_light(tokens, 0);
	if (lowest->precedence = 2)
		return (cmd_creator(lowest_precedence));
	else
		return (NULL);
}

t_ast_node	*parser(t_token **tokens)
{
	t_ast_node	*head;

	head = init_parsing(tokens);
}
