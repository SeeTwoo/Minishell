/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 19:06:03 by walter            #+#    #+#             */
/*   Updated: 2025/03/23 19:27:43 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_list(t_list *tokens)
{
	while (tokens)
	{
		write(1, tokens->start, tokens->size);
		printf("\n");
		tokens = tokens->next;
	}
}

void	free_tokens(t_list *tokens)
{
	t_list	*temp;

	while (tokens)
	{
		temp = tokens;
		tokens = tokens->next;
		free(temp);
	}
}

int	main(int ac, char **av)
{
	t_list	*tokens;

	if (ac != 2)
		return (0);
	tokens = lexer(av[1]);
	if (!tokens)
		return (0);
	print_list(tokens);
	return (0);
}
