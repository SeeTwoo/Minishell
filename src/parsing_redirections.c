/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:13:01 by walter            #+#    #+#             */
/*   Updated: 2025/04/20 12:28:10 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_redirect(t_token **tok, int i)
{
	while (tok[i] && tok[i]->prec == 2)
	{
		if (is_redir(tok[i]->type))
			return (1);
		i++;
	}
	return (0);
}

t_redirect	*redir_init(void)
{
	t_redirect	*redir;

	redir = malloc(sizeof(t_redirect));
	if (!redir)
		return (NULL);
	redir->in_type = -1;
	redir->out_type = -1;
	redir->in_str = NULL;
	redir->out_str = NULL;
	return (redir);
}

void	redir_filling(t_redirect *redir, t_token **tok, int i)
{
	while (tok[i] && tok[i]->prec == 2)
	{
		if (is_in_redir(tok[i]->type))
		{
			redir->in_type = tok[i]->type;
			redir->in_str = ft_strdup(tok[i + 1]->lexeme);
		}
		else if (is_out_redir(tok[i]->type))
		{
			redir->out_type = tok[i]->type;
			redir->out_str = ft_strdup(tok[i + 1]->lexeme);
		}
		i++;
	}
}

t_redirect	*get_redirect(t_token **tok, int i)
{
	t_redirect	*redir;

	if (!has_redirect(tok, i))
		return (NULL);
	redir = redir_init();
	if (!redir)
		return (NULL);
	redir_filling(redir, tok, i);
	return (redir);
}
