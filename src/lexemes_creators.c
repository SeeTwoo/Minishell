/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexemes_creators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 00:20:10 by walter            #+#    #+#             */
/*   Updated: 2025/03/30 20:02:14 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*separators(char **line, char *c)
{
	size_t	len;
	char	*dest;

	len = 0;
	while (*line == c)
		len++;
	*line += len;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	while (len--)
		dest[len] = c;
	return (dest);
}

char	*parenthesis(char **line, char *c)
{
	char	dest[2];

	dest[0] = c;
	dest[1] = '\0';
	(*line)++;
	return (dest);
}
