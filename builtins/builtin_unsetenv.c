/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_unsetenv.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 02:10:20 by aholster       #+#    #+#                */
/*   Updated: 2020/02/15 23:43:55 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#include "../env_internals/ft_env.h"

#include "../minishell.h"

static int	is_invalidkey(char *iter)
{
	if (!(ft_isdigit(iter[0]) || iter[0] == '='))
	{
		while (*iter && is_envkey_char(*iter))
		{
			iter++;
		}
	}
	return (*iter != '\0');
}

static void	search_and_destroy(const char *const key,\
				t_env *const true_env)
{
	t_list		**aiter;
	t_list		*del_holder;
	t_env_kvp	*cur_kvp;

	aiter = &(true_env->env_list);
	while (*aiter != NULL)
	{
		cur_kvp = (*aiter)->content;
		if (ft_strequ(cur_kvp->key, key) == 1)
		{
			del_holder = *aiter;
			*aiter = (*aiter)->next;
			ft_lstdelone(&del_holder, &env_del_kvp);
			break ;
		}
		aiter = &(*aiter)->next;
	}
}

int			builtin_unsetenv(int argc, char **argv, t_env *const true_env)
{
	int	index;

	if (argc <= 1)
	{
		ft_puterr("minishell: unsetenv: not enough arguments");
		return (1);
	}
	else
	{
		index = 1;
		while (index < argc)
		{
			if (is_invalidkey(argv[index]))
			{
				ft_puterr("minishell: unsetenv: badly formatted key %s\n",
							argv[index]);
				return (1);
			}
			search_and_destroy(argv[index], true_env);
			index++;
		}
		return (0);
	}
}
