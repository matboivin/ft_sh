/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:58:43 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/03 17:47:26 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh_ast.h"

/*
** This function adds a leaf node to the left of the tree
*/

void			append_node_left(t_ast_node **node, t_ast_node *new_node)
{
	t_ast_node	*cursor;

	if (!node || !new_node)
		return ;
	if (*node)
	{
		cursor = *node;
		while (cursor->left)
			cursor = cursor->left;
		cursor->left = new_node;
	}
	else
		*node = new_node;
}

/*
** This function adds a leaf node to the right of the tree
*/

void			append_node_right(t_ast_node **node, t_ast_node *new_node)
{
	t_ast_node	*cursor;

	if (!node || !new_node)
		return ;
	if (*node)
	{
		cursor = *node;
		while (cursor->right)
			cursor = cursor->right;
		cursor->right = new_node;
	}
	else
		*node = new_node;
}

/*
** This function adds childs to the node passed as parameter
*/

void			add_node_childs(
	t_ast_node **node, t_ast_node *p_left, t_ast_node *p_right)
{
	(*node)->left = p_left;
	(*node)->right = p_right;
}
