/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lookup.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:52:29 by walter            #+#    #+#             */
/*   Updated: 2025/03/31 18:53:49 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef char *(*func_ptr)(t_token *, char **, int *);

#ifndef FUNC_ARRAY
# define FUNC_ARRAY (func_ptr[128]){
	separators,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	skip_whitespaces,\
	skip_whitespaces,\
	skip_whitespaces,\
	skip_whitespaces,\
	skip_whitespaces,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	skip_whitespaces,\
	wrong_tok,\
	filtered_dup,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	separators,\
	filtered_dup,\
	parenthesis,\
	parenthesis,\
	filtered_dup,\
	wrong_tok,\
	wrong_tok,\
	filtered_dup,\
	wrong_tok,\
	wrong_tok,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	wrong_tok,\
	wrong_tok,\
	separators,\
	wrong_tok,\
	separators,\
	wrong_tok,\
	wrong_tok,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	filtered_dup,\
	wrong_tok,\
	separators,\
	wrong_tok,\
	wrong_tok,\
	wrong_tok\
}

#endif
