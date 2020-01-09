/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_set.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 11:49:54 by aholster       #+#    #+#                */
/*   Updated: 2019/12/16 11:08:34 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"
#include "../libft/libft.h"

int			set_env(char const *const restrict key,\
				char const *const restrict value,\
				t_list **const aenv_lst)
{
	t_env_kvp	*const kvp = env_search_key(key, *aenv_lst)->content;

	if (kvp != NULL)
	{
		ft_strdel(&(kvp->value));
		kvp->vlen = ft_strlen(value);
		kvp->value = ft_memdup(value, kvp->vlen + 1);
		if (kvp->value == NULL)
		{
			return (-1);
		}
	}
	else
	{
		if (env_add_kvp(key, value, aenv_lst) == -1)
		{
			return (-1);
		}
	}
	return (1);
}
