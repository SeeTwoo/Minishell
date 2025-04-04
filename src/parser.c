/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:02:00 by walter            #+#    #+#             */
/*   Updated: 2025/04/04 19:55:40 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*get_node(t_token *head, int i)
{
	while (i-- && head)
		head = head->next;
	return (head);
}

t_token	*left_lowest_precedence(t_token *node)
{
	
}

t_ast_node	*parser(t_token *head)
{
	t_ast_node	*head;

	head = init_parsing(t_token *head);
}
