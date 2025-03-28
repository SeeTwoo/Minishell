/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:07:21 by walter            #+#    #+#             */
/*   Updated: 2025/03/26 14:21:48 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	filtered_strlen(char *s, char c)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (s[++i])
		if (s[i] != c)
			j++;
	return (j);
}

char	*filtered_strdup(char *s, char c)
{
	char	*dest;
	int		i;
	int		j;

	dest = malloc(sizeof(char) * (filtered_strlen(s, c) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			dest[j] = s[i];
			j++;
		}
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

int	main(int ac, char **av)
{
	char	*s;

	if (ac != 2)
		return (1);
	s = filtered_strdup(av[1], '\"');
	if (!s)
		return (1);
	printf("%s\n", s);
	free(s);
	return (0);
}
