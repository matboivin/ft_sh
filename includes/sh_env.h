/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:33:44 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/09 18:21:44 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_ENV_H
# define SH_ENV_H

# include <stdbool.h>
# include "sh_define.h"

/*
** Retrieves the environment from envp
*/

void	init_env(char **envp);

/*
** Searches for the environment variable which name is key
*/

int		find_env(char *key);

/*
** Appends a new definition to the environment
*/

char	**ft_putenv(char *s);

/*
** Adds or replaces a new definition to the environment
*/

int		ft_setenv(char *key, char *new_value, bool replace);

/*
** Removes an entry from the environment
*/

int		ft_unsetenv(char *to_unset);

/*
** Removes all entries from the environment
*/

void	ft_clearenv(void);

/*
** Prints name and value pairs for all environment variables
*/

void	ft_printenv(void);

/*
** Returns a string that is the value of the environment variable key
*/

char	*ft_getenv(char *key);

#endif