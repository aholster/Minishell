/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 07:20:13 by aholster       #+#    #+#                */
/*   Updated: 2020/02/05 17:30:05 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <limits.h>
# include <stddef.h>

# ifndef ARG_MAX
#  define ARG_MAX (256 * 1024)
# endif

# define PROMPT "¥注文>"

typedef struct	s_arg_object{
	char		arg_buf[ARG_MAX + 1];
	size_t		tail;
	int			argc;
	char		*argv[(ARG_MAX / 2) + 1];
	char		**envp;
}				t_arg_object;

typedef struct		s_env{
	struct s_list	*env_list;
	int				last_ret;
}					t_env;

void			ft_puterr(const char *const err, ...);

int				shell_loop(t_env *const true_env);

int				retrieve_argument(t_env *const true_env,\
					t_arg_object *const aargs);
int				generate_all_arguments(char const *raw_arg,\
					char const *const arg_end,\
					t_arg_object *const aargs);

int				ft_hunt_exec(t_env *const true_env,\
					t_arg_object *const args);

#endif
