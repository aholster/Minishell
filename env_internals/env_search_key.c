/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_search_key.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 11:53:10 by aholster       #+#    #+#                */
/*   Updated: 2019/12/13 08:13:19 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"
#include "../libft/libft.h"

t_list	*env_search_key(char const *const restrict key,\
				t_list *env_lst)
{
	t_env_kvp	*cur_kvp;

	while (env_lst != NULL)
	{
		cur_kvp = env_lst->content;
		if (ft_strequ(cur_kvp->key, key) == 1)
		{
			return (env_lst);
		}
		env_lst = env_lst->next;
	}
	return (NULL);
}
