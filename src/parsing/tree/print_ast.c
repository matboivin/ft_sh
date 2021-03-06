/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:54:10 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/03 17:43:41 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_ast.h"

/*
** This function creates a dot graph from a given Abstract Syntax Tree (AST)
** and saves it to a SVG file
*/

void	print_ast(t_ast_node *root)
{
	save_ast_dot(root);
	save_ast_svg();
}
