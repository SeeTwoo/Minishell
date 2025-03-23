/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:51:37 by walter            #+#    #+#             */
/*   Updated: 2025/03/23 17:47:26 by walter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

typedef struct s_list		t_list;
typedef struct s_token		t_token;
typedef struct s_scanner	t_scanner;
typedef struct s_types		t_types

struct s_list
{
	void	*content;
	t_list	*next;
}

struct s_token
{
	char	*start;
	size_t	size;;
}

struct s_scanner
{
	char	*start;
	char	*current;
}
