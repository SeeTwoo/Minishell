/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:13:01 by walter            #+#    #+#             */
/*   Updated: 2025/04/14 11:30:03 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_redirect(t_token **tokens, int index)
{
	(void)tokens;
	(void)index;
	return (0);
}

int	redir_init(t_redirect *redir)
{
	redir = malloc(sizeof(t_redirect));
	if (!redir)
		return (0);
	redir->in_type = -1;
	redir->out_type = -1;
	redir->in_str = NULL;
	redir->out_str = NULL;
	return (1);
}

void	redir_filling(t_redirect *redir, t_token **tokens, int index)
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

	redir = NULL;
	if (!has_redirect(tokens, index))
		return (NULL);
	if (!redir_init(redir))
		return (NULL);
	redir_filling(redir, tokens, index);
	return (redir);
}
