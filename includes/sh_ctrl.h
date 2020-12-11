/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ctrl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:48:54 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/11 17:09:19 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_CTRL_H
# define SH_CTRL_H

# include "sh_define.h"
# include "sh_lexer.h"
# include "sh_parser.h"
# include "sh_command.h"

/*
** Shell controller
**
** lexer: Contains the tokens
** ast: Generated from parsing
** cmds: Command tables
*/

typedef struct	s_shctrl
{
	t_lexer		*lexer;
	t_ast_node	*ast;
	t_cmd		*cmds;
}				t_shctrl;

/*
** create_shell()   :  Constructor
** destroy_shell()  :  Destructor
*/

void			create_shell(t_shctrl *ft_sh);
void			destroy_shell(t_shctrl *ft_sh);

#endif
