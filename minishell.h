/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 01:11:00 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/18 14:45:51 by nbaudoin         ###   ########.fr       */
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
# include <signal.h>

// GLOBAL

extern int	g_status;

// =====
// MACROS
// =====

typedef enum e_token_type
{
	WORD = 99,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	APPEND,
	HEREDOC
}				t_token_type;

typedef struct s_token_info
{
	int				start;
	int				end;
	t_token_type	type;
}				t_token_info;

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
}				t_lexer;

// typedef struct s_prompt
// {
// }				t_prompt;

typedef struct s_redir
{
	int				type;
	char			*file;
	struct s_redir	*next;
}				t_redir;

typedef struct s_command
{
	char				**args;
	t_redir				*redir;
	struct s_command	*next;
}				t_command;

typedef struct s_data
{
	char	**full_path;
	char	**env;
}				t_data;

// =====
// SIGNALS
// =====

void	setup_signals(void);
void	handle_sigint(int sig);

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
int		create_token(t_token **tokens, t_lexer *lexer, t_token_info info);
void	free_token(t_token **tokens);

// Norme / refacto

int		handle_default_state(t_lexer *lexer, char c);
int		handle_quote_state(t_lexer *lexer, char c);
int		handle_quote_unclosed(t_lexer *lexer);
int		read_word_loop(t_lexer *lexer, char c);

// UTILS

char	*ft_strndup(const char *s, int start, int end);

// detect type of character

int		is_operator(char c);
int		is_space(char c);
int		is_quote(char c);
int		is_append(char *input, int start);
int		is_heredoc(char *input, int start);
int		is_word(char c);

// operator

int		create_operator_token(t_lexer *lexer, t_token **tokens);
// BUILTIN
// void	pwd(int ac);

#endif
