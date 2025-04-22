/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_creators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:50:36 by wbeschon          #+#    #+#             */
/*   Updated: 2025/04/22 11:33:21 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	args_number(t_token **tok)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (tok[i] && tok[i]->prec == 2)
	{
		if (is_redir(tok[i]->type))
			i += 2;
		else
		{
			i++;
			j++;
		}
	}
	return (j);
}

char	**args_creator(t_token **tok)
{
	char	**args;
	int		i;
	int		j;

	args = malloc(sizeof(char *) * (args_number(tok) + 1));
	if (!args)
		return (NULL);
	i = 0;
	j = 0;
	while (tok[i] && tok[i]->prec == 2)
	{
		if (is_redir(tok[i]->type))
			i += 2;
		else
		{
			args[j] = ft_strdup(tok[i]->lexeme);
			j++;
			i++;
		}
	}
	args[j] = NULL;
	return (args);
}
