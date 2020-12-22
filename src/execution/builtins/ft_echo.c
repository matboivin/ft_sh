/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:55:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/22 14:44:01 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft_str.h"
#include "libft_printf.h"
#include "sh_builtins.h"

/*
** Recoded builtin echo() with option ’-n’
*/

static void	handle_newline_opt(char *arg, bool *newline, int *i)
{
	if (!ft_strcmp(arg, "-n"))
	{
		*newline = false;
		(*i)++;
	}
}

void		ft_echo(int argc, char **argv)
{
	bool	newline;
	int		i;

	i = FIRST_PARAM;
	newline = true;
	if (argc > DEFAULT_ARGC)
		handle_newline_opt(argv[FIRST_PARAM], &newline, &i);
	if (i < argc)
	{
		ft_printf("%s", argv[i++]);
		while (i < argc)
			ft_printf(" %s", argv[i++]);
	}
	if (newline)
		ft_printf("\n");
}