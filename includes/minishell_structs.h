/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:51:37 by walter            #+#    #+#             */
/*   Updated: 2025/04/11 23:04:54 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

typedef struct s_token		t_token;
typedef struct s_redirect	t_redirect;
typedef struct s_ast_node	t_ast_node;
typedef struct s_shobj		t_shobj;

struct s_token
{
	char	*lexeme;
	int		type;
	int		precedence;
	t_token	*next;
};

struct s_ast_node
{
	t_ast_node	*left;
	t_ast_node	*right;
	int			visited;
	int			type;
	char		**args;
	t_redirect	*redirect;
};

struct s_redirect
{
	int		in_type;
	int		out_type;
	char	*in_str;
	char	*out_str;
};

struct s_shobj
{
	t_token		**tokens;
	t_ast_node	*head;
}

enum e_tok_types
{
	OR = 0,
	IN = 1,
	HD = 2,
	TRUNC = 3,
	WORD = 4,
	PIPE = 5,
	APPEND = 6,
	CLOSE_PAREN = 7,
	AND = 8,
	OPEN_PAREN = 9,
};

#endif
