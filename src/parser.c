/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:02:00 by walter            #+#    #+#             */
/*   Updated: 2025/04/05 00:11:59 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*find_lowest_right(t_token **tokens, int index)
{
	int	lowest;

	lowest = tokens[index]->precedence
	while (tokens[++index])
		if (tokens[index]->precedence < lowest)
			lowest = tokens[index]->precedence;
	return (tokens[index]);
}

t_ast_node	*init_parsing(t_token **tokens)
{
	t_token	*lowest_precedence;

	lowest_precedence = find_lowest_right(tokens, 0);
	if (lowest->prece
}

t_ast_node	*parser(t_token **tokens)
{
	t_ast_node	*head;

	head = init_parsing(tokens);
}
