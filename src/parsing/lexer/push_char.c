/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:58:00 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/12 23:37:02 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft_str.h"
#include "sh_lexer.h"

/*
** The lexer adds the current character to the stack
**
** stack: A pointer to the stack
** lexer: The lexer
**
** returns: 0 on success
**          -1 on error
*/

int		push_char(t_lexer *lexer, char **tok_stack)
{
	*tok_stack = ft_append_char(*tok_stack, lexer->input + lexer->pos, true);
	if (!(*tok_stack))
		return (FAIL_RET);
	lexer->pos++;
	return (0);
}
