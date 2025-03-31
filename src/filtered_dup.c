/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtered_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:15:39 by walter            #+#    #+#             */
/*   Updated: 2025/03/31 23:59:00 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static size_t	ft_strcspn_c(char const *s, char c)
{
	char	*end;

	end = ft_strchr(s, c);
	if (!end)
		return (ft_strlen(s));
	return (end - s);
}

static size_t	filtered_len(char const *s)
{
	size_t	i;
	size_t	offset;
	char	quote;

	i = 0;
	while (*s  && !ft_isspace(*s))
	{
		if (*s == '\'' || *s == '\"')
		{
			quote = *s;
			s++;
			offset = ft_strcspn_c(s, quote);
			s += offset;
			i += offset;
			if (*s == quote)
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

static void	filtered_cpy(char **s, char *dest, size_t *i, int *err)
{
	size_t	offset;
	char	quote;

	if (**s == '\'' || **s == '\"')
	{
		(*s)++;
		offset = ft_strcspn_c(*s, quote);
		ft_memcpy(&dest[*i], *s, offset);
		*s += offset;
		*i += offset;
		if (**s == quote)
			*s += 1;
		else
		{
			*err = 1;
			ft_error_msg("Unclosed quote", NULL);
		}
	}
	else
	{
		dest[*i] = **s;
		*s += 1;
		*i += 1;
	}
}

char	*filtered_dup(char **line)
{
	char	*dest;
	size_t	i;

	dest = malloc(sizeof(char) * (filtered_len(*line, quote) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (*s && !ft_isspace(*s))
		filtered_cpy(line, dest, &i);
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
