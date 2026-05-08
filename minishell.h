/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 01:11:00 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/08 18:06:31 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

// =====
// MACROS
// =====

# define S_TYPE_TOKENS 81

typedef enum e_token_type
{
	WORD = 99,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	APPEND,
	HEREDOC
}				t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}				t_token;

typedef enum e_state
{
	DEFAULT,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
}				t_state;

typedef struct s_lexer
{
	t_state		state;
	char		*input;
	int			i;
	int			start;
}				t_lexer;

// typedef struct s_prompt
// {
// }				t_prompt;

typedef struct s_data
{
	char	**commands;
	char	**full_path;
	char	**env;
}				t_data;

// =====
// FUNCTIONS
// =====

// =====
// LEXER
// =====

t_token	*lexer(char *input);

// tokens

t_token	*new_token(char *value, t_token_type type);
void	add_back_token(t_token **lst, t_token *node_to_add);

// UTILS

char	*ft_strndup(const char *s, int start, int end);

// detect type of character

int		is_operator(char c);
int		is_space(char c);
int		is_quote(char c);

// BUILTIN
// void	pwd(int ac);

#endif
