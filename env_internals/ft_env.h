/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_env.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 10:25:58 by aholster       #+#    #+#                */
/*   Updated: 2020/02/15 18:02:02 by aholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENV_H
# define FT_ENV_H

# include <stddef.h>
# include "../libft/libft.h"

typedef struct	s_env_kvp{
	char	*key;
	size_t	klen;
	char	*value;
	size_t	vlen;
}				t_env_kvp;

t_env_kvp		*env_search_key(char const *const key,\
					struct s_list *env_lst);

int				env_add_kvp(char const *const key,\
					char const *const value,\
					struct s_list **const aenv_lst);

int				set_env(char const *const key,\
					char const *const value,\
					struct s_list **const aenv_lst);

int				is_envkey_char(const char character);

void			env_del_kvp(void *data, size_t size);

#endif
