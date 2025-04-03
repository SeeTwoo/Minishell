/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matching.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:45:03 by walter            #+#    #+#             */
/*   Updated: 2025/04/03 14:25:36 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

int	end_match(char *wild, char *s)
{
	int	wild_len;
	int	s_len;
	int	i;

	wild_len = strlen(wild) - 1;
	if (wild[wild_len] == '*')
		return (1);
	s_len = strlen(s) - 1;
	i = 0;
	while (wild_len - i >= 0 && s_len - i >= 0 && wild[wild_len - i] != '*')
	{
		if (wild[wild_len - i] != s[s_len - i])
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

void	simple_globbing(char *wild)
{
	struct dirent	*entry;
	DIR				*dir;
	char			*wild_dup;

	dir = opendir(".");
	if (!dir)
	{
		printf("cannot open dir\n");
		return ;
	}
	while (1)
	{
		entry = readdir(dir);
		if (!entry)
			break ;
		wild_dup = strdup(wild);
		if (!wild_dup)
			break ;
		if (are_matching(wild_dup, entry->d_name))
			printf("%s  ", entry->d_name);
		free(wild_dup);
	}
	printf("\n");
	closedir(dir);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	simple_globbing(av[1]);
	return (0);
}
