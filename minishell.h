/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 07:20:13 by aholster       #+#    #+#                */
/*   Updated: 2019/12/10 15:56:19 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <limits.h>

# ifndef ARG_MAX
#  define ARG_MAX (256 * 1024)
# endif

# define PROMPT "¥注文>"

typedef struct	s_env_kvp{
	char	*key;
	char	*value;
}				t_env_kvp;

#endif
