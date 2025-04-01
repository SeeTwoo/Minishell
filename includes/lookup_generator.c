/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:06:09 by wbeschon          #+#    #+#             */
/*   Updated: 2025/04/01 02:58:36 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#define SEPARATORS "<>|&"
#define ALNUMS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\'\"0123456789-*"

void	write_func_ptrs(int fd)
{
	int	c;

	c = 0;
	while (c <= 127)
	{
		if (c == 0)
			dprintf(fd, "\tend_of_line_token");
		else if (strchr(SEPARATORS, (char)c))
			dprintf(fd, "\tseparators_token");
		else if ((char)c == '(' || (char)c == ')')
			dprintf(fd, "\tparenthesis_token");
		else if (strchr(ALNUMS, (char)c))
			dprintf(fd, "\tcommands_token");
		else
			dprintf(fd, "\twrong_token");
		if (c < 127)
			dprintf(fd, ",\\\n");
		else
			dprintf(fd, "\\\n");
		c++;
	}
}

void	write_lookup(int fd)
{
	dprintf(fd, "typedef t_token *(*func_ptr)(t_token *, char **, int *);\n\n");
	dprintf(fd, "#ifndef TOKEN_FILLERS\n");
	dprintf(fd, "# define TOKEN_FILLERS (func_ptr[128]){\\\n");
	write_func_ptrs(fd);
	dprintf(fd, "}\n\n");
	dprintf(fd, "#endif");
}

int	main(void)
{
	int		fd;

	fd = open("minishell_lookup.h", O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (fd == -1)
		return (0);
	write_lookup(fd);
	close(fd);
}
