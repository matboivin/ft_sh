/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stream.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:28:11 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/24 17:54:14 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sh_execution.h"

void	redirect_stream(int from, int to)
{
	if ((!is_open_file(from)) || (!is_open_file(to)))
		return ;
	dup2(from, to);
	close(from);
}
