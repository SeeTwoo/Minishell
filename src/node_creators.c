/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_creators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:31:36 by walter            #+#    #+#             */
/*   Updated: 2025/04/14 14:31:19 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast_node	*cmd_creator(t_token **tokens, int index)
{
	t_ast_node	*cmd;

	cmd = malloc(sizeof(t_ast_node));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->left = NULL;
	cmd->right = NULL;
	cmd->visited = 0;
	cmd->type = tokens[index]->type;
	cmd->redirect = get_redirect(tokens, index);
	return (cmd);
}

t_ast_node	*pipe_creator(t_token **tokens, int index)
{
	t_ast_node	*pipe;

	pipe = malloc(sizeof(t_ast_node));
	if (!pipe)
		return (NULL);
	pipe->args = NULL;
	pipe->visited = 0;
	pipe->type = PIPE;
	pipe->redirect = NULL;
	pipe->left = parse_left(tokens, index);
	pipe->right = parse_right(tokens, index);
	return (pipe);
}

t_ast_node	*logic_creator(t_token **tokens, int index)
{
	t_ast_node	*logic;

	logic = malloc(sizeof(t_ast_node));
	if (!logic)
		return (NULL);
	logic->args = NULL;
	logic->visited = 0;
	logic->type = tokens[index]->type;
	logic->redirect = NULL;
	logic->left = parse_left(tokens, index);
	logic->right = parse_right(tokens, index);
	return (logic);
}
