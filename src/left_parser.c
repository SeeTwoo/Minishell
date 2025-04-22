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

int	find_lowest_left(t_token **tok, int i, int lim)
{
	int	lowest;
	int	first;
	int	till_open;

	first = i;
	lowest = i;
	while (i >= 0 && tok[i]->prec > lim)
	{
		if (is_close_paren(tok[i]->type))
		{
			till_open = skip_paren_left(&tok[i - 1]);
			if (i - till_open == 0)
				return (find_lowest_left(tok, i - till_open + 1, lim));
			else
				return (find_lowest_left(tok, i - till_open - 1, lim));
		}
		if (tok[i]->prec <= tok[lowest]->prec)
			lowest = i;
		i++;
	}
	return (lowest);
}

t_ast_node	*parse_left(t_token **tok, int i, int lim)
{
	i = find_lowest_left(tok, i, lim);
	if (is_logic(tok[i]->type))
		return (logic_creator(tok, i));
	else if (is_pipe(tok[i]->type))
		return (pipe_creator(tok, i));
	return (command_creator(tok, i));
}
