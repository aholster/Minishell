/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 08:59:33 by aholster       #+#    #+#                */
/*   Updated: 2020/02/05 17:39:28 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <stdbool.h>

# define BUILTIN_COUNT 6

typedef	int	(*t_builtin)(int, char **, t_env *const);

typedef struct	s_builtin_tbl{
	char		*name;
	t_builtin	func;
}				t_builtin_tbl;

int				builtin_exit(int argc, char **argv, t_env *const true_env);

int				builtin_echo(int argc, char **argv, t_env *const true_env);

int				builtin_env(int argc, char **argv, t_env *const true_env);

int				builtin_setenv(int argc, char **argv, t_env *const true_env);

int				builtin_unsetenv(int argc, char **argv, t_env *const true_env);

int				builtin_cd(int argc, char **argv, t_env *const true_env);

#endif
