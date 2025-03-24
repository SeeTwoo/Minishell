/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:51:37 by walter            #+#    #+#             */
/*   Updated: 2025/03/24 20:09:25 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

typedef struct s_token		t_token;
typedef struct s_scanner	t_scanner;

struct s_token
{
	char	*start;
	size_t	size;
	int		type;
}

struct s_scanner
{
	char	*start;
	char	*current;
}

enum
{
	CMD,
	REDIR,
	HD,
	PIPE,
	OPEN_PAR,
	CLOS_PAR,
	AND,
	OR
}
