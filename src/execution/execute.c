/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:28:27 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/12 18:13:48 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include "sh_utils.h"
#include "sh_execution.h"

/*
** This function executes all simple commands
** When a simple command other than a builtin is to be executed, it is invoked
** in a child process
*/

void	execute(t_shctrl *ft_sh, t_cmd *cmd)
{
	if (cmd->cmd_count == DEFAULT_VALUE)
		return ;
	if (cmd->cmd_count == 1 && is_builtin(cmd->simple_cmds[cmd->curr_cmd]))
		exec_simple_cmd(cmd->simple_cmds[cmd->curr_cmd]);
	else
		exec_pipe_seq(ft_sh, cmd);
}
