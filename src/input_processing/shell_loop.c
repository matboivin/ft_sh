/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:02:51 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/05 18:10:03 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "sh_utils.h"
#include "sh_input_processing.h"

/*
** While the shell is not 'done', processes the user input: a command
**   Prompt the user for and input
**   Parse the command
**   Execute the command
**   Return status
*/

int		shell_loop(t_shctrl *ft_sh)
{
	while (!g_done)
		process_input(ft_sh);
	free_all(ft_sh);
#ifdef DEBUG
	ft_printf(
		"\n----------- DEBUG: STATUS -----------\nexited with: %d\n", g_status);
#endif /* DEBUG */
	return (g_status);
}
