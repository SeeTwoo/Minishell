/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtered_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:15:39 by walter            #+#    #+#             */
/*   Updated: 2025/03/28 00:17:10 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static size_t	filtered_len(char *s, char *quote)
{
	size_t	i;
	size_t	offset;

	i = 0;
	while (*s  && !ft_isspace(*s))
	{
		if (*s == *quote)
		{
			s++;
			offset = ft_strcspn(s, quote);
			s += offset;
			i += offset;
			if (*s == *quote)
				s++;
		}
		else
		{
			i++;
			s++;
		}
	}
	return (i);
}

static void	filtered_cpy(char **s, char *dest, char *quote, size_t *i)
{
	size_t	offset;

	if (**s == *quote)
	{
		*s += 1;
		offset = ft_strcspn(*s, quote);
		ft_memcpy(&dest[*i], *s, offset);
		*s += offset;
		*i += offset;
		if (**s == *quote)
			*s += 1;
	}
	else
	{
		dest[*i] = **s;
		*s += 1;
		*i += 1;
	}
}

char	*filtered_dup(char *s, char *quote)
{
	char	*dest;
	size_t	i;

	dest = malloc(sizeof(char) * (filtered_len(s, quote) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (*s && !ft_isspace(*s))
		filtered_cpy(&s, dest, quote, &i);
	dest[i] = '\0';
	return (dest);
}

/*int	main(int ac, char **av)
{
	char	*s;

	if (ac != 2)
		return (1);
	s = filtered_dup(av[1], "\"");
	if (!s)
		return (1);
	printf("lexeme is: %s\n", s);
	free(s);
	return (0);
}*/
