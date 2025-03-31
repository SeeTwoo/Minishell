/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:06:09 by wbeschon          #+#    #+#             */
/*   Updated: 2025/03/31 19:27:55 by walter           ###   ########.fr       */
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
			dprintf(fd, "\tend_of_line");
		else if (strchr(SEPARATORS, (char)c))
			dprintf(fd, "\tseparators");
		else if ((char)c == '(' || (char)c == ')')
			dprintf(fd, "\tparenthesis");
		else if (strchr(ALNUMS, (char)c))
			dprintf(fd, "\tfiltered_dup");
		else
			dprintf(fd, "\twrong_tok");
		if (c < 127)
			dprintf(fd, ",\\\n");
		else
			dprintf(fd, "\\\n");
		c++;
	}
}

void	write_lookup(int fd)
{
	dprintf(fd, "typedef char *(*func_ptr)(char **, char *);\n\n");
	dprintf(fd, "#ifndef FUNC_ARRAY\n");
	dprintf(fd, "# define FUNC_ARRAY (func_ptr[128]){\n");
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
