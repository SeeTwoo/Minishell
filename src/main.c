/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 19:06:03 by walter            #+#    #+#             */
/*   Updated: 2025/04/02 18:27:43 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tokens(t_token *tokens)
{
	char	string_types[12][20] = {"or", "in", "hd", "trunc", "word", "pipe", 
	"append", "close paren", "and", "open paren"
	};

	while (tokens)
	{
		if (tokens->lexeme)
			printf("lexeme is: %s\t\t type is: %s\n", tokens->lexeme, string_types[tokens->type]);
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

int	main(void)
{
	t_token	*tokens;
	char	*line;
	char	*current;

	line = readline("\e[35m\e[1mMinishell> \e[0m");
	current = line;
	if (!line)
		return (1);
	tokens = lexer(current);
	if (!tokens)
	{
		free(line);
		return (1);
	}
	print_tokens(tokens);
	free(line);
	free_tokens(tokens);
	return (0);
}
