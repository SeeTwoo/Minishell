/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:00:29 by wbeschon          #+#    #+#             */
/*   Updated: 2025/04/14 14:35:57 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_ast(t_ast_node *head)
{
	if (!head)
		return ;
	if (head->type == OR)
		printf("or\n");
	if (head->type == IN)
		printf("in\n");
	if (head->type == HD)
		printf("heredoc\n");
	if (head->type == TRUNC)
		printf("trunc\n");
	if (head->type == WORD)
		printf("cmd\n");
	if (head->type == PIPE)
		printf("pipe\n");
	if (head->type == APPEND)
		printf("append\n");
	if (head->type == AND)
		printf("and\n");
	print_ast(head->right);
	print_ast(head->left);
}
