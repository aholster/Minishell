/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_unsetenv.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 02:10:20 by aholster      #+#    #+#                 */
/*   Updated: 2020/02/28 19:11:45 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#include "../env_internals/ft_env.h"

#include "../minishell.h"

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
		ft_puterr("Usage: unsetenv <key> ...\n");
		return (1);
	}
	else
	{
		index = 1;
		while (index < argc)
		{
			search_and_destroy(argv[index], true_env);
			index++;
		}
		return (0);
	}
}
