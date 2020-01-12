/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_env.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 10:25:58 by aholster       #+#    #+#                */
/*   Updated: 2020/01/12 02:53:30 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENV_H
# define FT_ENV_H

# include <stddef.h>

typedef struct	s_env_kvp{
	char	*key;
	size_t	klen;
	char	*value;
	size_t	vlen;
}				t_env_kvp;

typedef struct s_list	t_list;

t_env_kvp		*env_search_key(char const *const restrict key,\
					t_list *env_lst);

int				env_add_kvp(char const *const restrict key,\
					char const *const restrict value,\
					t_list **const aenv_lst);

int				set_env(char const *const restrict key,\
					char const *const restrict value,\
					t_list **const aenv_lst);

void			env_del_kvp(void *data, size_t size);

#endif
