/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:33:39 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/13 21:06:57 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_LEXER_H
# define SH_LEXER_H

# include <stdbool.h>
# include "sh_define.h"

/*
** Tokens
*/

typedef enum		e_token_type
{
	NOT_FOUND = 0,
	TOKEN_AND,
	TOKEN_EAT,
	TOKEN_EQUAL,
	TOKEN_DBLAND,
	TOKEN_DBLOR,
	TOKEN_FOR,
	TOKEN_NEG,
	TOKEN_PIPE,
	TOKEN_REDIR,
	TOKEN_SEMICOLON,
	TOKEN_TEXT,
	TOKEN_WHILE
}					t_token_type;

typedef struct		s_regex
{
	const char		*op;
	size_t			len;
	t_token_type	type;
}					t_regex;

typedef struct		s_token
{
	size_t			len;
	t_token_type	type;
	char			*content;
}					t_token;

/*
** Lexer: lexical analyzer
*/

typedef struct		s_lexer
{
	size_t			size;
	size_t			capacity;
	t_token			**tokens;
}					t_lexer;

/*
** Token
**
** create_token()   :  Constructor
** malloc_token()   :  Malloc function
** destroy_token()  :  Destructor
** free_token()     :  Free function
*/

t_token				create_token(char *s, size_t p_len, t_token_type p_type);
t_token				*malloc_token(char *s, size_t p_len, t_token_type p_type);
void				destroy_token(t_token to_destroy);
void				free_token(t_token *to_free);
void				delete_tokens(t_token **tokens, size_t capacity);

/*
** Lexer: lexical analyzer
**
** create_lexer()   :  Constructor
** malloc_lexer()   :  Malloc function
** destroy_lexer()  :  Destructor
** free_lexer()     :  Free function
*/

void				create_lexer(t_lexer *lexer, size_t p_capacity);
t_lexer				*malloc_lexer(size_t p_capacity);
void				destroy_lexer(t_lexer to_destroy);
void				free_lexer(t_lexer *to_free);

/*
** Checks whether the lexer is full
*/

bool				lexer_is_full(t_lexer *lexer);

/*
** Doubles the capacity of the lexer
*/

void				increase_lexer(t_lexer *lexer);

/*
** Adds a token to the lexer
*/

void				add_token_to_lexer(t_lexer *lexer, t_token *new_token);

/*
** Searches if input is a token
*/

t_regex				get_token_type(char *input);

/*
** Fills the lexer from the input string and handles syntax errors
*/

void				fill_lexer(char *input, t_lexer *lexer);

#endif