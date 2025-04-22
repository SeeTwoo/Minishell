/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:22:10 by wbeschon          #+#    #+#             */
/*   Updated: 2025/04/22 09:24:57 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast_node	*parse_left(t_token **tok, int i, int lim)
{
	i = find_lowest_left(tok, i, lim);
	if (is_logic(tok[i]->type))
		return (logic_creator(tok, i));
	else if (is_pipe(tok[i]->type))
		return (pipe_creator(tok, i));
	return (command_creator(tok, i));
}
