/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_signal_handlers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:51:19 by mboivin           #+#    #+#             */
/*   Updated: 2021/04/13 12:12:22 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "sh_env.h"
#include "sh_subsystems.h"

/*
** This function registers signal handlers
** SIGINT is handled
** SIGQUIT is ignored
*/

static void	handle_sig_err(void)
{
	ft_clearenv();
	g_status = EXIT_FAILURE;
	perror("signal failed");
	exit(g_status);
}

void		register_signal_handlers(void)
{
	if (signal(SIGINT, handle_fatal_error) == SIG_ERR)
		handle_sig_err();
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		handle_sig_err();
}
