/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 19:06:03 by walter            #+#    #+#             */
/*   Updated: 2025/04/01 02:37:14 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tokens(t_token *tokens)
{
	while (tokens)
	{
		printf("lexeme is: %s\n", tokens->lexeme);
		tokens = tokens->next;
	}
}

t_token	*free_tokens(t_token *tokens)
{
	t_token	*temp;

	while (tokens)
	{
		temp = tokens;
		tokens = tokens->next;
		free(temp->lexeme);
		free(temp);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_token	*tokens;

	if (ac != 2)
		return (0);
	tokens = lexer(av[1]);
	if (!tokens)
		return (0);
	print_tokens(tokens);
	return (0);
}
