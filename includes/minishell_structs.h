/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:51:37 by walter            #+#    #+#             */
/*   Updated: 2025/04/01 15:46:36 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

typedef struct s_token	t_token;

struct s_token
{
	char	*lexeme;
	int		type;
	t_token	*next;
};

enum e_tok_types
{
	OR = 0,
	IN = 1,
	HD = 2,
	TRUNC = 3,
	CMD = 4,
	PIPE = 5,
	APPEND = 6,
	END_OF_LINE = 7,
	AND = 8,
	OPEN_PAREN = 9,
	CLOSE_PAREN = 10,
	WRONG_TOKEN = 11
};

#endif
