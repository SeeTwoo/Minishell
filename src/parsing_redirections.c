/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:13:01 by walter            #+#    #+#             */
/*   Updated: 2025/04/14 10:35:23 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redir_init(t_redirect **redir)
{
	*redir = malloc(lizeof(t_redirect));
	if (!(*redir))
		return (0);
	(*redir)->in_type = -1;
	(*redir)->out_type = -1;
	(*redir)->in_str = NULL;
	(*redir)->out_str = NULL;
	return (1);
}

int	redir_filling(t_redirect **redir, t_token, int index)
{
	int	i;

	i = index;
	while (i > 0 && (tokens[i - 1]->precedence == 2))
		i--;
	while (tokens[i]->precedence == 2)
	{
		if (tokens[i]->type == IN || tokens[i]->type == HD)
		{
			redir->in_type = tokens[i]->type;
			redir->in_str = ft_strdup(tokens[i + 1]->lexeme);
		}
		else if (tokens[i]->type == APPEND || tokens[i]->type == TRUNC)
		{
			redir->out_type = tokens[i]->type;
			redir->out_str = ft_strdup(tokens[i + 1]->lexeme);
		}
	}
}

t_redirect	*get_redirect(t_token **tokens, int index)
{
	t_redirect	*redir;
	int			i;

	if (!has_redirect(tokens, index))
		return (NULL);
	if (!redir_init(&redir))
		return (NULL);
	redir_filling(&redir, tokens, index);
	return (redir);
}
