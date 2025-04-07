/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 03:09:48 by walter            #+#    #+#             */
/*   Updated: 2025/04/07 03:44:25 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_parenthesis(t_token **tokens)
{
	int	i;
	int	open;
	int	close;

	open = 0;
	close = 0;
	while (tokens[i])
	{
		if (tokens[i]->type == OPEN_PAREN)
			open++;
		else if (tokens[i]->type == CLOSE_PAREN)
			close++;
		i++;
	}
	if (open != close)
		return (0);
	return (1);
}
