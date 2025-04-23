/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:37:30 by wbeschon          #+#    #+#             */
/*   Updated: 2025/04/23 14:47:03 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	end_match(char *wild, char *s)
{
	int	wild_len;
	int	s_len;
	int	i;

	wild_len = ft_strlen(wild) - 1;
	if (wild[wild_len] == '*')
		return (1);
	s_len = ft_strlen(s) - 1;
	i = 0;
	while (wild_len - i >= 0 && s_len -i >= 0 && wild[wild_len -i] != '*')
	{
		if (wild[wild_len -i] != s[s_len - i])
			return (0);
		i++;
	}
	return (1);
}

int	are_matching(char *wild, char *s)
{
	char	*to_find;
	char	*found;

	if (strcmp(wild, "*") == 0)
		return (1);
	if (!end_match(wild, s))
		return (0);
	to_find = strtok(wild, "*");
	while (to_find)
	{
		found = strstr(s, to_find);
		if (!found)
			return (0);
		s = found + strlen(to_find);
		to_find = strtok(NULL, "*");
	}
	return (1);
}

int	wildcard(t_token *head)
{
	struct dirent	*entry;
	DIR				*dir;
	char			*wild_format;
	t_token			*wild_toks;

	
}

int	globbing(t_token *head)
{
	while (head)
	{
		if (is_word(head->type) && ft_strchr(head->lexeme, "*"))
			wildcard(head);
		head = head->next;
	}
}
