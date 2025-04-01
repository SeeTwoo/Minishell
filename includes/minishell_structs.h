/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:51:37 by walter            #+#    #+#             */
/*   Updated: 2025/04/01 02:34:18 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

typedef struct s_token		t_token;

struct s_token
{
	char	*lexeme;
	int		type;
	t_token	*next;
};

enum token_types
{
	CMD,
	IN,
	HD,
	TRUNC,
	APPEND,
	PIPE,
	OPEN_PAR,
	CLOS_PAR,
	AND,
	OR
};

#endif
