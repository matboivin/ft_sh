/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:21 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/01 18:19:43 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_str.h"
#include "sh_lexer.h"

/*
** This function splits the input string into tokens
**
** returns: 0 on success
**          1 if the input is not finished
**          -1 on error
*/

static int	is_quote(int c)
{
	return ((c == STRONG_QUOTE) || (c == WEAK_QUOTE));
}

int			tokenize(t_lexer *lexer)
{
	t_regex	token;
	char	*stack;
	int		ret;

	stack = NULL;
	ret = EXIT_SUCCESS;
	lexer->pos = DEFAULT_VALUE;
	while (lexer->input[lexer->pos] && !ret)
	{
		token = get_token(lexer->input + lexer->pos);
		if (lexer->input[lexer->pos] == COMMENT_START)
			break ;
		if (lexer->input[lexer->pos] == BACKSLASH)
			ret = escape_char(lexer, &stack);
		else if (is_quote(lexer->input[lexer->pos]))
			ret = handle_quotes(lexer);
		else if (token.type)
			handle_token(lexer, token, &stack);
		else
			stack = push_char(lexer, stack);
	}
	if (stack && !ret)
		handle_text(lexer, &stack);
	ft_strdel(&stack);
	if (token.type == TOKEN_PIPE)
		return (lexer->pos == ft_strlen(lexer->input));
	return (ret);
}
